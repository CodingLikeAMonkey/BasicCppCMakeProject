#pragma once

#ifdef _WIN32
    #ifdef DYNAMIC_LIB_EXPORT
        #define DYNLIB_API __declspec(dllexport)
    #else
        #define DYNLIB_API __declspec(dllimport)
    #endif
#else
    #define DYNLIB_API
#endif

void DYNLIB_API shared_hello();