#include <chrono>

#include "util.h"

long current_epoch_milli() {
    using namespace std::chrono;

    milliseconds milli = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );

    return milli.count();
}