//扫雷游戏
#include <stdio.h>
#include "game2.h"



void game2()
{
	char hidden[ROW][COL];//存储布置的雷的信息    11*11 放雷的棋盘是11格的，但只埋在第2到第10格
	char showing[a][b];//存储排查得出的周围的雷的信息 9*9
	init_g(showing, a, b);
	init_g(hidden, ROW, COL);//初始化数组
	SetMine(hidden,a,b);//布置地雷
	p_g(hidden, ROW, COL);//打印地雷便于测试
	p_g(showing, a, b);//打印数组
	FindMine(showing,hidden,a,b);


}

int main()
{
	int i;
	menu();
	do
	{
		printf("请输入：\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:game2();
			break;
		case 2:printf("退出游戏\n");
			break;
		default:printf("输入错误，请重新输入：\n");
		}
	} while (i!=2);
	return 0;
}