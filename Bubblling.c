#include<stdio.h>
#include <stdlib.h>
//从0号元素出发，比较相邻俩个元素的大小，是否符合升序，如果不符合交换
//数组排序
//冒泡排序
int bubblesort(int arr[], int size)
{
	//以每次找最小为例，
	//[0,bound)已排序区间[bound,size)待排序区间
	//每次找一个最小值放到前边，也就意味着已排序区间多一个元素
	//待排序就少一个元素
	for (int bound = 0; bound < size; bound++)
	{
		//h还需要一重循环
		//这个循环负责找到当前待排序区间中的最小值，并放到bound位置
		for (int cur=size-1;cur>bound;cur--)
		{
			//比较相邻元素，如果不符合升序，交换俩个元素
			if (arr[cur - 1] > arr[cur])         //如果是降序，将>改成<即可
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