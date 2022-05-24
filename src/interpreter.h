#pragma once

#include <iostream>

#include "memory.h"
#include "result.h"

Result evaluate(std::string code, Memory memory, unsigned int start_index);
