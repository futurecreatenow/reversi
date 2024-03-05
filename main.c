#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#define FULL_CELL 16
#define BOARD_SIDE 4

enum board_num {ZERO,ONE,TWO,THREE,FOUR};
enum status_num {UNDECIDED_0,ME_1,PC_2};
int board[BOARD_SIDE][BOARD_SIDE] = {UNDECIDED_0}; 


void setup(void);
void show(void);
void select(struct BOARD *board);
void main(void) {
    struct BOARD board;
    board.turn = true;
    setup(); //最初の〇×を配置
    show(); //碁盤を表示
    select(&board); //置ける碁盤を表示
    
}
void setup(){
    //〇の表示
    board[ONE][TWO] = ME_1;board[TWO][ONE] = ME_1;
    //×の表示
    board[ONE][ONE] = PC_2;board[TWO][TWO] = PC_2;
}
void show(){
    printf("################\n");
    for (int  i = 0; i < BOARD_SIDE; i++)
    {
        for (int j = 0; j < BOARD_SIDE; j++)
        {
            switch (board[i][j])
            {
                case ME_1:printf("o");break;
                case PC_2:printf("x");break;
                case UNDECIDED_0:printf("-");break;
                default:break;
            }
            
        }
        printf("\n");
    }
    printf("################\n");
}
void select(struct BOARD *board_){
    //置ける場所を表示させる>>>branchで作成します
    if (board_->turn == true)printf("your turn>>>input o\n"),printf("[line][col]\n");
    else printf("PC turn>>>o"); //2024/3/5 


}