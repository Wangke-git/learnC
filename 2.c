#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main()
{
	char str1[] = "welcome to new world";
	char str2[] = "####################";
	int left = 0;
	int right = strlen(str1)-1;
	while (left <= right)
	{
		str2[left] = str1[left];
		str2[right] = str1[right];
		left += 1;
		right -= 1;
		system("cls");
		//cls:clear screen :cmd����
		printf("%s\n", str2);
		Sleep(500);
		//Sleep��ʾ˯�ߣ��������Cpu,��Ϣһ�ᡣsleepΪ����ϵͳ�ĺ���
	}

	system("pause");
	return 0;
}