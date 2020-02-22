#include<stdio.h>
#include<stdlib.h>
void PrintNum(unsigned int num)
{
	if (num > 9)
	{
		PrintNum(num / 10);
	}
	printf("%d \n", num % 10);
}
int main2()
{
	PrintNum(1234);
	system("pause");
	return 0;
}