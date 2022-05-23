#include "interpreter_spec.h"

#include <iostream>

#include <interpreter.cpp>
#include <memory.cpp>

Test interpreter_spec() {
    return Test::create_test(
        "interpreter.cpp",
        {
            []() -> bool {
                return Spec<std::string>::create_spec(
                    "Result evaluate(string, Memory, int)",
                    "evaluate Brainf**k code",
                    "A"
                ).test(evaluate("----[---->+<]>++.", Memory(), 0).get_output());
            },
            []() -> bool {
                return Spec<std::string>::create_spec(
                    "Result evaluate(string, Memory, int)",
                    "evaluate Brainf**k code",
                    "ABCD"
                ).test(evaluate("----[---->+<]>++.+.+.+.", Memory(), 0).get_output());
            },
            []() -> bool {
                return Spec<std::string>::create_spec(
                    "Result evaluate(string, Memory, int)",
                    "evaluate Brainf**k code",
                    "!@#$"
                ).test(evaluate("++++[->++++++++<]>+.-[->++<]>.[-->+<]>+++.+.", Memory(), 0).get_output());
            }
        }
    );
}
