// main.h

#ifndef MAIN_H
#define MAIN_H

typedef unsigned char byte;
typedef unsigned long long U64;

#define NAME "CChess 1.0"
#define BRD_TILE_CNT 120
#define MAX_GAME_MOVES 2048

/* Macros */
#define file_rank_to_120sq(file, rank) ((file) + 21 + ((rank) * 10))

/* Globals */
extern int sq_120_to_sq_64[BRD_TILE_CNT];
extern int sq_64_to_sq_120[64];

/* Functions */
extern void init();

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
    U64 hash;
    byte move;
    byte castle_perm;
    byte en_pass;
    byte fifty_moves;
} MOVE;

typedef struct {
    MOVE moves[MAX_GAME_MOVES];

    U64 hash;
    short cur_depth;
    short ply_me;
    short ply_opponent;
    short pcs_count[13];
    short non_pawn_pcs_count[3];
    short minor_pcs_count[3];
    short major_pcs_count[3];
    byte castle_perm;
    byte pieces[BRD_TILE_CNT];
    byte king_sq[2];
    byte pawns[3];
    byte side_moving;
    byte en_pass;
    byte fifty_moves;
} BOARD;

#endif