// init.c

#include "headers/commons.h"

short sqs_120[BRD_TILE_CNT];
short sqs_64[64];

u64 set_mask[64];
u64 clr_mask[64];

u64 piece_keys[13][120];
u64 side_key;
u64 castle_keys[16];


void init_hashes() {
    byte i;
    byte j;

    side_key = rand_u64();
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 120; j++) {
            piece_keys[i][j] = rand_u64();
        }
    }

    for (i = 0; i < 16; i++) {
        castle_keys[i] = rand_u64();
    }

}

void init_bitmasks() {
    byte i;

    for (i = 0; i < 64; i++) {
        set_mask[i] = 0ULL;
        clr_mask[i] = 0ULL;
    }

    for (i = 0; i < 64; i++) {
        set_mask[i] = (1ULL << i);
        clr_mask[i] = ~set_mask[i];
    }
}

void init_sq_120_to_64() {
    short i = 0;
    short sq_120 = A1;
    short sq_64 = 0;
    byte file = FILE_A;
    byte rank = RANK_1;

    for (i = 0; i < BRD_TILE_CNT; i++) {
        sqs_64[i] = 65;
    }

    for (i = 0; i < 64; i++) {
        sqs_120[i] = 120;
    }

    for (rank = RANK_1; rank <= RANK_8; rank++) {
        for (file = FILE_A; file <= FILE_H; file++) {
            sq_120 = file_rank_to_120sq(file, rank);
            sqs_120[sq_64] = sq_120;
            sqs_64[sq_120] = sq_64;
            sq_64++;
        }
    }
}

void init() {
    init_sq_120_to_64();
    init_bitmasks();
    init_hashes();
}