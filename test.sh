#!/bin/bash

CPP_VERSION=17

mkdir -p test_out

g++ test/*.cpp -o test_out/interpreter_test -Wall -std=c++$CPP_VERSION && test_out/interpreter_test
