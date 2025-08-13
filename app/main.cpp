#include "static_lib.h"
#include "dynamic_lib.h"
#include <iostream>

int main() {
    static_hello();
    shared_hello();

    // Keep console open in debug mode
#ifdef _DEBUG
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
#endif

    return 0;
}