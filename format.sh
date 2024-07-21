#!/bin/bash


echo "-------------------------------------"
echo "Formatting Project..."
echo "-------------------------------------"

find . -regex '.*\.\(cpp\|hpp\|cc\|cxx\)' -exec clang-format -style=file -i {} \;

echo "-------------------------------------"
echo "Finished Formatting Project..."
echo "-------------------------------------"