#!/usr/bin/env bash
set -eo pipefail
exec wget "https://github.com/mstorsjo/llvm-mingw/releases/download/20211002/llvm-mingw-20211002-ucrt-ubuntu-18.04-$(uname -m).tar.xz" -O llvm-mingw.tar.xz