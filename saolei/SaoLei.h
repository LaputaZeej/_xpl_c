//
// Created by 项鹏乐 on 2022/10/31.
//

#ifndef _XPL_C_SAOLEI_H
#define _XPL_C_SAOLEI_H

#define ROW 9
#define COL 9
#define COUNT 12

#define ROWS  ROW+2
#define COLS  COL+2

#define BOOB 'X'
#define NOR '*'
#define TAG 'P'
#define SHOW 'o'

#include "stdio.h"
#include <stdlib.h>

void SaoLeiInit(char games[ROWS][COLS], int row, int col);
void SaoLeiSetLei(char games[ROWS][COLS], int row, int col,int count);
void SaoLeiDisplay(char games[ROWS][COLS], int row, int col,int showLei);
void SaoLeiPlay(char games[ROWS][COLS], int row, int col);

#endif //_XPL_C_SAOLEI_H

