#!/bin/bash


x=`lsof -Fp -i:3000`
kill -9 ${x##p}>/dev/null

em++ --js-library mylib1.js --js-library mylib2.js js_lib.cpp -o build/jslib.html

cd build/

php -S 0.0.0.0:3000 &

firefox http://0.0.0.0:3000/jslib.html