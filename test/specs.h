#pragma once

#include <iostream>
#include <tuple>

class Specs {
    public:
        typedef bool(*Func)();

        std::string name;
        Func program;

        Specs(std::string _name, Func _program) {
            name = _name;
            program = _program;
        }

        bool run();

        static Specs create_test(std::string _name, Func _program) {
            return Specs(
                _name,
                _program
            );
        }
};
