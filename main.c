#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#define FULL_CELL 16
#define BOARD_SIDE 4

enum board_num {ZERO,ONE,TWO,THREE,FOUR};
enum status_num {UNDECIDED_0,ME_1,PC_2};
int board[BOARD_SIDE][BOARD_SIDE] = {UNDECIDED_0};
int score_board[BOARD_SIDE][BOARD_SIDE] = {UNDECIDED_0};
int pc_line = 0;
int pc_col = 0;
bool finish_flag = false;

void setup(void);
void show(void);
void select(struct BOARD *board);
void reverse(struct BOARD *board);
void stone_sum(struct BOARD *board);
void pc_expe();
void pc_put();
void main(void) {
    struct BOARD board;
    board.turn = true;
    setup(); //最初の〇×を配置
    show(); //碁盤を表示
    do
    {
        select(&board); //置けるマス目を選択
        reverse(&board); //碁盤をひっくり返す
        show(); 
        stone_sum(&board); //碁盤の合計計算
        pc_expe(); //pcの置く場所の候補を決める
        pc_put(); //pcの碁盤を置く
        show();
        stone_sum(&board);
    } while (finish_flag == false);
    


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
            switch (board[j][i])
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
    bool select_flag = false;

    //置ける場所を表示させる>>>branchで作成します
    printf("[line][col]\n");


    do
    {
        printf("select line(0-3)>>>\n");
        scanf("%d",&board_->line);
        printf("select col(0-3)>>>\n");
        scanf("%d",&board_->col);
        if (board_->line == 0 || board_->line == 1 || board_->line == 2 || board_->line == 3 ||
            board_->col == 0 || board_->col == 1 || board_->col == 2 || board_->col == 3 )
            {
            

            //斜め
                if (board_->line ==  0 && board_->col == 0){
                    if (board[1][1] == PC_2 && board[2][2] == PC_2 && board[3][3] == ME_1)
                            printf("OK_diagonal_01\n"),
                            select_flag = true;
                }


                if (board_->line ==  3 && board_->col == 3){
                    if (board[1][1] == PC_2 && board[2][2] == PC_2 && board[0][0] == ME_1)
                            printf("OK_diagonal_02\n"),
                            select_flag = true;
                }
                        
                if (board_->line ==  3 && board_->col == 0){
                    if (board[2][1] == PC_2 && board[1][2] == PC_2 && board[0][3] == ME_1)
                            printf("OK_diagonal_03\n"),
                            select_flag = true;
                }
                        
                if (board_->line ==  0 && board_->col == 3){
                    if (board[2][1] == PC_2 && board[1][2] == PC_2 && board[3][0] == ME_1)
                            printf("OK_diagonal_04\n"),
                            select_flag = true;
                }




                
                //縦列　下に×が存在
                
                if (board[board_->line][board_->col + 1] == PC_2
                    && board[board_->line][board_->col + 2] == ME_1)
                        
                            printf("OK_line_under_01\n"),
                            select_flag = true;
                            
                        
                if (board[board_->line][board_->col + 1] == PC_2
                        && board[board_->line][board_->col + 2] == PC_2
                        && board[board_->line][board_->col + 3] == ME_1)
                        
                            printf("OK_line_under_02\n"),
                            select_flag = true;
                            
                //縦列　上に×が存在
                
                if (board[board_->line][board_->col - 1] == PC_2
                    && board[board_->line][board_->col - 2] == ME_1)
                        
                            printf("OK_line_over_01\n"),
                            select_flag = true;
                            
                        
                if (board[board_->line][board_->col - 1] == PC_2
                        && board[board_->line][board_->col - 2] == PC_2
                        && board[board_->line][board_->col - 3] == ME_1)
                        
                            printf("OK_line_over_02\n"),
                            select_flag = true;

                //横列　右に×が存在
                
                if (board[board_->line + 1  ][board_->col] == PC_2
                    && board[board_->line + 2][board_->col] == ME_1)
                        
                            printf("OK_col_right_01\n"),
                            select_flag = true;
                            
                        
                if (board[board_->line + 1][board_->col ]== PC_2
                        && board[board_->line + 2][board_->col] == PC_2
                        && board[board_->line + 3][board_->col] == ME_1)
                        
                            printf("OK_col_right_02\n"),
                            select_flag = true;
                            
                //横列　左に×が存在
                
                if (board[board_->line - 1  ][board_->col] == PC_2
                    && board[board_->line - 2][board_->col] == ME_1)
                        
                            printf("OK_col_left_01\n"),
                            select_flag = true;
                            
                            
                        
                if (board[board_->line - 1][board_->col ]== PC_2
                        && board[board_->line - 2][board_->col] == PC_2
                        && board[board_->line - 3][board_->col] == ME_1)
                        
                            printf("OK_col_left_02\n"),
                            select_flag = true;

                
                if (select_flag == true)
                {
                    printf("Your choice is correct\n");
                }
                else{
                    printf("Your choice is incorrect\n");
                }
            }

        else printf("your select is not correct\n");
        
    } while (select_flag == false);
    
}
void reverse(struct BOARD *board_){
    board[board_->line][board_->col] = ME_1;

    //斜め

    
    if (board_->line ==  0 && board_->col == 0){
        if (board[1][1] == PC_2 && board[2][2] == PC_2 && board[3][3] == ME_1)
            board[1][1] == ME_1,board[2][2] == ME_1;
    }


    if (board_->line ==  3 && board_->col == 3){
        if (board[1][1] == PC_2 && board[2][2] == PC_2 && board[3][3] == ME_1)
            board[1][1] == ME_1,board[2][2] == ME_1;
    }
            
    if (board_->line ==  3 && board_->col == 0){
        if (board[2][1] == PC_2 && board[1][2] == PC_2 && board[0][3] == ME_1)
            board[2][1] == ME_1,board[1][2] == ME_1;
    }
            
    if (board_->line ==  0 && board_->col == 3){
        if (board[2][1] == PC_2 && board[1][2] == PC_2 && board[3][0] == ME_1)
            board[2][1] == ME_1,board[1][2] == ME_1;
    }




    
    //縦列　下に×が存在
    
    if (board[board_->line][board_->col + 1] == PC_2
        && board[board_->line][board_->col + 2] == ME_1)
        board[board_->line][board_->col + 1] = ME_1;
                
            
    if (board[board_->line][board_->col + 1] == PC_2
            && board[board_->line][board_->col + 2] == PC_2
            && board[board_->line][board_->col + 3] == ME_1)
            board[board_->line][board_->col + 1] = ME_1,
            board[board_->line][board_->col + 2] = ME_1;
                
    //縦列　上に×が存在
    
    if (board[board_->line][board_->col - 1] == PC_2
        && board[board_->line][board_->col - 2] == ME_1)
            board[board_->line][board_->col - 1] = ME_1;
                                
            
    if (board[board_->line][board_->col - 1] == PC_2
            && board[board_->line][board_->col - 2] == PC_2
            && board[board_->line][board_->col - 3] == ME_1)
            board[board_->line][board_->col - 1] = ME_1,
            board[board_->line][board_->col - 2] = ME_1;
                
    //横列　右に×が存在
    
    if (board[board_->line + 1  ][board_->col] == PC_2
        && board[board_->line + 2][board_->col] == ME_1)
        board[board_->line + 1  ][board_->col] = ME_1;
                                
            
    if (board[board_->line + 1][board_->col ]== PC_2
            && board[board_->line + 2][board_->col] == PC_2
            && board[board_->line + 3][board_->col] == ME_1)
            board[board_->line + 1  ][board_->col] = ME_1,
            board[board_->line + 2  ][board_->col] = ME_1;
                
    //横列　左に×が存在
    
    if (board[board_->line - 1  ][board_->col] == PC_2
        && board[board_->line - 2][board_->col] == ME_1)
        board[board_->line - 1][board_->col] = ME_1;
                
                
            
    if (board[board_->line - 1][board_->col ]== PC_2
            && board[board_->line - 2][board_->col] == PC_2
            && board[board_->line - 3][board_->col] == ME_1)
            board[board_->line - 1][board_->col] = ME_1,
            board[board_->line - 2][board_->col] = ME_1;

}
void stone_sum(struct BOARD *board_){
    int me_num = 0,pc_num = 0,undecide = 0;
    for (int  i = 0; i < BOARD_SIDE; i++)
    {
        for (int j = 0; j < BOARD_SIDE; j++)
        {
            switch (board[j][i])
            {
                case ME_1:me_num++;break;
                case PC_2:pc_num++;break;
                case UNDECIDED_0:undecide++;break;
                default:break;
            }
            
        }
    }
    if(undecide == 0) 
    {
        printf("finish\n");
        if (me_num > pc_num)
        {
            printf("you win\n");
        }else if (me_num == pc_num){
            printf("draw");
        }else{
            printf("you lose");
        }
        finish_flag = true;
    }
    printf("o >>>%d,x >>>%d\n",me_num,pc_num);

}

