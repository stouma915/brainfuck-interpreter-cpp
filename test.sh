#!/bin/bash

CPP_VERSION=17

mkdir -p out

g++ -I src test/*.cpp -o out/interpreter_test -Wall -std=c++$CPP_VERSION -O3 && out/interpreter_test
