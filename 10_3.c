#include<stdio.h>
#include<stdlib.h>
void printYH(int n)
{
	int form[20][20] = { 0 };
	for (int i = 0; i < n; i++)
	{
		form[i][0] = 1;//ֱ�Ӹ���i�е�һ����ֵΪ1
		for (int j = 1; j <= i; j++)
		{
			form[i][j] = form[i - 1][j] + form[i - 1][j - 1];
		}
	}
	//��ӡѭ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", form[i][j]);
		}
		putchar('\n');
	}

}
int main()
{
	printYH(10);
	system("pause");
	return 0;
}
