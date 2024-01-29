// debug.h
#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>
#include <string>

#ifdef NDEBUG
#define DEBUG 0
#else
#define DEBUG 1
#endif

#if DEBUG
#define DEBUG_EXEC(code) do { code } while(0)
#else
#define DEBUG_EXEC(code)
#endif


// #if DEBUG
//  #define DEBUG_EXEC if (1)
// #else
//  #define DEBUG_EXEC if (0)
// #endif


#endif // DEBUG_H
