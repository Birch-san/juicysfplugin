# docker build . -f win32.arm.Dockerfile --tag=llvm-mingw-arm
# docker run -it --rm --name llvm-mingw-arm llvm-mingw-arm
FROM ubuntu:22.04 AS wgetter
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
wget ca-certificates && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*

FROM wgetter AS get_llvm_mingw
RUN wget https://github.com/mstorsjo/llvm-mingw/releases/download/20211002/llvm-mingw-20211002-ucrt-ubuntu-18.04-aarch64.tar.xz

FROM ubuntu:22.04 AS gitter
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
git ca-certificates && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*

FROM gitter AS get_juce
COPY win32_cross_compile/clone_juce.sh clone_juce.sh
RUN ./clone_juce.sh

FROM gitter AS get_fluidsynth
COPY win32_cross_compile/clone_fluidsynth.sh clone_fluidsynth.sh
RUN ./clone_fluidsynth.sh

FROM ubuntu:22.04 AS xwin
RUN apt-get update -qq && \
DEBIAN_FRONTEND=noninteractive apt-get install -qqy --no-install-recommends \
cargo ca-certificates && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
RUN cargo install xwin
ENV PATH="$PATH:/root/.cargo/bin"

FROM xwin AS xwin_x86
RUN xwin --accept-license=yes --arch=x86 splat --output=/xwin

FROM xwin AS xwin_x86_64
RUN xwin --accept-license=yes --arch=x86_64 splat --output=/xwin

FROM ubuntu:22.04 AS toolchain
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
xz-utils cmake build-essential pkg-config && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY --from=get_llvm_mingw llvm-mingw-*.tar.xz llvm-mingw.tar.xz
# here's how to merge it into existing /bin, but that could have unintended clashes
# RUN tar -xvf llvm-mingw.tar.xz --strip-components=1 -k && rm llvm-mingw.tar.xz
RUN mkdir -p /opt/llvm-mingw && tar -xvf llvm-mingw.tar.xz --strip-components=1 -C /opt/llvm-mingw && rm llvm-mingw.tar.xz
ENV PATH="/opt/llvm-mingw/bin:$PATH"
COPY win32_cross_compile/x86_64_toolchain.cmake /x86_64_toolchain.cmake
COPY win32_cross_compile/i686_toolchain.cmake /i686_toolchain.cmake
COPY win32_cross_compile/aarch64_toolchain.cmake /aarch64_toolchain.cmake

FROM ubuntu:22.04 AS make_juce
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
cmake build-essential pkg-config libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libfreetype6-dev && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY --from=get_juce JUCE JUCE
COPY win32_cross_compile/make_juce.sh make_juce.sh
RUN ./make_juce.sh

FROM wgetter AS msys2_deps
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
zstd && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY win32_cross_compile/get_fluidsynth_deps_parallel.sh get_fluidsynth_deps_parallel.sh
RUN ./get_fluidsynth_deps_parallel.sh

FROM --platform=linux/amd64 ubuntu:21.04 AS wine
RUN apt-get update -qq && \
DEBIAN_FRONTEND=noninteractive apt-get install -qqy --no-install-recommends \
wget ca-certificates gpg software-properties-common && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
RUN wget -nc https://dl.winehq.org/wine-builds/winehq.key && \
gpg -o /etc/apt/trusted.gpg.d/winehq.key.gpg --dearmor winehq.key && \
rm winehq.key
RUN dpkg --add-architecture i386
RUN add-apt-repository -y 'deb [arch=i386] https://dl.winehq.org/wine-builds/ubuntu/ hirsute main'
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
winehq-stable && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*

FROM toolchain AS make_fluidsynth_x86
COPY --from=msys2_deps clang32 clang32
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY win32_cross_compile/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh x86
COPY win32_cross_compile/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh x86

FROM toolchain AS make_fluidsynth_x64
COPY --from=msys2_deps clang64 clang64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY win32_cross_compile/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh x64
COPY win32_cross_compile/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh x64

FROM toolchain
COPY --from=xwin_x86_64 /xwin/sdk/include/um/ /xwin/sdk/include/um/
COPY --from=xwin_x86_64 /xwin/sdk/lib/um/x86_64/ /xwin/sdk/lib/um/x86_64/
COPY --from=xwin_x86 /xwin/sdk/lib/um/x86/ /xwin/sdk/lib/um/x86/
COPY --from=make_juce /linux_native/ /linux_native/
COPY --from=msys2_deps /clang32/ /clang32/
COPY --from=msys2_deps /clang64/ /clang64/
COPY --from=make_fluidsynth_x64 /clang64/include/fluidsynth.h /clang64/include/fluidsynth.h
COPY --from=make_fluidsynth_x64 /clang64/include/fluidsynth/ /clang64/include/fluidsynth/
COPY --from=make_fluidsynth_x64 /clang64/lib/pkgconfig/fluidsynth.pc /clang64/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_x64 /clang64/lib/libfluidsynth.a /clang64/lib/libfluidsynth.a
COPY --from=make_fluidsynth_x86 /clang32/include/fluidsynth.h /clang32/include/fluidsynth.h
COPY --from=make_fluidsynth_x86 /clang32/include/fluidsynth/ /clang32/include/fluidsynth/
COPY --from=make_fluidsynth_x86 /clang32/lib/pkgconfig/fluidsynth.pc /clang32/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_x86 /clang32/lib/libfluidsynth.a /clang32/lib/libfluidsynth.a