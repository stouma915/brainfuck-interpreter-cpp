#include <iostream>
#include <vector>

#include "test.h"

#include "ascii_converter_spec.h"

int main() {
    std::vector<Test> tests = {
        ascii_converter_spec()
    };

    int success = 0;
    int failure = 0;

    for (unsigned int i = 0; i < tests.size(); i ++) {
        Test test = tests[i];

        auto [s, f] = test.run();
        success += s;
        failure += f;
    }

    std::cout << std::endl
              << success
              << " OK, "
              << failure
              << " Error"
              << (failure > 1 ? "s" : "")
              << "."
              << std::endl;

    if (failure == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests have failed." << std::endl;

        return 1;
    }
}
