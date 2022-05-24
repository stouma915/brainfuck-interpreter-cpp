#include <iostream>
#include <vector>

#include "test.h"

#include "interpreter_spec.h"
#include "util_spec.h"

const std::vector<Test> tests = {
    interpreter_spec(),
    util_spec()
};

int main() {
    using namespace std;

    int success = 0;
    int failure = 0;

    for (unsigned int i = 0; i < tests.size(); i ++) {
        Result result = tests[i].run();

        success += result.success;
        failure += result.failure;
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
