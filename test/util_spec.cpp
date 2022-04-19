#include <util.cpp>

#include "util_spec.h"

Test util_spec() {
    return Test::create_test(
        "util.cpp",
        {
            []() -> bool {
                return Spec<bool>::create_spec(
                           "bool starts_with(string, string)",
                           "return true if str starts with prefix",
                           true
                       ).test(starts_with("AABBCC", "AA"));
            },
            []() -> bool {
                return Spec<bool>::create_spec(
                           "bool starts_with(string, string)",
                           "return false if str doesn't start with prefix",
                           false
                       ).test(starts_with("AABBCC", "BB"));
            }
        }
    );
}
