// init.c

#include "main.h"

int sq_120_to_sq_64[BRD_TILE_CNT];
int sq_64_to_sq_120[64];

void init_sq_120_to_64() {
    short i = 0;
    short sq_120 = A1;
    short sq_64 = 0;
    byte file = FILE_A;
    byte rank = RANK_1;

    for (i = 0; i < BRD_TILE_CNT; i++) {
        sq_120_to_sq_64[i] = 65;
    }

    for (i = 0; i < 64; i++) {
        sq_64_to_sq_120[i] = 120;
    }

    for (rank = RANK_1; rank <= RANK_8; rank++) {
        for (file = FILE_A; file <= FILE_H; file++) {
            sq_120 = file_rank_to_120sq(file, rank);
            sq_64_to_sq_120[sq_64] = sq_120;
            sq_120_to_sq_64[sq_120] = sq_64;
            sq_64++;
        }
    }
}

void init() {
    init_sq_120_to_64();
}