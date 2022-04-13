#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <tuple>

#include "memory.h"

std::tuple<std::string, Memory> evaluate(std::string code, Memory memory);

#endif
