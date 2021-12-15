#!/bin/bash

rm a.out>>/dev/null

clang++-12 -v --std=c++17 -g  -Wall -Werror $1
echo ""
echo "Running......"
echo ""

./a.out
