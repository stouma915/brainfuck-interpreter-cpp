#pragma once

class TestResult {
    public:
        unsigned int success;
        unsigned int failure;

        TestResult(unsigned int _success, unsigned int _failure) {
            success = _success;
            failure = _failure;
        }
};
