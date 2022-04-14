#include "util.h"

bool starts_with(std::string str, std::string prefix) {
    return str.rfind(prefix, 0) == 0;
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
