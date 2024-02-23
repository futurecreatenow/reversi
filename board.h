#ifndef board_h
#define board_h
#define FULL_CELL_h 16
struct BOARD
{
    int board_num;
    int board_status;
};
extern struct BOARD board[FULL_CELL_h];
#endif