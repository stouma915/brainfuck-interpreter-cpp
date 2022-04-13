#include "util.h"

bool startsWith(std::string str, std::string prefix) {
    return str.rfind(prefix, 0) == 0;
}

int search_loop_end(std::string before, std::string after) {
    int result = -1;

    int count_of_bracket = 0;
    int count_of_closing_bracket = 0;

    for (int i = 0; i < after.length(); i ++) {
        int index = i;
        char symbol = after[i];

        if (symbol == '[') {
            count_of_bracket ++;
        } else if (symbol == ']') {
            count_of_closing_bracket ++;
        }

        if (count_of_bracket == count_of_closing_bracket) {
            result = index + before.length();
            break;
        }
    }

    return result;
}
