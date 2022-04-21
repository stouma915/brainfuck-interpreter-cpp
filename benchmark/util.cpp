#include <algorithm>
#include <chrono>
#include <iostream>

#include "util.h"

long current_epoch_milli() {
    using namespace std::chrono;

    milliseconds milli = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );

    return milli.count();
}

long max(std::vector<long> vec) {
    std::sort(vec.begin(), vec.end());

    return vec[vec.size() - 1];
}

long min(std::vector<long> vec) {
    std::sort(vec.begin(), vec.end());

    return vec[0];
}

long average(std::vector<long> vec) {
    long sum = 0;

    for (unsigned int i = 0; i < vec.size(); i ++) {
        sum += vec[i];
    }

    return sum / vec.size();
}
