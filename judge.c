#include <stdio.h>
#define ALL_CELL_ 16
#define INIT_BOARD_NUM 1
#define JUDGE_NUM 9
enum judge_num {ME_Jude_0,UNDECIDED_Judge_1,PC_Judge_2};


void judge(){
    for (int i = INIT_BOARD_NUM; i <= ALL_CELL_; i++)
    {
        switch (board[i - 1].board_status)
        {
            case ME_Jude_0:
                //〇と記載のboard_num
                for (int j = i - 5; j < JUDGE_NUM; j++)
                {
                    switch (board[j].board_status)
                    {
                        case PC_Judge_2:
                            printf("x:%d",j + 1);
                            break;
                        case UNDECIDED_Judge_1:break;
                        default:break;
                    }
                }
                printf("o:%d\n",i);
                break;
            case PC_Judge_2:break;
                //×と記載のboard_num
            case UNDECIDED_Judge_1:break;
                //未記載のboard_num
            default:break;
        }
        
        
    }
   
    
    
}
