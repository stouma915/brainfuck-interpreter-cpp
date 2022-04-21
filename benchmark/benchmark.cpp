#include "benchmark.h"

#include <ascii_converter.cpp>
#include <interpreter.cpp>
#include <memory.cpp>
#include <util.cpp>

#include "util.h"

std::vector<long> benchmark(std::string code, int num_of_exec) {
    std::vector<long> times;

    for (int i = 0; i < num_of_exec; i ++) {
        long start_time = current_epoch_milli();

        evaluate(code, Memory());

        long finish_time = current_epoch_milli();

        times.push_back(finish_time - start_time);
    }

    return times;
}

void show_running_message(std::string weight, int num_of_exec) {
    std::cout << "Running " << weight << " benchmark("
              << num_of_exec
              << " time"
              << (num_of_exec > 1 ? "s" : "")
              << ")..."
              << std::endl;
}

void show_max_min_average(std::vector<long> vec) {
    long max_time = max(vec);
    long min_time = min(vec);
    long average_time = average(vec);

    std::cout << "Max: "
              << max_time
              << "ms, Min: "
              << min_time
              << "ms, Average: "
              << average_time
              << "ms."
              << std::endl;
}
