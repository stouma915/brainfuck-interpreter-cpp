#include "test.h"

std::tuple<int, int> Test::run() {
    std::cout << "Start testing '" << name << "'." << std::endl;

    return { success, failure };
}
