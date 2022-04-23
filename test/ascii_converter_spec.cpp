#include "ascii_converter_spec.h"

#include <ascii_converter.cpp>

Test ascii_converter_spec() {
    return Test::create_test(
        "ascii_converter.cpp",
        {
            []() -> bool {
                return Spec<char>::create_spec(
                    "char convert_ascii(unsigned char)",
                    "convert 65 to A",
                    'A'
                ).test(convert_ascii(65));
            },
            []() -> bool {
                return Spec<char>::create_spec(
                    "char convert_ascii(unsigned char)",
                    "convert 66 to B",
                    'B'
                ).test(convert_ascii(66));
            },
            []() -> bool {
                return Spec<char>::create_spec(
                    "char convert_ascii(unsigned char)",
                    "convert 67 to C",
                    'C'
                ).test(convert_ascii(67));
            },
            []() -> bool {
                return Spec<char>::create_spec(
                    "char convert_ascii(unsigned char)",
                    "convert 97 to a",
                    'a'
                ).test(convert_ascii(97));
            },
            []() -> bool {
                return Spec<char>::create_spec(
                    "char convert_ascii(unsigned char)",
                    "convert 98 to b",
                    'b'
                ).test(convert_ascii(98));
            },
            []() -> bool {
                return Spec<char>::create_spec(
                    "char convert_ascii(unsigned char)",
                    "convert 99 to c",
                    'c'
                ).test(convert_ascii(99));
            }
        }
    );
}
