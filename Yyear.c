#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main4()
{
	int n=0;
	int i ;
	printf("��������һ������");
	scanf("%d", &i);
	for (n = 2; n < i; n++)
	{
		if (i%n == 0)
		{
			printf("������������\n");
			break;
		}
		else
		{
			printf("����Ϊ����\n");
			break;
		}
	}

	
	system("pause");
	return 0;
}