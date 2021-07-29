#define _CRT_SECURE_NO_WARNINGS 1
  
#include"game.h"
  
void game()
{
 char mine[ROW + 2][COL + 2];     //记录地雷的数组
 char show[ROW + 2][COL + 2];     //展示给玩家的数组
  
 Init(mine, show, ROW + 2, COL + 2);    //初始化
 set_mine(mine, MINE_NUM);      //布雷
  
 //print_show(mine, ROW, COL);      //打印布雷的棋盘
  
 print_show(show, ROW, COL);      //打印棋盘
  
 int ret = -1;         //用于游戏中判断是否是第一步
  
 while (1)          //玩家进行游戏
 {
 int x, y;
 int num = -1;
 printf("请输入坐标< x y >:\n");
 scanf("%d%d", &x, &y);
 if (x < 1 || x>10 || y < 1 || x>10)
 {
 printf("输入的坐标有误，请重新输入：\n");
 }
 else
 {
 if (ret == -1 && mine[x][y] == '1')   //第一步踩雷
 {
 mine[x][y] = '0';      //除掉这个雷
 set_mine(mine, 1);     // 再布一颗雷
 }
  
 if (mine[x][y] == '0')  //没有踩雷 
 {
 ret = 0;
 num = get_round_mine(mine, x, y);
 if (num != 0)
 {
  show[x][y] = num + '0';
 }
 else    //周围一圈都没有雷
 {
  open_show(mine, show, x, y); //展开函数 （连续展开）
 }
 print_show(show, ROW, COL);      //打印棋盘
 }
  
 else            // 踩雷了
 {
 printf("少侠，你踩到雷了！！！\n");
 print_show(mine, ROW, COL);      //打印棋盘
 return;
 }
 }
  
 if (Is_win(show))
 {
 printf("恭喜！！！您胜利啦!!!\n");
 break;
 }
 }
}
  
  
void Init(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int row, int col)
{
 memset(mine, '0', row*col * sizeof(mine[0][0]));
 memset(show, '*', row*col * sizeof(show[0][0]));
}
  
void print_show(char show[ROW + 2][COL + 2], int row, int col)   //打印棋盘
{
  
 int i;
 int j;
 printf(" ");
 for (i = 1; i <= col; i++)
 {
 printf("%2d", i);
 }
 printf("\n ");
 for (i = 0; i < col; i++)
 {
 printf("--");
 }
 printf("\n");
 for (i = 1; i <= row; i++)
 {
 printf("%2d|", i);
 for (j = 1; j <= col; j++)
 {
 printf("%2c", show[i][j]);
 }
 printf("\n");
 }
 printf("\n");
}
  
void set_mine(char mine[ROW + 2][COL + 2], int mineNumber)   //布雷
{
 int x = -1;
 int y = -1;
 while (mineNumber)
 {
 x = rand() % ROW + 1;
 y = rand() % COL + 1;
 if (mine[x][y] == '0')
 {
 mine[x][y] = '1';
 --mineNumber;
 }
 }
}
  
int get_round_mine(char mine[ROW + 2][COL + 2], int x, int y) //获取周围雷的个数；
{
 return (mine[x - 1][y - 1]) + (mine[x - 1][y]) + (mine[x - 1][y + 1]) +
 (mine[x][y + 1]) + (mine[x + 1][y + 1]) + (mine[x + 1][y]) +
 (mine[x + 1][y - 1]) + (mine[x][y - 1]) - 8 * '0';
}
  
void open_show(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int x, int y) //展开函数
{
 if (x >= 1 && x <= 10 && y >= 1 && y <= 10 && (mine[x][y] != 1) && (show[x][y] == '*'))
 {
 if (get_round_mine(mine, x, y) > 0)
 {
 show[x][y] = get_round_mine(mine, x, y) + '0';
 }
 else
 {
 show[x][y] = ' ';
 open_show(mine, show, x - 1, y - 1);
 open_show(mine, show, x - 1, y);
 open_show(mine, show, x - 1, y + 1);
 open_show(mine, show, x, y + 1);
 open_show(mine, show, x, y - 1);
 open_show(mine, show, x + 1, y - 1);
 open_show(mine, show, x + 1, y);
 open_show(mine, show, x + 1, y + 1);
 }
 }
}
  
int Is_win(char show[ROW + 2][COL + 2])  //判赢
{
 int count = MINE_NUM;
 int i;
 int j;
 for (i = 1; i <= ROW; i++)
 {
 for (j = 1; j <= ROW; j++)
 {
 if (show[i][j] == '*')
 {
 count--;
 }
 }
 }
 if (count == 0)  //雷全部找到
 {
 return 1;
 }
 else
 {
 return 0;
 }
}