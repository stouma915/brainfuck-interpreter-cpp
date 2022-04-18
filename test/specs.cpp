#include "specs.h"

bool Specs::run() {
    std::cout << "Start testing '" << name << "'." << std::endl;

    return program();
}
