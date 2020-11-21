#!/bin/bash 
rm -rf app>>/dev/null
g++ -std=c++17 -O2 -Wall $1 -o app

echo "app is running ...."
./app
