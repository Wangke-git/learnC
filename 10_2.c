#include<stdio.h>
#include<stdlib.h>
int main2()
{
	int tmp[4] = { 0 };

	int i;
	for (i = 0; i < 4; i++)
	{
		tmp[i] = 1;        //�ȼ���A������
		if ((tmp[0] != 1) + (tmp[2] == 1) +
			(tmp[3] == 1) + (tmp[3] != 1) == 3)
		{
			printf("%c������\n", 'A' + i);
		}
		tmp[i] = 0;      //���������������ôA��������,��ʼ����B������
	}
	system("pause");
	return 0;
}