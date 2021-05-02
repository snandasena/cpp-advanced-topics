#!/bin/bash

emcc cpp/hello.cpp -s WASM=1 -o www/hello.html

python3 -m http.server 3000