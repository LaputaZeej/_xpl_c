//
// Created by 项鹏乐 on 2022/10/31.
//

#include <stdio.h>
#include <time.h>

#include "Three.h"

void game() {
    printf("游戏开始！\n");
    char games[ROW][COL] = {0};
    GameInit(games, ROW, COL);
    GameDisplay(games, ROW, COL);
    char ret = DOING;
    while (1) {
        // 玩家
        GamePlayerMove(games, ROW, COL);
        GameDisplay(games, ROW, COL);
        ret = GameCheck(games, ROW, COL);
        //printf("<<<<<<<<<<<<<<<<<<<<%c\n",ret);
        if (ret != DOING) {
            break;
        }
        //电脑
        GameComputerMove(games, ROW, COL);
        GameDisplay(games, ROW, COL);
        ret = GameCheck(games, ROW, COL);
        //printf("<<<<<<<<<<<<<<<<<<<<%c\n",ret);
        if (ret != DOING) {
            break;
        }
    }
    if (ret == PLAYER_WIN) {
        printf("玩家赢了！！！！！\n");
    } else if (ret == COMPUTER_WIN) {
        printf("电脑赢了！！！！！\n");
    } else if (ret == PING) {
        printf("平局了！！！！！！\n");
    }

}

int main() {

    int input = 0;
    srand((unsigned int) (time(NULL)));
    do {
        printf("**************************************\n");
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