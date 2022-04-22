#pragma once

#include <iostream>
#include <tuple>

#include "memory.h"

std::tuple<std::string, Memory> evaluate(std::string code,
                                         Memory memory,
                                         int start_index = 0
);
