#include <iostream>

#include <interpreter.cpp>
#include <memory.cpp>

#include "interpreter_spec.h"

Test interpreter_spec() {
    return Test::create_test(
        "interpreter.cpp",
        {
            []() -> bool {
                return Spec<std::string>::create_spec(
                    "tuple<string, Memory> evaluate(string, Memory)",
                    "evaluate Brainf**k code",
                    "A"
                ).test(std::get<0>(evaluate("----[---->+<]>++.", Memory())));
            },
            []() -> bool {
                return Spec<std::string>::create_spec(
                    "tuple<string, Memory> evaluate(string, Memory)",
                    "evaluate Brainf**k code",
                    "ABCD"
                ).test(std::get<0>(evaluate("----[---->+<]>++.+.+.+.", Memory())));
            },
            []() -> bool {
                return Spec<std::string>::create_spec(
                    "tuple<string, Memory> evaluate(string, Memory)",
                    "evaluate Brainf**k code",
                    "!@#$"
                ).test(std::get<0>(evaluate("++++[->++++++++<]>+.-[->++<]>.[-->+<]>+++.+.", Memory())));
            }
        }
    );
}
