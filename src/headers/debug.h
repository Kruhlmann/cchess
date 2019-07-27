#define DEBUG
#ifndef DEBUG
#define ASSERT(n)
#else
#include "stdio.h"
#define ASSERT(n) \
if (!(n)) { \
    printf("%s - Failed", #n); \
    printf("\n\t* %s:%d\n", __FILE__, __LINE__); \
    exit(1); \
}
#endif