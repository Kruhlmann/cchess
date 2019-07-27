#ifndef STRUCTS_H
#define STRUCTS_H

#include "types.h"

typedef struct {
    u64 hash;
    byte move;
    byte castle_perm;
    byte en_pass;
    byte fifty_moves;
} MOVE;

typedef struct {
    MOVE moves[MAX_GAME_MOVES];

    u64 hash;
    u64 pawns[3];
    short cur_depth;
    short my_half_moves;
    short opponent_half_moves;
    short pcs_number[13];
    short piece_list[13][10];
    byte non_pawn_pcs[3];
    byte minor_pcs[3];
    byte major_pcs[3];
    byte castle_perm;
    byte pieces[BRD_TILE_CNT];
    byte king_sq[2];
    byte side_moving;
    byte en_pass;
    byte fifty_moves;
} BOARD;

#endif