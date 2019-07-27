#include "stdio.h"
#include "headers/commons.h"
#include "headers/macros.h"

const short BIT_TABLE[64] = {
  63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
  51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
  26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
  58, 20, 37, 17, 36, 8
};

short pop_bb(u64 *bit_board) {
    u64 b = *bit_board ^ (*bit_board - 1);
    unsigned int fold = (unsigned) ((b & 0xFFFFFFFF) ^ (b >> 32));
    *bit_board &= (*bit_board - 1);
    return BIT_TABLE[(fold * 0x783a9b23) >> 26];
}

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