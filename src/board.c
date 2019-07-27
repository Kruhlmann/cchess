// board.c

#include "stdio.h"
#include "headers/commons.h"

void reset_board(BOARD *pos) {
    byte i;

    for (i = 0; i < BRD_TILE_CNT; i++) {
        pos->pieces[i] = OFFBOARD;
    }

    for (i = 0; i < 64; i++) {
        pos->pieces[c_sq120(i)] = EMPTY;
    }

    for (i = 0; i < 3; i++) {
        pos->pawns[i] = 0ULL;
        pos->non_pawn_pcs[i] = 0;
        pos->minor_pcs[i] = 0;
        pos->major_pcs[i] = 0;
    }

    for (i = 0; i < 13; i++) {
        pos->pcs_number[i] = 0;
    }

    pos->king_sq[WHITE] = NO_SQ;
    pos->king_sq[BLACK] = NO_SQ;
    pos->side_moving = BOTH;
    pos->en_pass = NO_SQ;
    pos->fifty_moves = 0;
    pos->my_half_moves = 0;
    pos->opponent_half_moves = 0;
    pos->castle_perm = 0;
    pos->hash = 0ULL;
}

void parse_FEN(char *fen, BOARD *pos) {
    ASSERT(fen != NULL);
    ASSERT(pos != NULL);

    reset_board(pos);

    short count = 0;
    byte rank = RANK_8;
    byte file = FILE_A;
    byte piece = 0;
    byte i = 0;
    byte sq64 = 0;
    byte sq120 = 0;

    while ((rank >= RANK_1 && rank <= RANK_8) && *fen) {
        count = 1;

        switch(*fen) {
            case 'p': piece = bP; break;
            case 'r': piece = bR; break;
            case 'n': piece = bN; break;
            case 'b': piece = bB; break;
            case 'k': piece = bK; break;
            case 'q': piece = bQ; break;
            case 'P': piece = wP; break;
            case 'R': piece = wR; break;
            case 'N': piece = wN; break;
            case 'B': piece = wB; break;
            case 'K': piece = wK; break;
            case 'Q': piece = wQ; break;   
            case '1':   
            case '2':   
            case '3':   
            case '4':   
            case '5':   
            case '6':   
            case '7':   
            case '8':
                piece = EMPTY;
                count = *fen - '0';
                break;
            case '/':
            case ' ':
                rank --;
                file = FILE_A;
                fen++;
                continue;
            default:
                printf("Unable to parse supplied FEN string\n");
                printf("Triggered by %c\n", *fen);
                return;
        }

        for (i = 0; i < count; i++) {
            sq64 = rank * 8 + file;
            sq120 = c_sq120(sq64);

            printf("Piece was %d\n", piece);
            if (piece != EMPTY) {
                pos->pieces[sq120] = piece;
            }
            file++;
        }
        fen++;
    }

    ASSERT(*fen == 'w' || *fen == 'b');
    pos->side_moving = (*fen == 'w') ? WHITE : BLACK;
    fen += 2;

    for (i = 0; i < 4; i++) {
        if (*fen == ' ') {
            break;
        }

        switch (*fen) {
            case 'k': pos->castle_perm |= BK_CASTLE; break;
            case 'q': pos->castle_perm |= BQ_CASTLE; break;
            case 'K': pos->castle_perm |= WK_CASTLE; break;
            case 'Q': pos->castle_perm |= WQ_CASTLE; break;
            default: break;
        }

        fen++;
    }
    fen++;

    ASSERT(pos->castle_perm >= 0x0000 && pos->castle_perm <= 0x1111);

    if (*fen != '-') {
        file = fen[0] - 'a';
        rank = fen[1] - '1';

        ASSERT(file >= FILE_A && file <= FILE_H);
        ASSERT(rank >= RANK_1 && rank <= RANK_8);

        pos->en_pass = file_rank_to_120sq(file, rank);
    }

    pos->hash = hash_gen(pos);
}

void print_board(const BOARD *pos) {
    byte sq;
    byte file;
    byte rank;
    byte piece;

    printf("\nCCHESS BOARD\n\n");

    for (rank = RANK_8; rank >= RANK_1; rank--) {
        printf("%d  ", rank + 1);
        for (file = FILE_A; file <= FILE_H; file++) {
            sq = file_rank_to_120sq(file, rank);
            piece = pos->pieces[sq];
            printf(" %3c ", piece_chars[piece]);
        }
        printf("\n");
    }
    
    printf("\n   ");
    for (file = FILE_A; file <= FILE_H; file++) {
        printf(" %3c ", 'a' + file);
    }
    printf("\n");

    printf("Side:               %c\n", side_chars[pos->side_moving]);
    printf("En passant:         %d\n", pos->en_pass);
    printf("Castle permissions: %c%c%c%c\n",
        pos->castle_perm & WK_CASTLE ? 'K' : '-',
        pos->castle_perm & WQ_CASTLE ? 'Q' : '-',
        pos->castle_perm & BK_CASTLE ? 'k' : '-',
        pos->castle_perm & BQ_CASTLE ? 'q' : '-'
    );
    printf("Board hash:         %llX", pos->hash);

}