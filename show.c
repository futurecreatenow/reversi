//マス目を表示させる関数
#include <stdio.h>
#define ONE_SIDE 4
#define ALL_CELL 16

enum show_num {ME_Show_0,UNDECIDED_Show_1,PC_Show_2};
void show(){
    printf("################\n");
    for (int  i = 0; i < ALL_CELL; i++)
    {
        switch (board[i].board_status)
        {
            case ME_Show_0:printf("o");break;
            case PC_Show_2:printf("x");break;
            case UNDECIDED_Show_1:printf("-");break;
            default:break;
        }
        if (i % ONE_SIDE == ONE_SIDE - 1){printf("\n");}    
        
    }
    printf("################\n");
}