#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Game() {
	int num = 0;
	//��������Ϸ
	//1.ϵͳ�������һ�����֣������1-100
	int toGuess = rand() % 100 + 1;
	//2.���û�����һ������
	while (1)
	{
		printf("������һ��������1-100����");
			scanf("%d", &num);
		if (num < toGuess)
		{
			printf("����\n");
		}
		else if (num > toGuess)
		{
			printf("����\n");
		}
		else
		{
			printf("��ϲ��¶��ˣ�\n");
			break;
		}


	}
}
int Menu()
{
	printf("===================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("===================\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
int main()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			Game();
		}
		else
		{
			printf("goodby!\n");
			break;
		}
	}
	return 0;
}