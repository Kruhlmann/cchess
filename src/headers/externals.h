#ifndef EXTERNALS_H
#define EXTERNALS_H

/* Globals */

extern short sqs_120[BRD_TILE_CNT];
extern short sqs_64[64];
extern u64 set_mask[64];
extern u64 clr_mask[64];
extern u64 piece_keys[13][120];
extern u64 side_key;
extern u64 castle_keys[16];
extern char piece_chars[];
extern char side_chars[];
extern char rank_chars[];
extern char file_chars[];

/* Functions */

// init.c
extern void init();

// bitboards.c
extern void print_bitboard(u64 bb);
extern short pop_bb(u64 *bb);
extern short cnt_bb(u64 b);

// hashkeys.c
extern u64 hash_gen(const BOARD *pos) ;

// board.c
extern void reset_board(BOARD *pos);
extern void print_board(const BOARD *pos);
extern void parse_FEN(char *fen, BOARD *pos);

// rand.c
extern u64 rand_u64();

#endif