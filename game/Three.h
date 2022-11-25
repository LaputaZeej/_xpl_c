//
// Created by 项鹏乐 on 2022/10/31.
//

#ifndef _XPL_C_THREE_H
#define _XPL_C_THREE_H

#define ROW 3
#define COL 3

#define EMPTY  ' '
#define PLAYER '*'
#define COMPUTER '#'

#define PLAYER_WIN 'p'
#define COMPUTER_WIN 'C'
#define PING 'v'
#define DOING 'd'

#include "stdio.h"
#include <stdlib.h>

void GameInit(char games[ROW][COL], int row, int col);

void GameDisplay(char games[ROW][COL], int row, int col);

void GamePlayerMove(char games[ROW][COL], int row, int col);

void GameComputerMove(char games[ROW][COL], int row, int col);

char GameCheck(char games[ROW][COL], int row, int col);

#endif //_XPL_C_THREE_H

