// rand.c

#include "headers/commons.h"
#include "stdlib.h"

u64 rand_u64 () {
    return (u64) rand()
        | (u64) rand() << 15
        | (u64) rand() << 30
        | (u64) rand() << 4
        | ((u64) rand() & 0xf) << 60;
}