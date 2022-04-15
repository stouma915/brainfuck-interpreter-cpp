#include <regex>

#include "util.h"

bool starts_with(std::string str, std::string prefix) {
    return str.rfind(prefix, 0) == 0;
}

bool is_single_bit_int(std::string str) {
    if (regex_match(str, std::regex("[+-]?[0-9]{1,3}"))) {
        long num = atol(str.c_str());

        if (num >= -128 && num <= 127) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int search_loop_end(std::string code, int start_index) {
    if (code[start_index] != '[') {
        return -1;
    }

    int result = -1;

    std::string search_target = code.substr(start_index, code.length() - start_index);

    int a = 0;
    int b = 0;

    for (unsigned int i = 0; i < search_target.length(); i ++) {
        int index = i;
        char symbol = search_target[index];

        if (symbol == '[') {
            a ++;
        } else if (symbol == ']') {
            b ++;
        }

        if (a == b) {
            result = start_index + index;
            break;
        }
    }

    return result;
}

int to_single_bit_int(std::string str) {
    long num = atol(str.c_str());

    return (int) num;
}
