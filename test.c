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

// 数组函数传参的时候会隐式转成指针. 这个指针就是指向首元素的指针
// 当前参数是一个二维数组, 首元素是一个 int[4]
// 首元素的指针 就是一个 int(*)[4]  也就是数组指针
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
	printf("执行 test\n");
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

// 冒泡排序(升序)
// 如果 isAsc 为 1 表示升序排序, 为 0 表示降序排序
// cmp 描述了比较规则
// 例如是升序排序的话, 
// 如果 第一个参数 小于第二个参数, 就返回 1, 否则返回 0
void BubbleSort(int arr[], int size, Cmp cmp) {
	int bound = 0;
	// [0, bound) 已排序区间
	// [bound, size) 待排序区间
	// 初始情况下, 已排序区间是空区间
	// 每循环一次, 找到一个最小值放到前面去, 也就让已排序区间多了一个元素, 待排序区间少了一个元素
	// 直到整个数组都变成已排序区间, 就排序完成
	for (; bound < size; bound++) {
		int cur = size - 1;
		for (; cur > bound; cur--) {
			if (cmp(arr[cur - 1], arr[cur]) == 0) {
				// 如果前一个元素和后一个元素的相对位置不符合排序要求, 就交换
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
	// %p 用来打印指针变量的(打印的是一个地址)
	// 指针 + 1 地址跳过一个元素. (取决于 元素的 sizeof)
	//printf("%p\n", arr); // arr 隐式转成指针了. 指向首元素的指针. int*
	//printf("%p\n", arr + 1);
	//printf("%p\n", &arr);// &arr 直接对数组名取地址, 得到的是一个指向这个数组的指针, "数组指针", int(*)[10]
	//printf("%p\n", &arr + 1);

	// 创建了 p 变量指向  arr 这个数组. 此时 p 也是数组指针
	// int(*p)[10] = &arr;



	// 数组指针在实际开发中在哪里会使用呢?
	// 使用场景非常少, 二维数组传参的时候可以用到
	// 长度为 3 的一维数组, 每个元素长度为 4  扣1  [正确]
	// 长度为 4 的一维数组, 每个元素长度为 3  扣2
	// int arr[3][4] = { 0 };
	// PrintArr(arr);
	// PrintArr2(arr);


	//int arr[5];   // 普通数组
	//int* arr2[5]; // 指针数组
	//int(*p)[10];  // 数组指针

	//// 这绝不是一个科学的情况, 语法上允许, 但是这是非常糟糕的代码
	//int((*p2)[10])[5]; // 长度为 10 个元素的指针数组,
	//				   // 里面的每个元素, 都是一个数组指针, 这个数组指针指向长度为 5 个元素的 int 数组

	//int* arr2[20];
	//// 数组的每个元素是 一个 int*
	//// 数组传参会隐式转成指针, 指向首元素的指针
	//// int**
	//test2(arr2);


	// 函数指针
	// 只有函数名, 没写括号, 并不是函数调用, 此时就是获取到 test 函数对应的函数指针
	// 下面的两种写法是等价
	//printf("%p\n", test);
	//printf("%p\n", &test);

	// p 变量就是一个函数指针, 类型是 int(*)()
	// 像下面的写法比较别扭, 可以使用 typedef 来简化代码
	// 此时就给 int(*)() 类型创建了别名 Func1
	//typedef int(*Func1)();
	//// int(*p)() = test;
	//Func1 p = test;
	//// 使用函数指针调用函数的时候, 可以先解引用再调用, 也可以直接调用, 效果等价
	//// (*p)();
	//p();

	//typedef void(*Func2)(int);
	////void(*p2)(int) = test2;
	//Func2 p2 = test2;

	// 玩蛇皮???? 早期 Linux 内核中的一段代码
	// (   *(void(*)())0   )     ();

	//printf("请输入你的运算方式: \n");
	//printf("1. + \n");
	//printf("2. - \n");
	//printf("3. * \n");
	//printf("4. / \n");
	//int choice = 0;
	//scanf("%d", &choice);

	//int ret = 0;
	// 此处的代码, if else 太多啦~~
	//if (choice == 1) {
	//	ret = Add(10, 20);
	//} else if (choice == 2) {
	//	ret = Sub(10, 20);
	//} else if (choice == 3) {
	//	ret = Mul(10, 20);
	//} else if (choice == 4) {
	//	ret = Div(10, 20);
	//}
	
	// 转移表的方式来解决这个问题
	// 转移表就是一个函数指针数组. 
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

	// 常见笔试题面试题(32位系统为例)

	// 第一组
	// int arr[] = { 1, 2, 3, 4 };
	// printf("%d\n", sizeof(arr)); // 16
	// printf("%d\n", sizeof(arr + 0)); // 4 int* arr 已经隐式转成指针
	// printf("%d\n", sizeof(*arr));	// 4 arr 已经隐式转成 int* 再解引用, 得到 int
	// printf("%d\n", sizeof(arr + 1));	// 4 arr 已经隐式转成 int* 
	// printf("%d\n", sizeof(arr[1]));		// 4 int
	// printf("%d\n", sizeof(&arr));		// 4 &arr 是一个 int(*)[4], 只要是指针, 32位系统下都是 4 字节
	// printf("%d\n", sizeof(*&arr));		// 16 &arr 是数组指针. 再次 * 从这个地址开始取 int(*)[4] 类型对应的字节数
	// printf("%d\n", sizeof(&arr + 1));	// 4 &arr 得到一个 int(*)[4] 再 + 1 还是 int(*)[4], 只要是指针, 就是 4 个字节
	// printf("%d\n", sizeof(&arr[0]));		// 4 得到 int*
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 同上

	// 第二组
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// 结果是 6 扣 6
	// 结果是 7 扣 7
	// 其他值 扣对应的值
	// printf("%d\n", sizeof(arr));		// 6 arr 就是一个普通是字符数组, 不要想太多
	// printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 得到一个 char*, 只要是指针变量, 就是占 4 个字节
	// printf("%d\n", sizeof(*arr));		// 1 *arr 得到一个 char , 就是占一个字节
	// printf("%d\n", sizeof(arr[1]));		// 1 arr[1] 得到的一个char, 就是占一个字节
	// printf("%d\n", sizeof(&arr));		// 4 &arr 得到一个数组指针 char(*)[6], 只要是指针, 就是 4 个字节
	// printf("%d\n", sizeof(&arr + 1));	// 4 同上
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] 得到 char*, + 1 还是 char*

	// 6 扣 6
	// 7 扣 7
	// 其他值 扣其他具体的值
	printf("%d\n", strlen(arr));

	system("pause");
	return 0;
}