#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
//人机对战
//控制台程序，用户输入坐标来落子
//1.x,表示玩家的棋子。o表示电脑棋子，电脑随机落子
//2.先表示棋盘，二位数组3行3列char数组 
//空格表示未落子位置，初始情况下二维数组全为空格
//3.先打印空棋盘
//4.约定玩家先落子，提示玩家落子，检查游戏是否结束
//5.电脑落子，检查游戏是否结束
//回到2继续执行
int Menu()
{
	printf("========================\n");
	printf("欢迎来到三子棋游戏！\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("========================\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MAX_ROW 3//棋盘的行
#define MAX_COL 3//棋盘的列
void Init(char chessBoard[MAX_ROW][MAX_COL])
{
	/*for(int row = 0; row < MAX_ROW; row++)
	{
		for (int col;col<MAX_COL;col++)
		{
			chessBoard[row][col] = ' ';
		}
	}*/
	srand(time(0));
	memset(chessBoard, ' ', MAX_ROW*MAX_COL);//将数组元素设为空格
}
void Print(char chessBoard[MAX_ROW][MAX_COL])
{
	//把棋盘内容打印出来

	for (int row=0;row<MAX_ROW;row++)
	{
		printf("+---+---+---+\n");
		printf("|%c  |%c  |%c  |\n", chessBoard[row][0],
			chessBoard[row][1], chessBoard[row][2]);
	}
	printf("+---+---+---+\n");
}
void Playermove(char chessBoard[MAX_ROW][MAX_COL])
{
	printf("轮到玩家落子!\n");
	while (1)
	{
		printf("请您输入您要落子的位置(row,col)");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 | col >= MAX_COL)
		{
			printf("您的输入有误!\n");
			continue;
		}
		if (chessBoard[row][col] != ' ')
		{
			//说明当前位置已经有子了,不能再重复落子
			printf("该位置已经有子了!\n");
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}
void  Computermove(char chessBoard[MAX_ROW][MAX_COL])
{
	printf("轮到电脑落子\n");
	while (1)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ')
		{
			continue;
		}
		chessBoard[row][col] = 'O';
		break;
	}
}
//判定棋盘是否满了,如果满了返回1,否则返回0
int IsFull(char chessBoard[MAX_ROW][MAX_COL])
{
	//查找一下棋盘是否与空位
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chessBoard[row][col] == ' ')
			{
				//找到空位了,棋盘没满
				return 0;
			}
		}
	}
	//所有位置都找完了,也没找到空格,最终返回1
	return 1;
}
//返回值表示游戏的状况
	//放回x表示玩家获胜
	//返回o表示电脑获胜
	//返回' '表示还未分出胜负
	//返回Q表示和棋
char Check(char chessBoard[MAX_ROW][MAX_COL])
{
	//1.检查所有的行,看是否有连成三个子的情况
	for (int row=0;row<MAX_ROW;row++)
	{
		if (chessBoard[row][0] != ' '
			&&chessBoard[row][0] == chessBoard[row][1] &&
			chessBoard[row][0] == chessBoard[row][2])
		{
			return chessBoard[row][0];
		}
	}
	//2.检查所有的列
	for (int col=0;col<MAX_COL;col++)
	{
		if (chessBoard[0][col] != ' '
			&&chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col])
		{
			return chessBoard[0][col];
		}

	}
	//3.检查对角线
	if (chessBoard[0][0]!=' '
		&&chessBoard[0][0]==chessBoard[1][1]
		&&chessBoard[0][0]==chessBoard[2][2])
	{
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&&chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0])
	{
		return chessBoard[0][2];
	}
	//4.判断是否和棋,棋盘满了,就是和棋
	if (IsFull(chessBoard))
	{
		return 'Q';
	}
	return ' ';
}
void Game()
{
	//一局游戏的核心函数
	//1.创建并初始化一个棋盘(字符类型的二维数组)
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(chessBoard);
	char winner = Check(chessBoard);
	while (1)
	{  
		//2.先打印棋盘
		Print(chessBoard);
		//3.提示玩家先落子(输入坐标)
		Playermove(chessBoard);
		//4.检查游戏是否结束
		winner = Check(chessBoard);
		if (winner!=' ')
		{
			break;
		}
		//5.电脑落子
		Computermove(chessBoard);
		//6.检查游戏是否结束
		winner = Check(chessBoard);
		if (winner!=' ')
		{
			break;
		}
	}
	if (winner == 'X')
	{
		printf("恭喜你,您赢了\n");
	}
	else if(winner=='o')
	{
		printf("你真菜,连电脑都下不过\n");
	}
	else
	{
		printf("你真菜,和电脑五五开!\n");
	}

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
		else if(choice==0)
		{
			printf("再见!\n");
			break;
		}
		else
		{
			printf("您的输入有误!\n");
		}
	}

	system("pause");
	return 0;
}