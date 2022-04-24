#pragma once

#include <unordered_map>

class Memory {
    public:
        unsigned int pointer;
        std::unordered_map<unsigned int, unsigned char> entries;

        Memory(int _pointer = 0,
               std::unordered_map<unsigned int, unsigned char> _entries = {}
        ) {
            pointer = _pointer;
            entries = _entries;
        }

        void increment();
        void decrement();
        void increment_value();
        void decrement_value();
        void set_value(int new_value);
        unsigned char get_current_value();
};
