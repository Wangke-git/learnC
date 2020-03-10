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
	//�����Ϸ���У�飬����ļ�������ʤ���ޣ������ܸ����Ͻ�������
	if (str == NULL || res == NULL)
	{
		return NULL;
	}
	// ASSERT(str != NULL && res != NULL);//assert���������ԡ�������ĳ�������������������ֱ�ӱ���
	//����Ĵ������޸���str��ָ��ϣ������ֵ�������str
	//ʵ�ַ�ʽ1
	/*char* result = str;
	while (*res!='\0')
	{
		*str = *res;
		res++;
		str++;
	}
	*str = '\0';
	return result;*/
	//ʵ�ַ�ʽ2
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
	//1.���ҵ�str�Ľ���λ��
	int cur = 0;
	while (str[cur] != '\0')
	{
		cur++;
	}
	//ѭ������֮��cur�±��Ϊ\0
	//2.�ٰ�res��str�Ľ���λ�ý��п���
	int i = 0;
	while (res[i] != '\0')
	{
		str[cur + i] = res[i];
		i++;
	}
	//�������\0ǧ��Ҫ��©
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