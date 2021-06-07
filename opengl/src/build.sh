#!/bin/bash

CC=g++
CPPFLAGS="-I../include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC $1 $CPPFLAGS $LDFLAGS -o ../../cmake-build-debug/opengldemo

../../cmake-build-debug/opengldemo