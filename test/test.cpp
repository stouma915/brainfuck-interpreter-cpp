#include "test.h"

std::tuple<int, int> Test::run() {
    std::cout << "Start testing '" << name << "'." << std::endl;

    for (int i = 0; i < spec_vec.size(); i ++) {
        if (spec_vec[i]()) {
            success ++;
        } else {
            failure ++;
        }
    }

    return { success, failure };
}
