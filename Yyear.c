#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main4()
{
	int n=0;
	int i ;
	printf("请您输入一个数：");
	scanf("%d", &i);
	for (n = 2; n < i; n++)
	{
		if (i%n == 0)
		{
			printf("该数不是素数\n");
			break;
		}
		else
		{
			printf("该数为素数\n");
			break;
		}
	}

	
	system("pause");
	return 0;
}