#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	// UB 对应着错误的代码
	//printf("%d\n", strlen(arr));		// 未定义行为(UB)
	//printf("%d\n", strlen(arr + 0));	// 未定义行为(UB)
	// 觉得结果是 1 , 扣1 , 不是 1 扣2 
	// *arr 得到的是 char 类型, strlen 要求的参数是 char* 类型的. 
	// printf("%d\n", strlen(*arr));	// 这个代码按理说, 是要编译出错的. 但是 c 是弱类型的编程语言, 把 char 和char* 就给隐式转换了
	// printf("%d\n", strlen(arr[1]));		// 效果同上

	// char arr[] = "abcdef";
	// printf("%d\n", sizeof(arr));		// 7 sizeof 是求内存的大小, 这个大小要包含 \0
	// printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 => char*
	// printf("%d\n", sizeof(*arr));		// 1 *arr => char
	// printf("%d\n", sizeof(arr[1]));		// 1 arr[1] => char
	// printf("%d\n", sizeof(&arr));	// 4 &arr => char(*)[7]
	// printf("%d\n", sizeof(&arr + 1));	// 4 &arr + 1 => char(*)[7]
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] + 1 => char*

	// printf("%d\n", strlen(arr));	// 6 此处是计算字符串长度, 不算 \0
	// printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));	// UB *arr 得到字符, char 和 char* 类型不匹配. 按理说是要编译失败的
	//printf("%d\n", strlen(arr[1]));	// 同上
	// printf("%d\n", strlen(&arr));	// 6 &arr char(*)[7] 类型. 和 char* 类型不匹配, 按理说是要编译失败的
									// &arr 碰巧和 arr 得到的地址值, 是相同的值. 这个结果能算对, 纯属巧合
	// printf("%d\n", strlen(&arr + 1));	// UB &arr + 1 跳过了整个数组, 访问数组后面的空间. 非法内存
	// printf("%d\n", strlen(&arr[0] + 1));	// &arr[0] => char* char* + 1 跳过一个元素, 一个char

	// char* p = "abcdef";
	// printf("%d\n", sizeof(p));	// 4 p 是 char* 
	// printf("%d\n", sizeof(p + 1));	// 4 p + 1 还是 char*
	// printf("%d\n", sizeof(*p));	// 1 *p char 
	// printf("%d\n", sizeof(p[1]));	// 1 p[1] char
	// printf("%d\n", sizeof(&p));	// 4 p char* , &p => char**
	// printf("%d\n", sizeof(&p + 1));	// 同上
	// printf("%d\n", sizeof(&p[0] + 1));	// 4 &p[0] 是 char* 再 + 1 还是 char*

	// printf("%d\n", strlen(p));	// 6 p 指向的是一个字符串
	// printf("%d\n", strlen(p + 1));	// 5 从 p + 1 的位置往后找 5 个元素找到 \0
	// printf("%d\n", strlen(*p));	// UB *p char  strlen 要求的参数是 char* . 类型不匹配, 原则上要编译失败
	// printf("%d\n", strlen(p[1]));	// UB 同上
	// printf("%d\n", strlen(&p));	// UB &p 得到 char** 和 char* 不是相同类型. 原则上要编译失败. 此时 把 char** 强转成的 char* 并不是一个真正字符串
	// printf("%d\n", strlen(&p + 1));	// UB 同上
	// printf("%d\n", strlen(&p[0] + 1));	// 5 &p[0] 得到的是 a 的地址. + 1 得到 b 的地址. 从 b 开始往后找 5 个元素是 \0

	// 最后一组  二维数组
	// 所谓的二维数组 本质上就是一个 一维数组. 里面的每个元素又是一个一维数组
	// 长度为 3 个元素的一维数组, 里面的每个元素又是长度为 4 的一维数组
	int a[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	};
	// printf("%d\n", sizeof(a));	// 48   12 个元素, 每个元素 4 个字节
	// printf("%d\n", sizeof(a[0][0]));	// 4 a[0][0] => int
	// printf("%d\n", sizeof(a[0]));  // 16 a[0] => int[4] 类型
	// printf("%d\n", sizeof(a[0] + 1));	// 4 a[0] => int[4] 再 + 1 , 就隐式转成指针 int*
	// *(a[0]+1) => a[0][1] 等价 => 2
	// printf("%d\n", sizeof(   *  ( a[0] + 1 )  )    );	// 4 a[0] => int[4] 再 + 1 , 隐式转成 int*, 再 * 得到 int
	// printf("%d\n", sizeof(&a[0] + 1));		//4  a[0] => int[4]    &a[0] => int(*)[4]  再 + 1 还是数组指针  

	// printf("%d\n", sizeof(*(&a[0] + 1)));	// a[0] => int[4]  再&得到 int(*)[4] 再 + 1得到的还是 int(*)[4], 再解引用 int[4]
	// printf("%d\n", sizeof(*a)); // 16 *a => *(a + 0) => a[0] 结果 int[4]

	// 16 => 3
	// 未定义行为 => 4
	// 这个代码并不是未定义行为
	// 曾经说过的 "数组下标越界未定义行为" 前提条件是 内存访问越界. 这是程序运行时的行为
	// 当下面的代码编译结束之后, 相当于变成 
	// printf("%d\n", 16); 
	// 这是程序运行时真正进行的逻辑
	printf("%d\n", sizeof(a[100])); // 16 sizeof 是一个运算符(不是函数), 特点是, 编译期求值
	printf("%d\n", a[100]);




	// 小插曲, 关于 const 指针
	//int num = 10;
	//int num2 = 0;
	//int* const p = &num;

	//*p = 20;	   // 这个能编译通过 扣3
	//// p = &num2;  // 这个能编译通过 扣4

	system("pause");
	return 0;
}