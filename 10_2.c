#include<stdio.h>
#include<stdlib.h>
int main2()
{
	int tmp[4] = { 0 };

	int i;
	for (i = 0; i < 4; i++)
	{
		tmp[i] = 1;        //先假设A是凶手
		if ((tmp[0] != 1) + (tmp[2] == 1) +
			(tmp[3] == 1) + (tmp[3] != 1) == 3)
		{
			printf("%c是凶手\n", 'A' + i);
		}
		tmp[i] = 0;      //如果条件不成立那么A不是凶手,开始假设B是凶手
	}
	system("pause");
	return 0;
}