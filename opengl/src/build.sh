#!/bin/bash

CC=g++
CPPFLAGS="-I../include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC opengl_dot_demo.cpp $CPPFLAGS $LDFLAGS -o ../../cmake-build-debug/opengl_dot_demo

../../cmake-build-debug/opengl_dot_demo