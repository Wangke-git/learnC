#include<stdio.h>
#include<stdlib.h>
int power(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	if (k == 1)
	{
		return n;
	}
	return n * power(n, k - 1);
}
int main13()
{
	printf("%d\n", power(5, 7));
	system("pause");
	return 0;
}