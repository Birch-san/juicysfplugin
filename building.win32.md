```bash
DOCKER_BUILDKIT=0 docker build . -f win32.Dockerfile --tag=llvm-mingw
# ues this if you need to investigate any problems:
# docker run -it --rm --name llvm-mingw llvm-mingw
./distribute/bundle_win32.sh 3.0.1
```