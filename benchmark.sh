#!/bin/bash

CPP_VERSION=17

mkdir -p bench_out

g++ -I src benchmark/*.cpp -o bench_out/interpreter_bench -Wall -std=c++$CPP_VERSION && bench_out/interpreter_bench
