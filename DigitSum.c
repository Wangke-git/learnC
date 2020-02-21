#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	if (n < 10)
	{
		return n;
	}
	return n % 10 + DigitSum(n / 10);
}
int main23()
{
	printf("%d\n", DigitSum(1729));
	system("pause");
	return 0;
}