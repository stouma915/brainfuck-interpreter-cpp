#!/bin/bash

CPP_VERSION=17

mkdir -p test_out

g++ -I src test/*.cpp -o test_out/interpreter_test -Wall -std=c++$CPP_VERSION -O3 && test_out/interpreter_test
