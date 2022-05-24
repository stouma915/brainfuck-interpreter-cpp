#!/bin/bash

CPP_VERSION=17

mkdir -p out

g++ -I src\
    benchmark/*.cpp\
    -o out/interpreter_bench\
    -Wall\
    -std=c++$CPP_VERSION\
    -O3\
    && out/interpreter_bench
