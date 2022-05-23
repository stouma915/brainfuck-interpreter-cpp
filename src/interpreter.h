#pragma once

#include <iostream>

#include "memory.h"
#include "result.h"

Result evaluate(std::string code, Memory memory, int start_index);
