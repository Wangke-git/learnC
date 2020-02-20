#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main3() {
	char ch;
	while (1) {
		printf("ÇëÊäÈëÒ»¸ö×Ö·û£º\n");
		ch = getchar();
		getchar();
		if (ch >= 'a'&&ch <= 'z') {
			printf("%c\n", ch - 32);
		}
		else if (ch >= 'A'&&ch <= 'Z') {
			printf("%c\n", ch + 32);
		}
		else if (ch >= '0'&&ch <= '9') {
			;
		}
	}
	system("pause");
	return 0;
}
