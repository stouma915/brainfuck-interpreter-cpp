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
                return Spec<bool>::create_spec(
                    "bool is_single_bit_int(string)",
                    "true if str can be int",
                    true
                ).test(is_single_bit_int("32"));
            },
            []() -> bool {
                return Spec<bool>::create_spec(
                    "bool is_single_bit_int(string)",
                    "false if str cannot be int",
                    false
                ).test(is_single_bit_int("aaa"));
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
            },
            []() -> bool {
                return Spec<int>::create_spec(
                    "int search_loop_end(string, int)",
                    "search loop end index and return",
                    5
                ).test(search_loop_end("[[[]]]", 0));
            },
            []() -> bool {
                return Spec<int>::create_spec(
                    "int search_loop_end(string, int)",
                    "-1 if start_index is invalid",
                    -1
                ).test(search_loop_end("[]", 1));
            },
            []() -> bool {
                return Spec<int>::create_spec(
                    "int search_loop_end(string, int)",
                    "-1 if not found",
                    -1
                ).test(search_loop_end("[", 0));
            },
            []() -> bool {
                return Spec<int>::create_spec(
                    "int to_single_bit_int(string)",
                    "convert string to int",
                    32
                ).test(to_single_bit_int("32"));
            }
        }
    );
}
