#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "show.c"
#include "judge.c"
#define FULL_CELL 16

enum board_num {ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
                ELE,TWE,THI,FOURTE,FIF,SIXTE};
enum status_num {ME_0,UNDECIDED_1,PC_2};
struct BOARD board[FULL_CELL] =     {{ONE,UNDECIDED_1},{TWO,UNDECIDED_1},{THREE,UNDECIDED_1},{FOUR,UNDECIDED_1},
                                    {FIVE,UNDECIDED_1},{SIX,PC_2},{SEVEN,ME_0},{EIGHT,UNDECIDED_1},
                                    {NINE,UNDECIDED_1},{TEN,ME_0},{ELE,PC_2},{TWE,UNDECIDED_1},
                                    {THI,UNDECIDED_1},{FOURTE,UNDECIDED_1},{FIF,UNDECIDED_1},{SIXTE,UNDECIDED_1}};


void main(void) {
    show();
    judge();
}