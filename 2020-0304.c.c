#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	// UB ��Ӧ�Ŵ���Ĵ���
	//printf("%d\n", strlen(arr));		// δ������Ϊ(UB)
	//printf("%d\n", strlen(arr + 0));	// δ������Ϊ(UB)
	// ���ý���� 1 , ��1 , ���� 1 ��2 
	// *arr �õ����� char ����, strlen Ҫ��Ĳ����� char* ���͵�. 
	// printf("%d\n", strlen(*arr));	// ������밴��˵, ��Ҫ��������. ���� c �������͵ı������, �� char ��char* �͸���ʽת����
	// printf("%d\n", strlen(arr[1]));		// Ч��ͬ��

	// char arr[] = "abcdef";
	// printf("%d\n", sizeof(arr));		// 7 sizeof �����ڴ�Ĵ�С, �����СҪ���� \0
	// printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 => char*
	// printf("%d\n", sizeof(*arr));		// 1 *arr => char
	// printf("%d\n", sizeof(arr[1]));		// 1 arr[1] => char
	// printf("%d\n", sizeof(&arr));	// 4 &arr => char(*)[7]
	// printf("%d\n", sizeof(&arr + 1));	// 4 &arr + 1 => char(*)[7]
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] + 1 => char*

	// printf("%d\n", strlen(arr));	// 6 �˴��Ǽ����ַ�������, ���� \0
	// printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));	// UB *arr �õ��ַ�, char �� char* ���Ͳ�ƥ��. ����˵��Ҫ����ʧ�ܵ�
	//printf("%d\n", strlen(arr[1]));	// ͬ��
	// printf("%d\n", strlen(&arr));	// 6 &arr char(*)[7] ����. �� char* ���Ͳ�ƥ��, ����˵��Ҫ����ʧ�ܵ�
									// &arr ���ɺ� arr �õ��ĵ�ֵַ, ����ͬ��ֵ. �����������, �����ɺ�
	// printf("%d\n", strlen(&arr + 1));	// UB &arr + 1 ��������������, �����������Ŀռ�. �Ƿ��ڴ�
	// printf("%d\n", strlen(&arr[0] + 1));	// &arr[0] => char* char* + 1 ����һ��Ԫ��, һ��char

	// char* p = "abcdef";
	// printf("%d\n", sizeof(p));	// 4 p �� char* 
	// printf("%d\n", sizeof(p + 1));	// 4 p + 1 ���� char*
	// printf("%d\n", sizeof(*p));	// 1 *p char 
	// printf("%d\n", sizeof(p[1]));	// 1 p[1] char
	// printf("%d\n", sizeof(&p));	// 4 p char* , &p => char**
	// printf("%d\n", sizeof(&p + 1));	// ͬ��
	// printf("%d\n", sizeof(&p[0] + 1));	// 4 &p[0] �� char* �� + 1 ���� char*

	// printf("%d\n", strlen(p));	// 6 p ָ�����һ���ַ���
	// printf("%d\n", strlen(p + 1));	// 5 �� p + 1 ��λ�������� 5 ��Ԫ���ҵ� \0
	// printf("%d\n", strlen(*p));	// UB *p char  strlen Ҫ��Ĳ����� char* . ���Ͳ�ƥ��, ԭ����Ҫ����ʧ��
	// printf("%d\n", strlen(p[1]));	// UB ͬ��
	// printf("%d\n", strlen(&p));	// UB &p �õ� char** �� char* ������ͬ����. ԭ����Ҫ����ʧ��. ��ʱ �� char** ǿת�ɵ� char* ������һ�������ַ���
	// printf("%d\n", strlen(&p + 1));	// UB ͬ��
	// printf("%d\n", strlen(&p[0] + 1));	// 5 &p[0] �õ����� a �ĵ�ַ. + 1 �õ� b �ĵ�ַ. �� b ��ʼ������ 5 ��Ԫ���� \0

	// ���һ��  ��ά����
	// ��ν�Ķ�ά���� �����Ͼ���һ�� һά����. �����ÿ��Ԫ������һ��һά����
	// ����Ϊ 3 ��Ԫ�ص�һά����, �����ÿ��Ԫ�����ǳ���Ϊ 4 ��һά����
	int a[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	};
	// printf("%d\n", sizeof(a));	// 48   12 ��Ԫ��, ÿ��Ԫ�� 4 ���ֽ�
	// printf("%d\n", sizeof(a[0][0]));	// 4 a[0][0] => int
	// printf("%d\n", sizeof(a[0]));  // 16 a[0] => int[4] ����
	// printf("%d\n", sizeof(a[0] + 1));	// 4 a[0] => int[4] �� + 1 , ����ʽת��ָ�� int*
	// *(a[0]+1) => a[0][1] �ȼ� => 2
	// printf("%d\n", sizeof(   *  ( a[0] + 1 )  )    );	// 4 a[0] => int[4] �� + 1 , ��ʽת�� int*, �� * �õ� int
	// printf("%d\n", sizeof(&a[0] + 1));		//4  a[0] => int[4]    &a[0] => int(*)[4]  �� + 1 ��������ָ��  

	// printf("%d\n", sizeof(*(&a[0] + 1)));	// a[0] => int[4]  ��&�õ� int(*)[4] �� + 1�õ��Ļ��� int(*)[4], �ٽ����� int[4]
	// printf("%d\n", sizeof(*a)); // 16 *a => *(a + 0) => a[0] ��� int[4]

	// 16 => 3
	// δ������Ϊ => 4
	// ������벢����δ������Ϊ
	// ����˵���� "�����±�Խ��δ������Ϊ" ǰ�������� �ڴ����Խ��. ���ǳ�������ʱ����Ϊ
	// ������Ĵ���������֮��, �൱�ڱ�� 
	// printf("%d\n", 16); 
	// ���ǳ�������ʱ�������е��߼�
	printf("%d\n", sizeof(a[100])); // 16 sizeof ��һ�������(���Ǻ���), �ص���, ��������ֵ
	printf("%d\n", a[100]);




	// С����, ���� const ָ��
	//int num = 10;
	//int num2 = 0;
	//int* const p = &num;

	//*p = 20;	   // ����ܱ���ͨ�� ��3
	//// p = &num2;  // ����ܱ���ͨ�� ��4

	system("pause");
	return 0;
}