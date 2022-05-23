#pragma once

#include <iostream>
#include <vector>

std::vector<long> benchmark(std::string code, int num_of_exec);
void show_start_message(std::string weight, int num_of_exec);
void show_result(std::vector<long> vec);
