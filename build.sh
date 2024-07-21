#!/bin/bash

echo "-------------------------------------"
echo "Building Project..."
echo "-------------------------------------"

conan install . --build=missing && \
cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON /usr/lib/llvm-13 -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 && \
ninja -C build && \
ninja -C build test 

echo "-------------------------------------"
echo "Finished Building Project..."
echo "-------------------------------------"