#pragma once

#include <unordered_map>

class Memory {
    public:
        unsigned int pointer;
        std::unordered_map<unsigned int, unsigned char> entries;

        Memory() {
            pointer = 0;
            entries = {};
        }

        void increment();
        void decrement();
        void increment_value();
        void decrement_value();
        void set_value(int new_value);
        unsigned char get_current_value();
};
