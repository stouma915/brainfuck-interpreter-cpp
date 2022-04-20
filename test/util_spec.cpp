#include <util.cpp>

#include "util_spec.h"

Test util_spec() {
    return Test::create_test(
        "util.cpp",
        {
            []() -> bool {
                return Spec<bool>::create_spec(
                           "bool starts_with(string, string)",
                           "true if str starts with prefix",
                           true
                       ).test(starts_with("AABBCC", "AA"));
            },
            []() -> bool {
                return Spec<bool>::create_spec(
                           "bool starts_with(string, string)",
                           "false if str doesn't start with prefix",
                           false
                       ).test(starts_with("AABBCC", "BB"));
            },
            []() -> bool {
                return Spec<int>::create_spec(
                           "int search_loop_end(string, int)",
                           "search loop end index and return",
                           1
                       ).test(search_loop_end("[]", 0));
            },
            []() -> bool {
                return Spec<int>::create_spec(
                           "int search_loop_end(string, int)",
                           "search loop end index and return",
                           20
                       ).test(search_loop_end("++++++[>++++++++++<-]>+++++.", 6));
            }
        }
    );
}
