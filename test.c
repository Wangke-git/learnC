
#include<stdio.h>
#include<stdlib.h>
void swap(int* x, int* y)
{
	int tmp = *x;              //������ʱ����
	*x = *y;
	*y = tmp;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 5,4,3,2,1 };
	int sz = sizeof(a) / sizeof(a[0]);      //�������к��м����ַ�
	for (int i = 0; i < sz; i++)
	{
		swap(&a[i], &b[i]);//���������е�Ԫ��
	}

	printf("����������a��ֵ��");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("����������b��ֵ��");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}