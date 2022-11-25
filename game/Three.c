//
// Created by 项鹏乐 on 2022/10/31.
//

#include <stdlib.h>
#include "Three.h"

void GameInit(char games[ROW][COL], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            games[i][j] = EMPTY;
        }
    }
}

void GameDisplay(char games[ROW][COL], int row, int col) {
    for (int i = 0; i < row; ++i) {
        // 输入行
        for (int j = 0; j < col; ++j) {
            printf(" %c ", games[i][j]);
            if (j < col - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < row - 1) {
            for (int j = 0; j < col; ++j) {
                printf("---");
                if (j < col - 1) {
                    printf("|");
                }
            }
            printf("\n");
        }

    }
}

void GamePlayerMove(char games[ROW][COL], int row, int col) {
    printf("玩家走...\n");
    int x = 0;
    int y = 0;
    while (1) {
        printf("请输入坐标:>");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if (games[x - 1][y - 1] == EMPTY) {
                games[x - 1][y - 1] = PLAYER;
                break;
            } else {
                printf("该位置已有棋子，请下其他地方！\n");
            }
        } else {
            printf("输入错误x[1-%d],y[1-%d]\n", row, col);
        }
    }


}

char GameIsFull(char games[ROW][COL], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (games[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

char GameCheck(char games[ROW][COL], int row, int col) {
    for (int i = 0; i < row; ++i) {
        int win = 1;
        for (int j = 0; j < col - 1; ++j) {
            if (games[i][j] == EMPTY || games[i][j] != games[i][j + 1]) {
                win = 0;
                break;
            }
        }
        if (win == 1) {
            printf(" - \n");
            if (games[i][0] == PLAYER) {
                return PLAYER_WIN;
            } else if (games[i][0] == COMPUTER) {
                return COMPUTER_WIN;
            }
        }
    }

    for (int i = 0; i < col; ++i) {
        int win = 1;
        for (int j = 0; j < row - 1; ++j) {
            // i = 2
            // 0 2
            // 1 2
            // 2 2
            if (games[j][i] == EMPTY || games[j][i] != games[j + 1][i]) {
                win = 0;
                break;
            }
        }
        if (win == 1) {
            printf(" | \n");
            if (games[0][i] == PLAYER) {
                return PLAYER_WIN;
            } else if (games[0][i] == COMPUTER) {
                return COMPUTER_WIN;
            }
        }
    }

    // x x x x
    // x x x x
    // x x x x
    // x x x x
    // 0 0
    // 1 1
    // 2 2
    // 3 3
    int win = 1;
    char temp = 's';
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i != j)continue;
            //printf("->\\ [%d,%d] : %c\n", i, j, games[i][j]);
            if (games[i][j] == EMPTY) {
                win = 0;
                break;
            } else {
                if (temp=='s'){
                    temp = games[i][j];
                }else if (temp == games[i][j]) {
                } else {
                    win = 0;
                    break;
                }
            }
        }
    }
    if (win == 1) {
        //printf(" \\ \n");
        if (games[0][0] == PLAYER) {
            return PLAYER_WIN;
        } else if (games[0][0] == COMPUTER) {
            return COMPUTER_WIN;
        }
    }

    // x x x x
    // x x x x
    // x x x x
    // x x x x

    // 0 3
    // 1,2
    // 2,1
    // 3,0
    win = 1;
     temp = 's';
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
//            if (i + col - j  != row - 1)continue;
            if (i != j)continue;
            //printf("->/ [%d,%d] : %c\n", i, col - j - 1, games[i][col - j - 1]);
            if (games[i][col - j - 1] == EMPTY) {
                win = 0;
                break;
            }else{
                if (temp=='s'){
                    temp = games[i][col - j - 1];
                }else if (temp == games[i][col - j - 1]) {
                } else {
                    win = 0;
                    break;
                }
            }
        }
    }
    if (win == 1) {
        //printf(" / \n");
        if (games[0][col - 1] == PLAYER) {
            return PLAYER_WIN;
        } else if (games[0][col - 1] == COMPUTER) {
            return COMPUTER_WIN;
        }
    }
    if (GameIsFull(games, row, col) == 0) return DOING;
    return PING;
}


void GameComputerMove(char games[ROW][COL], int row, int col) {
    printf("电脑走");
    int x = 0;
    int y = 0;
    while (1) {
        x = rand() % row;
        y = rand() % col;
        printf(".");
        if (games[x][y] == EMPTY) {
            games[x][y] = COMPUTER;
            break;
        }
    }
    printf("\n");
}