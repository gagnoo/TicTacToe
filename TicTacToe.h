#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>

char matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
char Player = ' ';
const char PlayerX = 'x';
const char PlayerO = 'o';
int choice;

extern char Input(char value);
extern void ShowBoard();
extern void CheckMove(char choice);
extern void ChangePlayer();
extern int CheckCurrentValue();
extern int CheckWin();

#endif // TICTACTOE_H_INCLUDED
