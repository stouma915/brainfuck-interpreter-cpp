#ifndef UTIL_H
#define UTIL_H

#include <iostream>

bool starts_with(std::string str, std::string prefix);
bool is_single_bit_int(std::string str);
int  search_loop_end(std::string code, int start_index);

#endif
