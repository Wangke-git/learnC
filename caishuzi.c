#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

int main()
{
	//����һ������
	for(int i=0;i<3;i++)
	{
		char password[1024] = { 0 };
		printf("����������");
		scanf("%s", password);
		if (strcmp(password, "888888") == 0)  //�ַ���Ҳ�ܱȽϴ�С��strcmp�ǱȽ��ַ�����С�������ֵ���
			//�����һ���ַ���С�ڵڶ�������<0����   ���ڸ�����>0����������ȷ���0��
		{
			printf("��¼�ɹ�!\n");
			break;
		}
		else
		{
			printf("������������������!\n");
		}
	}
	printf("���Ѿ��������");
	return 0;
	
}