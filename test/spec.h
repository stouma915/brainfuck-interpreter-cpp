#pragma once

#include <iostream>

template <typename A>
class Spec {
    public:
        std::string name;
        std::string should;
        A expect;

        Spec(std::string _name, std::string _should, A _expect) {
            name = _name;
            should = _should;
            expect = _expect;
        }

        bool test(A x) {
            using namespace std;

            cout << "--- " << name << " should " << should << " ---" << endl;

            if (x == expect) {
                cout << "OK." << endl;

                return true;
            } else {
                cout << "Expected '" << expect << "', but the result was '" << x << "'." << endl;
                cout << "Fail." << endl;

                return false;
            }
        }

        static Spec<A> create_spec(std::string _name, std::string _should, A _expect) {
            return Spec<A>(
                _name,
                _should,
                _expect
            );
        }
};
