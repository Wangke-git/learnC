#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Game() {
	int num = 0;
	//猜数字游戏
	//1.系统随机生成一个数字，随机数1-100
	int toGuess = rand() % 100 + 1;
	//2.让用户输入一个整数
	while (1)
	{
		printf("请输入一个整数（1-100）：");
			scanf("%d", &num);
		if (num < toGuess)
		{
			printf("低了\n");
		}
		else if (num > toGuess)
		{
			printf("搞了\n");
		}
		else
		{
			printf("恭喜你猜对了！\n");
			break;
		}


	}
}
int Menu()
{
	printf("===================\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("===================\n");
	printf("请输入您的选择:");
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