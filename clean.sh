#!/bin/bash

echo "-------------------------------------"
echo "Cleaning Project..."
echo "-------------------------------------"

if [ -d build ]; then
    echo "Removing build folder."
    rm -rf build
fi

if [ -f CMakeUserPresets.json ]; then
    echo "Removing 'CMakeUserPresets.json' file."
    rm -f CMakeUserPresets.json
fi

if [ -d .cache ]; then
    echo "Removing '.cache' folder."
    rm -rf .cache
fi

echo "-------------------------------------"
echo "Finished Cleaning Project..."
echo "-------------------------------------"