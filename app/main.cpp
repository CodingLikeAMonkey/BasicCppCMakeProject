#include "static_lib.h"
#include "dynamic_lib.h"
#include "header_only/math_utils.h"  // Include header-only library
#include <iostream>

int main() {
    static_hello();
    shared_hello();

    // Use header-only library
    int sum = math_utils::add(5, 7);
    math_utils::print_result(sum);

    // Keep console open in debug mode
#ifdef _DEBUG
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
#endif

    return 0;
}