#!/bin/bash

echo "-------------------------------------"
echo "Building Project..."
echo "-------------------------------------"

echo "Running clang-tidy...
" && \
echo "-------------------------------------" && \

clang-tidy -format-style=file -header-filter=.* -p build -checks=-*,clang-analyzer-*,cppcoreguidelines-*,modernize-* main.cpp >build/lint_report.txt && \

echo "-------------------------------------" && \
echo "
Linting has finished and report can be found at '$PWD/build/lint_report.txt'"

echo "-------------------------------------"
echo "Finished Building Project..."
echo "-------------------------------------"