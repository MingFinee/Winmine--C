//ɨ����Ϸ
#include <stdio.h>
#include "game2.h"



void game2()
{
	char hidden[ROW][COL];//�洢���õ��׵���Ϣ    11*11 ���׵�������11��ģ���ֻ���ڵ�2����10��
	char showing[a][b];//�洢�Ų�ó�����Χ���׵���Ϣ 9*9
	init_g(showing, a, b);
	init_g(hidden, ROW, COL);//��ʼ������
	SetMine(hidden,a,b);//���õ���
	p_g(hidden, ROW, COL);//��ӡ���ױ��ڲ���
	p_g(showing, a, b);//��ӡ����
	FindMine(showing,hidden,a,b);


}

int main()
{
	int i;
	menu();
	do
	{
		printf("�����룺\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:game2();
			break;
		case 2:printf("�˳���Ϸ\n");
			break;
		default:printf("����������������룺\n");
		}
	} while (i!=2);
	return 0;
}