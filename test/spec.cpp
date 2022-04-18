#include "spec.h"

template <typename A>

Spec<A> create_spec(std::string name, A expect) {
    return new Spec(
        name,
        expect
    );
}
