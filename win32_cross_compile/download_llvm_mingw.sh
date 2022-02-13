#!/usr/bin/env bash
set -eo pipefail
exec wget "https://github.com/mstorsjo/llvm-mingw/releases/download/$LLVM_MINGW_VER/llvm-mingw-$LLVM_MINGW_VER-ucrt-ubuntu-18.04-$(uname -m).tar.xz" -O llvm-mingw.tar.xz