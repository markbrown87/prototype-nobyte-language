#!/bin/bash

echo "-------------------------------------"
echo "Checking Leaks on Project..."
echo "-------------------------------------"

valgrind --leak-check=full --show-leak-kinds=all -s --log-file=build/valgrind_report.txt ./build/bin/NoByte

echo "-------------------------------------"
echo "Finished Checking Leaks on Project..."
echo "-------------------------------------"