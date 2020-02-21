#include<stdio.h>
#include<stdlib.h>
//斐波那契数(生兔子问题）
//递归
//int Feb(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	if (n == 2)
//	{
//		return 1;
//	}
//	return Feb(n - 1) + Feb(n - 2);
//}
//非递归
int Feb(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 1;
	}
	int last1 = 1;//当前一项的前一项
	int last2 = 1;//当前一项的前俩项
	int cur = 0;
	for (int i = 3; i <= n; i++)
	{
		cur = last1 + last2;
		//下次循环的时候，当前项的last1就是下一项的last2
		//当前项的cur就是下一项的last1
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int main7()
{
	printf("%d\n", Feb(7));
	system("pause");
	return 0;
}