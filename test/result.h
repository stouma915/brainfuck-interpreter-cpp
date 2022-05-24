#pragma once

class Result {
    public:
        unsigned int success;
        unsigned int failure;

        Result(unsigned int _success, unsigned int _failure) {
            success = _success;
            failure = _failure;
        }
};
