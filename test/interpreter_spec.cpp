#include "interpreter_spec.h"

#include <iostream>

#include <interpreter.cpp>
#include <memory.cpp>

#include "spec.h"

Test interpreter_spec() {
    using namespace std;

    return Test::create_test(
        "interpreter.cpp",
        {
            []() -> bool {
                return Spec<string>::create_spec(
                    "Result evaluate(string, Memory, unsigned int)",
                    "evaluate Brainf**k code",
                    "A"
                ).test(evaluate("----[---->+<]>++.", Memory(), 0).output);
            },
            []() -> bool {
                return Spec<string>::create_spec(
                    "Result evaluate(string, Memory, unsigned int)",
                    "evaluate Brainf**k code",
                    "ABCD"
                ).test(evaluate("----[---->+<]>++.+.+.+.", Memory(), 0).output);
            },
            []() -> bool {
                return Spec<string>::create_spec(
                    "Result evaluate(string, Memory, unsigned int)",
                    "evaluate Brainf**k code",
                    "!@#$"
                ).test(evaluate("++++[->++++++++<]>+.-[->++<]>.[-->+<]>+++.+.", Memory(), 0).output);
            }
        }
    );
}
