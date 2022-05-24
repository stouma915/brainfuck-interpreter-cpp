#include "util.h"

#include <regex>

bool starts_with(std::string str, std::string prefix) {
    return str.rfind(prefix, 0) == 0;
}

bool is_int(std::string str) {
    if (regex_match(str, std::regex("[+-]?[0-9]{1,10}"))) {
        long num = atol(str.c_str());

        if (num >= -2147483648L && num <= 2147483647L) {
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

    int x, y = 0;

    for (unsigned int i = start_index; i < code.length(); i ++) {
        char symbol = code[i];

        if (symbol == '[') {
            x ++;
        } else if (symbol == ']') {
            y ++;
        }

        if (x == y) {
            result = i;
            break;
        }
    }

    return result;
}

int to_int(std::string str) {
    long num = atol(str.c_str());

    return (int) num;
}
