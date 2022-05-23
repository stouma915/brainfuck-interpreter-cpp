#pragma once

#include <iostream>

#include "memory.h"

class Result {
    public:
        std::string output;
        Memory memory;

        Result(std::string _output, Memory _memory) {
            output = _output;
            memory = _memory;
        }

        std::string get_output() {
            return output;
        }

        Memory get_memory() {
            return memory;
        }

};
