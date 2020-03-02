#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintArr(int arr[3][4]) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
}

// ���麯�����ε�ʱ�����ʽת��ָ��. ���ָ�����ָ����Ԫ�ص�ָ��
// ��ǰ������һ����ά����, ��Ԫ����һ�� int[4]
// ��Ԫ�ص�ָ�� ����һ�� int(*)[4]  Ҳ��������ָ��
void PrintArr2(int(*p)[4]) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			printf("%d ", p[row][col]);
		}
		printf("\n");
	}
}

void test2(int num) {

}

int test() {
	printf("ִ�� test\n");
	return 100;
}

int Add(int x, int y) {
	return x + y;
}

int Sub(int x, int y) {
	return x - y;
}

int Mul(int x, int y) {
	return x * y;
}

int Div(int x, int y) {
	return x / y;
}

typedef int(*Cmp)(int, int);

// ð������(����)
// ��� isAsc Ϊ 1 ��ʾ��������, Ϊ 0 ��ʾ��������
// cmp �����˱ȽϹ���
// ��������������Ļ�, 
// ��� ��һ������ С�ڵڶ�������, �ͷ��� 1, ���򷵻� 0
void BubbleSort(int arr[], int size, Cmp cmp) {
	int bound = 0;
	// [0, bound) ����������
	// [bound, size) ����������
	// ��ʼ�����, �����������ǿ�����
	// ÿѭ��һ��, �ҵ�һ����Сֵ�ŵ�ǰ��ȥ, Ҳ�����������������һ��Ԫ��, ��������������һ��Ԫ��
	// ֱ���������鶼�������������, ���������
	for (; bound < size; bound++) {
		int cur = size - 1;
		for (; cur > bound; cur--) {
			if (cmp(arr[cur - 1], arr[cur]) == 0) {
				// ���ǰһ��Ԫ�غͺ�һ��Ԫ�ص����λ�ò���������Ҫ��, �ͽ���
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

int Less(int x, int y) {
	return x < y ? 1 : 0;
}

int Greater(int x, int y) {
	return x > y ? 1 : 0;
}

int main() {
	// int arr[10] = { 0 };
	// %p ������ӡָ�������(��ӡ����һ����ַ)
	// ָ�� + 1 ��ַ����һ��Ԫ��. (ȡ���� Ԫ�ص� sizeof)
	//printf("%p\n", arr); // arr ��ʽת��ָ����. ָ����Ԫ�ص�ָ��. int*
	//printf("%p\n", arr + 1);
	//printf("%p\n", &arr);// &arr ֱ�Ӷ�������ȡ��ַ, �õ�����һ��ָ����������ָ��, "����ָ��", int(*)[10]
	//printf("%p\n", &arr + 1);

	// ������ p ����ָ��  arr �������. ��ʱ p Ҳ������ָ��
	// int(*p)[10] = &arr;



	// ����ָ����ʵ�ʿ������������ʹ����?
	// ʹ�ó����ǳ���, ��ά���鴫�ε�ʱ������õ�
	// ����Ϊ 3 ��һά����, ÿ��Ԫ�س���Ϊ 4  ��1  [��ȷ]
	// ����Ϊ 4 ��һά����, ÿ��Ԫ�س���Ϊ 3  ��2
	// int arr[3][4] = { 0 };
	// PrintArr(arr);
	// PrintArr2(arr);


	//int arr[5];   // ��ͨ����
	//int* arr2[5]; // ָ������
	//int(*p)[10];  // ����ָ��

	//// �������һ����ѧ�����, �﷨������, �������Ƿǳ����Ĵ���
	//int((*p2)[10])[5]; // ����Ϊ 10 ��Ԫ�ص�ָ������,
	//				   // �����ÿ��Ԫ��, ����һ������ָ��, �������ָ��ָ�򳤶�Ϊ 5 ��Ԫ�ص� int ����

	//int* arr2[20];
	//// �����ÿ��Ԫ���� һ�� int*
	//// ���鴫�λ���ʽת��ָ��, ָ����Ԫ�ص�ָ��
	//// int**
	//test2(arr2);


	// ����ָ��
	// ֻ�к�����, ûд����, �����Ǻ�������, ��ʱ���ǻ�ȡ�� test ������Ӧ�ĺ���ָ��
	// ���������д���ǵȼ�
	//printf("%p\n", test);
	//printf("%p\n", &test);

	// p ��������һ������ָ��, ������ int(*)()
	// �������д���Ƚϱ�Ť, ����ʹ�� typedef ���򻯴���
	// ��ʱ�͸� int(*)() ���ʹ����˱��� Func1
	//typedef int(*Func1)();
	//// int(*p)() = test;
	//Func1 p = test;
	//// ʹ�ú���ָ����ú�����ʱ��, �����Ƚ������ٵ���, Ҳ����ֱ�ӵ���, Ч���ȼ�
	//// (*p)();
	//p();

	//typedef void(*Func2)(int);
	////void(*p2)(int) = test2;
	//Func2 p2 = test2;

	// ����Ƥ???? ���� Linux �ں��е�һ�δ���
	// (   *(void(*)())0   )     ();

	//printf("������������㷽ʽ: \n");
	//printf("1. + \n");
	//printf("2. - \n");
	//printf("3. * \n");
	//printf("4. / \n");
	//int choice = 0;
	//scanf("%d", &choice);

	//int ret = 0;
	// �˴��Ĵ���, if else ̫����~~
	//if (choice == 1) {
	//	ret = Add(10, 20);
	//} else if (choice == 2) {
	//	ret = Sub(10, 20);
	//} else if (choice == 3) {
	//	ret = Mul(10, 20);
	//} else if (choice == 4) {
	//	ret = Div(10, 20);
	//}
	
	// ת�Ʊ�ķ�ʽ������������
	// ת�Ʊ����һ������ָ������. 
	//typedef int(*Func)(int, int);
	//Func table[] = {
	//	Add,
	//	Sub,
	//	Mul,
	//	Div
	//};
	//ret = table[choice - 1](10, 20);
	//printf("ret = %d\n", ret);


	//int arr[4] = { 9, 5, 2, 7 };
	//BubbleSort(arr, 4, Less);
	//for (int i = 0; i < 4; i++) {
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	// ����������������(32λϵͳΪ��)

	// ��һ��
	// int arr[] = { 1, 2, 3, 4 };
	// printf("%d\n", sizeof(arr)); // 16
	// printf("%d\n", sizeof(arr + 0)); // 4 int* arr �Ѿ���ʽת��ָ��
	// printf("%d\n", sizeof(*arr));	// 4 arr �Ѿ���ʽת�� int* �ٽ�����, �õ� int
	// printf("%d\n", sizeof(arr + 1));	// 4 arr �Ѿ���ʽת�� int* 
	// printf("%d\n", sizeof(arr[1]));		// 4 int
	// printf("%d\n", sizeof(&arr));		// 4 &arr ��һ�� int(*)[4], ֻҪ��ָ��, 32λϵͳ�¶��� 4 �ֽ�
	// printf("%d\n", sizeof(*&arr));		// 16 &arr ������ָ��. �ٴ� * �������ַ��ʼȡ int(*)[4] ���Ͷ�Ӧ���ֽ���
	// printf("%d\n", sizeof(&arr + 1));	// 4 &arr �õ�һ�� int(*)[4] �� + 1 ���� int(*)[4], ֻҪ��ָ��, ���� 4 ���ֽ�
	// printf("%d\n", sizeof(&arr[0]));		// 4 �õ� int*
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 ͬ��

	// �ڶ���
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// ����� 6 �� 6
	// ����� 7 �� 7
	// ����ֵ �۶�Ӧ��ֵ
	// printf("%d\n", sizeof(arr));		// 6 arr ����һ����ͨ���ַ�����, ��Ҫ��̫��
	// printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 �õ�һ�� char*, ֻҪ��ָ�����, ����ռ 4 ���ֽ�
	// printf("%d\n", sizeof(*arr));		// 1 *arr �õ�һ�� char , ����ռһ���ֽ�
	// printf("%d\n", sizeof(arr[1]));		// 1 arr[1] �õ���һ��char, ����ռһ���ֽ�
	// printf("%d\n", sizeof(&arr));		// 4 &arr �õ�һ������ָ�� char(*)[6], ֻҪ��ָ��, ���� 4 ���ֽ�
	// printf("%d\n", sizeof(&arr + 1));	// 4 ͬ��
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] �õ� char*, + 1 ���� char*

	// 6 �� 6
	// 7 �� 7
	// ����ֵ �����������ֵ
	printf("%d\n", strlen(arr));

	system("pause");
	return 0;
}