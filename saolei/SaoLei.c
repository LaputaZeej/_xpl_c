//
// Created by 项鹏乐 on 2022/10/31.
//

#include <stdlib.h>
#include "SaoLei.h"


// 0:显示 0：未翻开 1：已翻开（安全 已炸死）    // todo 标记雷区（？）
// 1:雷   1：有雷 0：没有雷
// 0000 0011

int GameIsLei(const char *state) {
    char v = *state;
    return ((v >> 1) & 0b1) == 1;
}

int GameIsShow(const char *state) {
    //printf("c=%c|",*state);
    return (*state & 0b1) != 0;
}

int GameIsTag(const char *state) {
    //printf("c=%c|",*state);
    return (*state >> 2 & 0b1) != 0;
}

void GameSetShow(char *state, int on) {
    //printf("%d", *state);
    if (on == 0) {
        *state &= ~(0x1 << 0);
    } else {
        //printf("->");
        *state |= (0x1 << 0);
    }
    //printf("%d %p | ", *state, state);
}

void GameSetLei(char *state, int on) {
    if (on == 0) {
        *state &= ~(0x1 << 1);
    } else {
        *state |= (0x1 << 1);
    }
}

void GameSetTag(char *state, int on) {
    if (on == 0) {
        *state &= ~(0x1 << 2);
    } else {
        *state |= (0x1 << 2);
    }
}


void SaoLeiInit(char games[ROWS][COLS], int row, int col) {
//    printf("SaoLeiInit %p\n",games);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            games[i][j] = 0b0000;
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            char *temp = &games[i][j];
            GameSetShow(temp, 0);
            GameSetLei(temp, 0);
        }
    }
}

void SaoLeiSetLei(char games[ROWS][COLS], int row, int col, int count) {
    printf("初始化雷的数量:%d\n", count);
    while (count) {
        int x = rand() % ROWS - 1;
        int y = rand() % COLS - 1;
        if (x <= 0 || x >= ROWS - 1 || y <= 0 || y >= COLS)continue;
        char *temp = &games[x][y];
        //printf("SaoLeiSetLei %d,%d %p", x, y,temp);
        if (GameIsLei(temp) == 0) {
            GameSetLei(temp, 1);
            //printf("-->%c %p\n", games[x+1][y+1],temp);
            count--;
        }
    }
}

int Get_My_Number(char games[ROWS][COLS], int row, int col, int x, int y) {
    int r = GameIsLei(&games[x - 1][y - 1]) +
            GameIsLei(&games[x][y - 1]) +
            GameIsLei(&games[x + 1][y - 1]) +

            GameIsLei(&games[x - 1][y]) +
            GameIsLei(&games[x + 1][y]) +

            GameIsLei(&games[x - 1][y + 1]) +
            GameIsLei(&games[x][y + 1]) +
            GameIsLei(&games[x + 1][y + 1]);
    return r;
}

void SaoLeiDisplay(char games[ROWS][COLS], int row, int col, int showLei) {
    for (int i = 0; i < ROWS; ++i) {
        // 第一行 最后一行
        if (i == 0 || i == ROWS - 1) {
            for (int j = 0; j < COLS; ++j) {
                if (j == 0 || j == COLS - 1) {
                    printf("#  ");
                } else {
                    printf("%d  ", j); // 列表题
                }
            }
            printf("\n");
        } else {
            for (int j = 0; j < COLS; ++j) {
                if (j == 0 || j == COLS - 1) {
                    printf("%d  ", i); // 行标题
                } else {
                    char *temp = &(games[i][j]);
                    // printf("%d  ", *temp); // todo 测试
                    int r = GameIsLei(temp);
                    if ((showLei == 1 && r == 1) || (r == 1 && GameIsShow(temp) == 1)) {
                        printf("%c  ", BOOB);
                    } else if (GameIsShow(temp) == 1) {
                        int num = Get_My_Number(games, row, col, i, j);
                        //printf("(%d)",num);
                        if (num == 0) {
                            printf("%c  ", num);
                        } else {
                            printf("%d  ", num);
                        }

                        // todo 检测爆炸or正常
                    } else {
                        //printf("%d %p ", temp, &temp);
                        if (GameIsTag(temp)) {
                            printf("%c  ", TAG);
                        } else {
                            printf("%c  ", NOR);
                        }
                    }
                }
            }
            printf("\n");
        }
    }



//        printf("%d  ", i); // 行号标记
//        for (int j = 0; j < COLS - 1; ++j) {
//            char *temp = &(games[i + 1][j + 1]);
//            int r = GameIsLei(temp);
//
////            printf("%d  ", *temp);
////            printf("(%d)", *temp);
//            if ((showLei == 1 && r == 1) || (r == 1 && GameIsShow(temp) == 1)) {
//                printf("%c  ", BOOB);
//            } else if (GameIsShow(temp) == 1) {
//                int num = Get_My_Number(games, row, col, i, j);
//                //printf("(%d)",num);
//                if (num == 0) {
//                    printf("%c  ", num);
//                } else {
//                    printf("%d  ", num);
//                }
//
//                // todo 检测爆炸or正常
//            } else {
//                //printf("%d %p ", temp, &temp);
//                if (GameIsTag(temp)) {
//                    printf("%c  ", TAG);
//                } else {
//                    printf("%c  ", NOR);
//                }
//            }
//        }
//        printf("\n");
//    }
}

void SaoLeiPlay(char games[ROWS][COLS], int row, int col) {
    int x, y, z = 0;
    int success = 0;
    while (1) {
        printf("输入你选择的位置[x,y,z]（x,y为坐标，z为标记/反标记 )）\n");
        printf("例如 1 2 0 代表翻开（1，2），1 2 1代表标记（1，2）\n");
        printf("请输入:>");
        scanf("%d%d%d", &x, &y, &z);
        if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
            char *temp = &games[x][y];
            if (z != 0) {
                // 标记
                if (GameIsTag(temp)) {
                    GameSetTag(temp, 0);
                } else {
                    GameSetTag(temp, 1);
                }
                SaoLeiDisplay(games, ROWS, COLS, 0);
            } else {

                if (GameIsLei(temp)) {
                    printf("你被炸死了\n");
                    GameSetShow(temp, 1);
                    SaoLeiDisplay(games, ROWS, COLS, 0);
                    printf("————————————————————————————————————————————————————————\n");
                    break;
                } else {
                    GameSetShow(temp, 1);
                    SaoLeiDisplay(games, ROWS, COLS, 0);
                    // todo 扫雷成功
                    success++;
                    if (ROW * COL - success == COUNT) {
                        printf("太棒了！你成功做到了！一共%d个雷！\n", COUNT);
                        SaoLeiDisplay(games, ROWS, COLS, 1);
                        printf("————————————————————————————————————————————————————————\n");
                        break;
                    }
                }
            }
        } else {
            printf("输入错误\n");
        }
    }
}