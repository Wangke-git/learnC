#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int  Strlen(const char* str)
{
	int size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return size;
}
char* Strcpy(char* str, const char* res)
{
	//参数合法性校验，这里的检验性连胜于无，并不能根本上解性问题
	if (str == NULL || res == NULL)
	{
		return NULL;
	}
	// ASSERT(str != NULL && res != NULL);//assert叫做“断言”（）里的程序必须成立，否则程序就直接崩溃
	//后面的代码中修改了str的指向。希望返回值是最初的str
	//实现方式1
	/*char* result = str;
	while (*res!='\0')
	{
		*str = *res;
		res++;
		str++;
	}
	*str = '\0';
	return result;*/
	//实现方式2
	int cur = 0;
	while (res[cur]!='\0')
	{
		str[cur] = res[cur];
		cur++;
	}
	str[cur] = '\0';
	return str;

}
char* Strcat(char* str, const char* res)
{
	if (str == NULL || res == NULL)
	{
		return NULL;
	}
	//1.先找到str的结束位置
	int cur = 0;
	while (str[cur] != '\0')
	{
		cur++;
	}
	//循环结束之后，cur下标就为\0
	//2.再把res往str的结束位置进行拷贝
	int i = 0;
	while (res[i] != '\0')
	{
		str[cur + i] = res[i];
		i++;
	}
	//最后设置\0千万不要遗漏
	str[cur + i] = '\0';
	return str;
}

int main()
{
	/*char* str = "asdasdasds";
	int len=Strlen(str);
	printf("%d\n", len);*/
	/*char str[10]={0 };
	Strcpy(str, "haha");
	printf("%s\n", str);*/
	char str1[100] = "haha";
	char str2 [100]= "hehe";
	Strcat(str1, str2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}