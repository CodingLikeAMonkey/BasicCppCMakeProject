#pragma once
#include <iostream>

namespace math_utils {
    template<typename T>
    T add(T a, T b) {
        return a + b;
    }

    inline void print_result(int result) {
        std::cout << "Result: " << result << "\n";
    }
}