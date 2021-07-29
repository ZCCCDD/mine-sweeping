#pragma once
  
#ifndef _GAME_H_
#define _GAME_H_
  
//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
  
  
#define ROW 10    //棋盘大小
#define COL 10
#define MINE_NUM 10   //雷的个数
  
void game();
  
void Init(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int row, int col); //初始化
void print_show(char show[ROW + 2][COL + 2], int row, int col);     //打印棋盘
void set_mine(char mine[ROW + 2][COL + 2], int mineNumber);      //布雷
int get_round_mine(char mine[ROW + 2][COL + 2], int x, int y);   //获取周围雷的个数；
void open_show(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int x, int y); //展开函数
int Is_win(char show[ROW + 2][COL + 2]);   //判赢
  
#endif