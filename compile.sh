#!/bin/bash

CPP_VERSION=17

mkdir -p out

g++ src/*.cpp -o out/brainfuck-interpreter -std=c++$CPP_VERSION