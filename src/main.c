// main.c

#include "stdio.h"
#include "main.h"

int main() {
    init();

    short index = 0;
    for (index = 0; index < BRD_TILE_CNT; index++) {
        if (index % 10 == 0) {
            printf("\n");
        }
        printf("%5d", sq_120_to_sq_64[index]);
    }

    printf("\n");
    printf("\n");

    for (index = 0; index < 64; index++) {
        if (index % 8 == 0) {
            printf("\n");
        }
        printf("%5d", sq_64_to_sq_120[index]);
    }
    
    printf("\n");


    return 0;
}