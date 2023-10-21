#include "predicates.h"

bool is_even(int x) {
    return x % 2 == 0;
}

bool is_odd(int x) {
    return x % 2 == 1;
}

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}