//ɨ��
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
	while (m)   //����game.h�ж���
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;  //1~9,��2����10��
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
		- 8 * '0');   //  '1'-'0'=1 ; '3'-'0'=3;��ASCII���֪
}
void FindMine(char showing[a][b], char hidden[ROW][COL], int r, int c)
{
	int x, y;
	int i = 0;
	char n = 0;
	while (i < 81 - n)
	{
		printf("���������꣺\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (showing[x - 1][y - 1] == '*')
			{
				if (hidden[x][y] == '1')
				{
					printf("�������\n");
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
				printf("�����ظ������������룺\n");
			}
		}
		else
			printf("�Ƿ����룬���������룺\n");
	}
	if (i >= 81 - n)
		printf("��ϲ�㣬������\n");
}