void pc_expe(){
    int line_up = 0;
    int line_under = 0;
    int col_right = 0;
    int col_left = 0;
    int dia_right = 0;
    int dia_left = 0;
    int stone_sum = 0;
    for (int i = 0; i < BOARD_SIDE; i++)
    {
        for (int j = 0; j < BOARD_SIDE; j++)
        {
            switch (board[j][i])
            {
            case UNDECIDED_0:
                //斜め
                if (board[0][0] == PC_2 && board[1][1] == ME_1 && board[2][2] == ME_1 && board[3][3] == PC_2) dia_left++;
                if (board[3][0] == PC_2 && board[2][1] == ME_1 && board[1][2] == ME_1 && board[3][0] == PC_2) dia_right++;
                
                //縦列　下に×が存在
                if (board[j][i + 1] == ME_1 && board[j][i + 2] == PC_2) line_under++;
                if (board[j][i + 1] == ME_1 && board[j][i + 2] == ME_1 && board[j][i + 3] == PC_2) line_under++;

                //縦列　上に×が存在
                if (board[j][i - 1] == ME_1 && board[j][i - 2] == PC_2) line_up++;
                if (board[j][i - 1] == ME_1 && board[j][i - 2] == ME_1 && board[j][i - 3] == PC_2) line_up++;

                //横列　右に×が存在
                if (board[j + 1][i] == ME_1 && board[j + 2][i] == PC_2) col_right++;
                if (board[j + 1][i] == ME_1 && board[j + 2][i] == ME_1 && board[j + 3][i] == PC_2) col_right++;


                //横列　左に×が存在
                if (board[j - 1][i] == ME_1 && board[j - 2][i] == PC_2) col_left++;
                if (board[j - 1][i] == ME_1 && board[j - 2][i] == ME_1 && board[j - 3][i] == PC_2) col_left++;



                stone_sum = line_up + line_under + col_right + col_left + dia_right + dia_left;
                score_board[j][i] = stone_sum;

                break;
            
            default:
                break;
            }
        }
        
    }

    
    int pc_score = 0;
    for (int i = 0; i < BOARD_SIDE; i++)
    {
        for (int j = 0; j < BOARD_SIDE; j++)
        {
            if (score_board[j][i] > pc_score)
            {
                pc_line = j;
                pc_col = i;
                pc_score = score_board[j][i];
            }
            
        }
        
    }


    

}

