#include <iostream>
#include <vector>

#include "test.h"

#include "ascii_converter_spec.h"
#include "util_spec.h"

const std::vector<Test> tests = {
    ascii_converter_spec(),
    util_spec()
};

int main() {
    using namespace std;

    int success = 0;
    int failure = 0;

    for (unsigned int i = 0; i < tests.size(); i ++) {
        Test test = tests[i];

        auto [s, f] = test.run();
        success += s;
        failure += f;
    }

    cout << endl
         << success
         << " OK, "
         << failure
         << " Error"
         << (failure > 1 ? "s" : "")
         << "."
         << endl;

    if (failure == 0) {
        cout << "All tests passed." << endl;
    } else {
        cout << "Some tests have failed." << endl;

        return 1;
    }
}
