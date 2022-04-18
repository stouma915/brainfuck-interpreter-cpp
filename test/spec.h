#pragma once

#include <iostream>

template <typename A>
class Spec {
    public:
        std::string name;
        A expect;

        Spec(std::string _name, A _expect) {
            name = _name;
            expect = _expect;
        }
};

Spec create_spec(std::string name, A expect);
