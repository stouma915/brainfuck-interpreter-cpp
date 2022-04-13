#include "util.h"

bool startsWith(std::string str, std::string prefix) {
    return str.rfind(prefix, 0) == 0;
}