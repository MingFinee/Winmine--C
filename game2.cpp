//扫雷
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int menu()
{
	printf("**********************\n");
	printf("****1.play  2.exit****\n");
	printf("**********************\n");
	return 0;
}
#include "game2.h"
void init_g(char g[ROW][COL], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			g[i][j] = '0';
		}
	}
}
void init_g(char g[a][b], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			g[i][j] = '*';
		}
	}
}

void p_g(char g[a][b], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf(" %c ", g[i][j]);
			if (j < c - 1)
				printf("|");
		}
		printf("\n");
		if (i < r - 1)
		{
			for (j = 0; j < c; j++)
			{
				printf("---");
				if (j < c - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void p_g(char g[ROW][COL], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%c", g[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char g[ROW][COL], int r, int  c)
{
	srand(unsigned int(time(NULL)));
	int m = count;
	while (m)   //已在game.h中定义
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;  //1~9,第2到第10格
		if (g[x][y] == '0')
		{
			g[x][y] = '1';
			m--;
		}
	}
}

int compare(char hidden[ROW][COL], int x, int y)
{
	return (hidden[x - 1][y] + hidden[x][y - 1] + hidden[x + 1][y - 1] + hidden[x - 1][y - 1]
		+ hidden[x + 1][y] + hidden[x][y + 1] + hidden[x - 1][y + 1] + hidden[x + 1][y + 1]
		- 8 * '0');   //  '1'-'0'=1 ; '3'-'0'=3;查ASCII码可知
}
void FindMine(char showing[a][b], char hidden[ROW][COL], int r, int c)
{
	int x, y;
	int i = 0;
	char n = 0;
	while (i < 81 - n)
	{
		printf("请输入坐标：\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (showing[x - 1][y - 1] == '*')
			{
				if (hidden[x][y] == '1')
				{
					printf("你踩雷了\n");
					p_g(hidden, ROW, COL);
					break;
				}
				else
				{
					int n = compare(hidden, x, y);
					showing[x - 1][y - 1] = n + '0';
					i++;
					p_g(showing, a, b);
				}
			}
			else
			{
				printf("坐标重复，请重新输入：\n");
			}
		}
		else
			printf("非法输入，请重新输入：\n");
	}
	if (i >= 81 - n)
		printf("恭喜你，排完了\n");
}
