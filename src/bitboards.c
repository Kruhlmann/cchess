#include "stdio.h"
#include "headers/commons.h"
#include "headers/macros.h"


short cnt_bb(u64 b) {
    short r;
    for (r = 0; r < b; r++) {
        b &= b - 1;
    }
    return r;
}

void print_bitboard(u64 bit_board) {
    u64 index = 1ULL;

    short rank;
    short file;
    short sq_64;
    short sq_120;

    printf("\n");
    for (rank = RANK_8; rank >= RANK_1; rank--) {
        for (file = FILE_A; file <= FILE_H; file++) {
            sq_120 = file_rank_to_120sq(file, rank);
            sq_64 = c_sq64(sq_120);

            if ((index << sq_64) & bit_board) {
                printf(" X ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
