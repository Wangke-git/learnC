#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main()
{
	//���ֲ���
	//����һ�����飬����ĳ�������Ƿ��������д���
	int arr[] = {1,2,3,4,5,6,7,8,9 };
	int toFind = 2;
	int i;
	//[left,right]����������
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < toFind)
		{
			//���ұ��ң�����left
			left = mid + 1;
		}
		else if(arr[mid]>toFind)
		{
			//������ң�����right
			right = mid - 1;
		}
		else
		{
			//�ҵ���
			printf("�ҵ���Ԫ�أ��±��ǣ�%d\n", mid);
			break;
		}
	}
	if (left > right) {
		printf("û�ҵ���\n");
	}
	system("pause");
	return 0;
}