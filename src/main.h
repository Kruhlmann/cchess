// main.h

#include "stdlib.h"

#ifndef MAIN_H
    #define MAIN_H

    #define DEBUG
    #ifndef DEBUG
        #define ASSERT(n)
    #else
        #define ASSERT(n) \
        if (!(n)) { \
            printf("%s - Failed", #n); \
            printf("\n\t* %s:%d\n", __FILE__, __LINE__); \
            exit(1); \
        }
    #endif

    typedef unsigned char byte;
    typedef unsigned long long u64;

    #define NAME "CChess 1.0"
    #define BRD_TILE_CNT 120
    #define MAX_GAME_MOVES 2048

    /* Macros */
    #define file_rank_to_120sq(file, rank) ((file) + 21 + ((rank) * 10))
    #define set_bit(bb, sq) ((bb) |= set_mask[(sq)])
    #define clr_bit(bb, sq) ((bb) &= clr_mask[(sq)])

    /* Globals */
    extern short sqs_120[BRD_TILE_CNT];
    extern short sqs_64[64];
    extern u64 set_mask[64];
    extern u64 clr_mask[64];

    /* Functions */

    // init.c
    extern void init();

    // bitboards.c
    extern void print_bitboard(u64 bb);
    extern short pop_bb(u64 *bb);
    extern short cnt_bb(u64 b);

    /* Enums */
    enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
    enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
    enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
    enum { WHITE, BLACK, BOTH };
    enum {
        A1 = 21, B1, C1, D1, E1, F1, G1, H1,
        A2 = 31, B2, C2, D2, E2, F2, G2, H2,
        A3 = 41, B3, C3, D3, E3, F3, G3, H3,
        A4 = 51, B4, C4, D4, E4, F4, G4, H4,
        A5 = 61, B5, C5, D5, E5, F5, G5, H5,
        A6 = 71, B6, C6, D6, E6, F6, G6, H6,
        A7 = 81, B7, C7, D7, E7, F7, G7, H7,
        A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_sq
    };
    enum { FALSE, TRUE };
    enum { WK_CASTLE = 0x0001, WQ_CASTLE = 0x0010, BK_CASTLE = 0x0100, BQ_CASTLE = 0x1000 };

    /* Structures */

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
        short cur_depth;
        short ply_me;
        short ply_opponent;
        short pcs_count[13];
        short non_pawn_pcs_count[3];
        short minor_pcs_count[3];
        short major_pcs_count[3];
        short piece_list[13][10];
        byte castle_perm;
        byte pieces[BRD_TILE_CNT];
        byte king_sq[2];
        byte pawns[3];
        byte side_moving;
        byte en_pass;
        byte fifty_moves;
    } BOARD;

#endif