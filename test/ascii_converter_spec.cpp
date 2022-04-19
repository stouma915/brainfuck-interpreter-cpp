#include <ascii_converter.cpp>

#include "ascii_converter_spec.h"

Test ascii_converter_spec() {
    return Test::create_test(
        "ascii_converter.cpp",
        {
            []() -> bool {
                return Spec<char>::create_spec(
                           "convert_ascii",
                           "convert int to char",
                           'A'
                       ).test(convert_ascii(65));
            }
        }
    );
}
