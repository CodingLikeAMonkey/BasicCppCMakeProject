#pragma once

#ifdef DYNAMIC_LIB_EXPORT
    #define DYNLIB_API __declspec(dllexport)
#else
    #define DYNLIB_API __declspec(dllimport)
#endif

void DYNLIB_API shared_hello();