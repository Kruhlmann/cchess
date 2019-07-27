// hashkeys.c

#include "headers/commons.h"

u64 hash_gen(const BOARD *pos) {
    u64 hash = 0ULL;
    byte sq;
    byte piece;

    for (sq = 0; sq < BRD_TILE_CNT; sq++) {
        piece = pos->pieces[sq];
        if (piece != NO_SQ && piece != EMPTY) {
            ASSERT(piece >= wP && piece <= bK);
            hash ^= piece_keys[piece][sq];
        }
    }

    if (pos->side_moving == WHITE) {
        hash ^= side_key;
    }

    if (pos->en_pass != NO_SQ) {
        ASSERT(pos->en_pass >= 0 && pos->en_pass < BRD_TILE_CNT);
        hash ^= piece_keys[EMPTY][pos->en_pass];
    }

    ASSERT(pos->castle_perm >= 0x0000 && pos->castle_perm <= 0x1000);

    hash ^= castle_keys[pos->castle_perm];

    return hash;
}