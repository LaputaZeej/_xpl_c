//
// Created by 项鹏乐 on 2022/10/31.
//

#include <stdio.h>
#include <time.h>
#include "SaoLei.h"

void game() {
    printf("扫雷游戏开始！\n");
    char broad[ROWS][COLS] = {0};
    SaoLeiInit(broad, ROWS, COLS);
    SaoLeiSetLei(broad,ROWS,COLS,COUNT);
    SaoLeiDisplay(broad, ROWS, COLS,0);
    SaoLeiPlay(broad, ROWS, COLS);


}

int main() {


    int input = 0;
    srand((unsigned int) (time(NULL)));
    do {
        printf("**************************************\n");
        printf("***********     扫雷   ***************\n");
        printf("***********     v1.0   ***************\n");
        printf("********* [1]开始 [0]退出 *************\n");
        printf("**************************************\n");
        printf("请输入>:");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                input = 0;
                printf("退出游戏！\n");
                break;
            default:
                printf("您的输入错误！\n");
                break;
        }
    } while (input);
    return 0;
}