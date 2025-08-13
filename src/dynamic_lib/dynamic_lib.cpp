#include "dynamic_lib.h"
#include <iostream>

void DYNLIB_API shared_hello() {
    std::cout << "Hello from dynamic library!\n";
}