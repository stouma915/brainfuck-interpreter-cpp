#pragma once

#include <iostream>
#include <tuple>
#include <vector>

#include "result.h"

class Test {
    public:
        typedef bool(*Func)();

        std::string name;
        std::vector<Func> spec_vec;

        int success;
        int failure;

        Test(std::string _name, std::vector<Func> _spec_vec) {
            name = _name;
            spec_vec = _spec_vec;

            success = 0;
            failure = 0;
        }

        Result run();

        static Test create_test(std::string _name, std::vector<Func> _spec_vec) {
            return Test(
                _name,
                _spec_vec
            );
        }
};
