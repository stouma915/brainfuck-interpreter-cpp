#include <iostream>
#include <vector>

#include "bench_codes.h"
#include "benchmark.h"
#include "util.h"

#define NUM_OF_EXEC_LIGHTWEIGHT 100
#define NUM_OF_EXEC_MEDIUM_WEIGHT 50
#define NUM_OF_EXEC_HEAVYWEIGHT 25

int main() {
    using namespace std;

    show_start_message("lightweight", NUM_OF_EXEC_LIGHTWEIGHT);

    vector<long> lightweight_times = benchmark(
        lightweight_code(),
        NUM_OF_EXEC_LIGHTWEIGHT
    );

    show_result(lightweight_times);

    cout << endl;

    show_start_message("medium weight", NUM_OF_EXEC_MEDIUM_WEIGHT);

    vector<long> medium_weight_times = benchmark(
        medium_weight_code(),
        NUM_OF_EXEC_MEDIUM_WEIGHT
    );

    show_result(medium_weight_times);

    cout << endl;

    show_start_message("heavyweight", NUM_OF_EXEC_HEAVYWEIGHT);

    vector<long> heavyweight_times = benchmark(
        heavyweight_code(),
        NUM_OF_EXEC_HEAVYWEIGHT
    );

    show_result(heavyweight_times);

    cout << endl;

    long elapsed = sum(lightweight_times) +
                   sum(medium_weight_times) +
                   sum(heavyweight_times);

    cout << "Elapsed: " << elapsed << "ms." << endl;
    cout << "Benchmark finished." << endl;
}
