#include<stdio.h>
#include<stdlib.h>
//int Factor(int n)
//{
//	int res = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		res = *i;
//	}
//	return res;
//}
//ตÝน้
//n!=>n*n-1
//n==1 1!=>1
int Factor(int n)
{
	if (n ==1) {
		return 1;
	}
	return n *=Factor (n - 1);
}
int main6()
{
	printf("%d\n", Factor(5));
	system("pause");
	return 0;
}