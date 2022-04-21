#pragma once

#include <iostream>
#include <vector>

std::vector<long> benchmark(std::string code, int num_of_exec);

void show_running_message(std::string weight, int num_of_exec);
void show_max_min_average(std::vector<long> vec);
