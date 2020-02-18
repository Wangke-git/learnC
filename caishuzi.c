#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

int main()
{
	//输入一个密码
	for(int i=0;i<3;i++)
	{
		char password[1024] = { 0 };
		printf("请输入密码");
		scanf("%s", password);
		if (strcmp(password, "888888") == 0)  //字符串也能比较大小。strcmp是比较字符串大小：按照字典序
			//如果第一个字符串小于第二个返回<0整数   大于给返回>0的整数，相等返回0；
		{
			printf("登录成功!\n");
			break;
		}
		else
		{
			printf("您的输入有误，请重试!\n");
		}
	}
	printf("您已经输错三次");
	return 0;
	
}