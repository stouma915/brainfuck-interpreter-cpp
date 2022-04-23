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
    entries[pointer] ++;
}

void Memory::decrement_value() {
    entries[pointer] --;
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

unsigned char Memory::get_current_value() {
    return entries[pointer];
}
