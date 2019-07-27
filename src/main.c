// main.c

#include "stdio.h"
#include "headers/commons.h"

int main() {
    init();
    
    BOARD board[1];

    parse_FEN(START_FEN, board);
    // print_board(board);

    return 0;
}