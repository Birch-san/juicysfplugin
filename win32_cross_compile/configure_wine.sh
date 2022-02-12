#!/usr/bin/env bash
set -eo pipefail
cd wine
CC=clang-14 CXX=clang++-14 ./configure --without-x --without-freetype