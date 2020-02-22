#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
//�˻���ս
//����̨�����û���������������
//1.x,��ʾ��ҵ����ӡ�o��ʾ�������ӣ������������
//2.�ȱ�ʾ���̣���λ����3��3��char���� 
//�ո��ʾδ����λ�ã���ʼ����¶�ά����ȫΪ�ո�
//3.�ȴ�ӡ������
//4.Լ����������ӣ���ʾ������ӣ������Ϸ�Ƿ����
//5.�������ӣ������Ϸ�Ƿ����
//�ص�2����ִ��
int Menu()
{
	printf("========================\n");
	printf("��ӭ������������Ϸ��\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("========================\n");
	printf("����������ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MAX_ROW 3//���̵���
#define MAX_COL 3//���̵���
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
	memset(chessBoard, ' ', MAX_ROW*MAX_COL);//������Ԫ����Ϊ�ո�
}
void Print(char chessBoard[MAX_ROW][MAX_COL])
{
	//���������ݴ�ӡ����

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
	printf("�ֵ��������!\n");
	while (1)
	{
		printf("����������Ҫ���ӵ�λ��(row,col)");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 | col >= MAX_COL)
		{
			printf("������������!\n");
			continue;
		}
		if (chessBoard[row][col] != ' ')
		{
			//˵����ǰλ���Ѿ�������,�������ظ�����
			printf("��λ���Ѿ�������!\n");
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}
void  Computermove(char chessBoard[MAX_ROW][MAX_COL])
{
	printf("�ֵ���������\n");
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
//�ж������Ƿ�����,������˷���1,���򷵻�0
int IsFull(char chessBoard[MAX_ROW][MAX_COL])
{
	//����һ�������Ƿ����λ
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chessBoard[row][col] == ' ')
			{
				//�ҵ���λ��,����û��
				return 0;
			}
		}
	}
	//����λ�ö�������,Ҳû�ҵ��ո�,���շ���1
	return 1;
}
//����ֵ��ʾ��Ϸ��״��
	//�Ż�x��ʾ��һ�ʤ
	//����o��ʾ���Ի�ʤ
	//����' '��ʾ��δ�ֳ�ʤ��
	//����Q��ʾ����
char Check(char chessBoard[MAX_ROW][MAX_COL])
{
	//1.������е���,���Ƿ������������ӵ����
	for (int row=0;row<MAX_ROW;row++)
	{
		if (chessBoard[row][0] != ' '
			&&chessBoard[row][0] == chessBoard[row][1] &&
			chessBoard[row][0] == chessBoard[row][2])
		{
			return chessBoard[row][0];
		}
	}
	//2.������е���
	for (int col=0;col<MAX_COL;col++)
	{
		if (chessBoard[0][col] != ' '
			&&chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col])
		{
			return chessBoard[0][col];
		}

	}
	//3.���Խ���
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
	//4.�ж��Ƿ����,��������,���Ǻ���
	if (IsFull(chessBoard))
	{
		return 'Q';
	}
	return ' ';
}
void Game()
{
	//һ����Ϸ�ĺ��ĺ���
	//1.��������ʼ��һ������(�ַ����͵Ķ�ά����)
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(chessBoard);
	char winner = Check(chessBoard);
	while (1)
	{  
		//2.�ȴ�ӡ����
		Print(chessBoard);
		//3.��ʾ���������(��������)
		Playermove(chessBoard);
		//4.�����Ϸ�Ƿ����
		winner = Check(chessBoard);
		if (winner!=' ')
		{
			break;
		}
		//5.��������
		Computermove(chessBoard);
		//6.�����Ϸ�Ƿ����
		winner = Check(chessBoard);
		if (winner!=' ')
		{
			break;
		}
	}
	if (winner == 'X')
	{
		printf("��ϲ��,��Ӯ��\n");
	}
	else if(winner=='o')
	{
		printf("�����,�����Զ��²���\n");
	}
	else
	{
		printf("�����,�͵������忪!\n");
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
			printf("�ټ�!\n");
			break;
		}
		else
		{
			printf("������������!\n");
		}
	}

	system("pause");
	return 0;
}