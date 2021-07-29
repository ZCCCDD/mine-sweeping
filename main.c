#define _CRT_SECURE_NO_WARNINGS 1
  
#include"game.h"
  
void menu()   //菜单
{
 printf("###################################\n");
 printf("############# 1.play ############\n");
 printf("############# 0.exit ############\n");
 printf("###################################\n");
  
}
  
int main()
{
 srand((unsigned int)time(NULL));
 int input = 1;
 printf("请选择游戏进程: \n");
 do {
 menu();
 scanf("%d", &input);
 switch (input) {
 case 1:
 game();    //主游戏 
 break;
 case 0:
 break;
 default:
 printf("选择错误，客官请重新选择：\n");
 break;
 }
 } while (input);
  
  
 system("pause");
 return 0;
}