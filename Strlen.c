#include<stdio.h>
#include<stdlib.h>
//�ǵݹ�
//int strlen(char str[]) 
//{
//	int i = 0;
//	while (str[i] != 0)
//	{
//		i++;
//	}
//	return i;
//}
//�ݹ�
int Strlen(char str[])
{
	if (str[0] == '\0')  //���ַ���
	{
		return 0;
	}
	return 1 + Strlen(str + 1);//str+1����һ���ַ�ָ����һ���ַ�
}
int main5()
{
	char str[] = "hehe";
	int len = Strlen(str);
	printf("%d\n", len);
	
	system("pause");
	return 0;
}