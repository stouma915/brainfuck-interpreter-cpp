#include "util.h"

#include <algorithm>
#include <chrono>
#include <iostream>

long current_epoch_milli() {
    using namespace std::chrono;

    milliseconds milli = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );

    return milli.count();
}

long sum(std::vector<long> vec) {
    long s = 0;

    for (unsigned int i = 0; i < vec.size(); i ++) {
        s += vec[i];
    }

    return s;
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
    return sum(vec) / vec.size();
}
