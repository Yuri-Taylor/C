#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 3
#define COL 3
void InitBoard(char arr[ROW][COL], int row, int col);
void DisplayBoard(char arr[ROW][COL], int row, int col);
void PlayerMove(char arr[ROW][COL], int row, int col);
void ComputerMove(char arr[ROW][COL], int row, int col);
char IsWin(char arr[ROW][COL], int row, int col);

#endif