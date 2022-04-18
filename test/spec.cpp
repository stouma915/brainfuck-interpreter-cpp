#include "spec.h"

Spec create_spec(std::string name, A expect) {
    return new Spec(
        name,
        expect
    );
}
