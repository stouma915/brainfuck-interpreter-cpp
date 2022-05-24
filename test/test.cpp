#include "test.h"

Result Test::run() {
    std::cout << "Start testing '" << name << "'." << std::endl;

    for (unsigned int i = 0; i < spec_vec.size(); i ++) {
        if (spec_vec[i]()) {
            success ++;
        } else {
            failure ++;
        }
    }

    return Result(success, failure);
}
