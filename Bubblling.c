#include<stdio.h>
#include <stdlib.h>
//��0��Ԫ�س������Ƚ���������Ԫ�صĴ�С���Ƿ����������������Ͻ���
//��������
//ð������
int bubblesort(int arr[], int size)
{
	//��ÿ������СΪ����
	//[0,bound)����������[bound,size)����������
	//ÿ����һ����Сֵ�ŵ�ǰ�ߣ�Ҳ����ζ�������������һ��Ԫ��
	//���������һ��Ԫ��
	for (int bound = 0; bound < size; bound++)
	{
		//h����Ҫһ��ѭ��
		//���ѭ�������ҵ���ǰ�����������е���Сֵ�����ŵ�boundλ��
		for (int cur=size-1;cur>bound;cur--)
		{
			//�Ƚ�����Ԫ�أ�������������򣬽�������Ԫ��
			if (arr[cur - 1] > arr[cur])         //����ǽ��򣬽�>�ĳ�<����
			{
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}
int main()
{
	int arr[4] = { 9,5,2,7 };
	bubblesort(arr, 4);
	for (int i=0;i<4;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}