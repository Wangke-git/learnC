#include<stdio.h>
#include<stdlib.h>
//쳲�������(���������⣩
//�ݹ�
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
//�ǵݹ�
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
	int last1 = 1;//��ǰһ���ǰһ��
	int last2 = 1;//��ǰһ���ǰ����
	int cur = 0;
	for (int i = 3; i <= n; i++)
	{
		cur = last1 + last2;
		//�´�ѭ����ʱ�򣬵�ǰ���last1������һ���last2
		//��ǰ���cur������һ���last1
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