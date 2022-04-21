#include "memory.h"

#include <iostream>

void Memory::increment() {
    pointer ++;
}

void Memory::decrement() {
    if (pointer >= 1) {
        pointer --;
    }
}

void Memory::increment_value() {
    unsigned int new_value = entries[pointer] + 1;
    if (new_value >= 256) {
        entries[pointer] = 0;
    } else {
        entries[pointer] = new_value;
    }
}

void Memory::decrement_value() {
    unsigned int current = entries[pointer];
    if (current == 0) {
        entries[pointer] = 255;
    } else {
        entries[pointer] = current - 1;
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

bool Memory::has_value() {
    return entries.find(pointer) != entries.end();
}

unsigned int Memory::get_current_value() {
    return entries[pointer];
}
