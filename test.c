
#include<stdio.h>
#include<stdlib.h>
void swap(int* x, int* y)
{
	int tmp = *x;              //创建临时变量
	*x = *y;
	*y = tmp;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 5,4,3,2,1 };
	int sz = sizeof(a) / sizeof(a[0]);      //求数组中含有几个字符
	for (int i = 0; i < sz; i++)
	{
		swap(&a[i], &b[i]);//交换数组中的元素
	}

	printf("交换后数组a的值：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("交换后数组b的值：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}