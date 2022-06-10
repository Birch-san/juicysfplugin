# the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR i386)

set(triple aarch64-linux-gnu)
set(CMAKE_C_LIBRARY_ARCHITECTURE ${triple})
set(CMAKE_CXX_LIBRARY_ARCHITECTURE ${triple})

set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER_TARGET ${triple})

# which compilers to use for C and C++
set(CMAKE_C_COMPILER   /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# where is the target environment located
# https://cmake.org/cmake/help/latest/command/find_library.html
set(CMAKE_FIND_ROOT_PATH /usr)
set(CMAKE_INSTALL_PREFIX /usr)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)