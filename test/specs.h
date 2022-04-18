#pragma once

#include <iostream>
#include <tuple>

class Specs {
    public:
        template<typename Func>

        std::string name;
        Func program;

        int success;
        int failure;

        Specs(std::string _name, Func _program) {
            name = _name;
            program = _program;

            success = 0;
            failure = 0;
        }

        std::tuple<int, int> run();
};
