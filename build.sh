#!/bin/bash

 export CC=/usr/bin/clang 
 export CXX=/usr/bin/clang++ 
 
 conan profile detect --force
 conan install . --output-folder=conan --build=missing

 cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=conan/build/Release/generators/conan_toolchain.cmake
 
 cmake --build build