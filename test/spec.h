#pragma once

#include <iostream>

template <typename A>
class Spec {
    public:
        std::string name
};

Spec create_spec(std::string name);