void pc_put(){
    board[pc_line][pc_col] = PC_2;
    printf("pc_put>>>(pc_line)%d,(pc_col)%d\n",pc_line,pc_col);
    //斜め
    if (pc_line ==  0 && pc_col == 0){
        if (board[1][1] == ME_1 && board[2][2] == ME_1 && board[3][3] == PC_2)
            board[1][1] == PC_2,board[2][2] == PC_2;
    }


    if (pc_line ==  3 && pc_col == 3){
        if (board[1][1] == ME_1 && board[2][2] == ME_1 && board[3][3] == PC_2)
            board[1][1] == PC_2,board[2][2] == PC_2;
    }
            
    if (pc_line ==  3 && pc_col == 0){
        if (board[2][1] == ME_1 && board[1][2] == ME_1 && board[0][3] == PC_2)
            board[2][1] == PC_2,board[1][2] == PC_2;
    }
            
    if (pc_line ==  0 && pc_col == 3){
        if (board[2][1] == ME_1 && board[1][2] == ME_1 && board[3][0] == PC_2)
            board[2][1] == PC_2,board[1][2] == PC_2;
    }

    //縦列　下に×が存在
    
    if (board[pc_line][pc_col + 1] == ME_1
        && board[pc_line][pc_col + 2] == PC_2)
        board[pc_line][pc_col + 1] = PC_2;
                
            
    if (board[pc_line][pc_col + 1] == ME_1
            && board[pc_line][pc_col + 2] == ME_1
            && board[pc_line][pc_col + 3] == PC_2)
            board[pc_line][pc_col + 1] = PC_2,
            board[pc_line][pc_col + 2] = PC_2;
                
    //縦列　上に×が存在
    
    if (board[pc_line][pc_col - 1] == ME_1
        && board[pc_line][pc_col - 2] == PC_2)
            board[pc_line][pc_col - 1] = PC_2;
                                
            
    if (board[pc_line][pc_col - 1] == ME_1
            && board[pc_line][pc_col - 2] == ME_1
            && board[pc_line][pc_col - 3] == PC_2)
            board[pc_line][pc_col - 1] = PC_2,
            board[pc_line][pc_col - 2] = PC_2;
                
    //横列　右に×が存在
    
    if (board[pc_line + 1  ][pc_col] == ME_1
        && board[pc_line + 2][pc_col] == PC_2)
        board[pc_line + 1  ][pc_col] = PC_2;
                                
            
    if (board[pc_line + 1][pc_col ]== ME_1
            && board[pc_line + 2][pc_col] == ME_1
            && board[pc_line + 3][pc_col] == PC_2)
            board[pc_line + 1  ][pc_col] = PC_2,
            board[pc_line + 2  ][pc_col] = PC_2;
                
    //横列　左に×が存在
    
    if (board[pc_line - 1  ][pc_col] == ME_1
        && board[pc_line - 2][pc_col] == PC_2)
        board[pc_line - 1][pc_col] = PC_2;
                
                
            
    if (board[pc_line - 1][pc_col ]== ME_1
            && board[pc_line - 2][pc_col] == ME_1
            && board[pc_line - 3][pc_col] == PC_2)
            board[pc_line - 1][pc_col] = PC_2,
            board[pc_line - 2][pc_col] = PC_2;

}