#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void print()
{
	int i, j, k;
	printf("请您输入你要输入的数：");
	scanf("%d", &k);
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <=k; j++)
		{
			printf("%d*%d=%d ", i, j, i*j);
		}
		printf("\n");
	}
}
int main1()
{
	print();
	system("pause");
	return 0;
}