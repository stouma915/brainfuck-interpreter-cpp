#include <iostream>

#include "memory.h"

void Memory::increment() {
    pointer ++;
}

void Memory::decrement() {
    if (pointer >= 1) {
        pointer --;
    }
}

void Memory::increment_value() {
    int new_value = (has_value() ? entries[pointer] : 0) + 1;
    if (new_value >= 256) {
        entries[pointer] = 0;
    } else {
        entries[pointer] = new_value;
    }
}

void Memory::decrement_value() {
    int new_value = (has_value() ? entries[pointer] : 256) - 1;
    if (new_value <= -1) {
        entries[pointer] = 255;
    } else {
        entries[pointer] = new_value;
    }
}

void Memory::set_value(int new_value) {
    entries[pointer] = 0;

    for (int i = 1; i <= std::abs(new_value); i ++) {
        if (new_value < 0) {
            decrement_value();
        } else if (new_value > 0) {
            increment_value();
        }
    }
}

int Memory::get_current_value() {
    return has_value() ? entries[pointer] : 0;
}

bool Memory::has_value() {
    return entries.find(pointer) != entries.end();
}