#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main()
{
	//二分查找
	//给定一个数组，查找某个数字是否在数组中存在
	int arr[] = {1,2,3,4,5,6,7,8,9 };
	int toFind = 2;
	int i;
	//[left,right]待查找区间
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < toFind)
		{
			//在右边找，更新left
			left = mid + 1;
		}
		else if(arr[mid]>toFind)
		{
			//在左边找，更新right
			right = mid - 1;
		}
		else
		{
			//找到了
			printf("找到该元素，下标是：%d\n", mid);
			break;
		}
	}
	if (left > right) {
		printf("没找到！\n");
	}
	system("pause");
	return 0;
}