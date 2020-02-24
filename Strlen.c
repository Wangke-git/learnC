#include<stdio.h>
#include<stdlib.h>
//非递归
//int strlen(char str[]) 
//{
//	int i = 0;
//	while (str[i] != 0)
//	{
//		i++;
//	}
//	return i;
//}
//递归
int Strlen(char str[])
{
	if (str[0] == '\0')  //空字符串
	{
		return 0;
	}
	return 1 + Strlen(str + 1);//str+1跳过一个字符指向下一个字符
}
int main5()
{
	char str[] = "hehe";
	int len = Strlen(str);
	printf("%d\n", len);
	
	system("pause");
	return 0;
}