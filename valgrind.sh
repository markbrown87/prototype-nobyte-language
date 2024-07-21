#!/bin/bash

echo "-------------------------------------"
echo "Checking Leaks on Project..."
echo "-------------------------------------"

valgrind --leak-check=full --show-leak-kinds=all -s --log-file=build/valgrind_report.txt ./build/bin/SHL

echo "-------------------------------------"
echo "Finsihed Checking Leaks on Project..."
echo "-------------------------------------"