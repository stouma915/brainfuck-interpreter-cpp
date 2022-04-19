#pragma once

#include <iostream>
#include <tuple>
#include <vector>

class Specs {
    public:
        typedef bool(*Func)();

        std::string name;
        std::vector<Func> spec_vec;

        Specs(std::string _name, std::vector<Func> _spec_vec) {
            name = _name;
            spec_vec = _spec_vec;
        }

        bool run();

        static Specs create_test(std::string _name, std::vector<Func> _spec_vec) {
            return Specs(
                _name,
                _spec_vec
            );
        }
};
