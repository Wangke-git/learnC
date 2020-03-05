#include<stdio.h>
#include<string.h>
int main()
{
	//  int arr[10]={0};
	//%p是用来打印指针变量(打印的是一个数组)
	////指针+1地址跳过一个元素(取决于元素的sizeof)
	//printf("%p\n",arr);//arr隐式转为指针,指向首元素的地址
	//printf("%p\n",arr+1);
	//dataprintf("%p\n",&arr); //&arr直接对数组名取地址,得到的是一个指向这个数组的指针,"数组指针",int(*)[10]
	//libprintf("%p\n",&arr+1);
	// int (*p)[10]=&arr 
	//数组指针在实际开发中使用场景十分少,二维数组传参的时候可以用到
	// int arr[3][4]={0};//长度为3的一维数组,每个元素的长度为4


	//第一组(在32位系统下)
	//int arr[] = { 1,2,3,4 };
	//printf("%d\n",sizeof(arr));//打印16,int为4,四个元素,所以打印16
	//printf("%d\n",sizeof(arr+0));//打印 4,int* arr. 
	//printf("%d\n", sizeof(*arr));//4, arr已经隐式转为int* 在解引用,得到 int
	//printf("%d\n", sizeof(arr + 1));//4,arr已经隐式转为指针
	//printf("%d\n", sizeof(&arr));  //4,数组指针,
	//printf("%d\n", sizeof(arr[1]));   //4,int类型
	//printf("%d\n", sizeof(*&arr));         //16, &arr是数组指针,再次*从这个地市开始去int(*)[4]类型对应的字节数
	//printf("%d\n", sizeof(&arr + 1)); //4 ,&arr是数组指针,int(*)[4]再+1还是一个指针,所以还是四个字节
	//printf("%d\n", sizeof(&arr[0]));//4 arr[0]为int &将其隐式转为指针得到int*类型
	//printf("%d"\n, sizeof(&arr[0] + 1);// 4 同上, 指针+1还是指针



	//第二组
	//char arr[] = { 'a','b','c','d','e','f'};
	//printf("%d\n", sizeof(arr)); // 6 arr就是一个普通的字符数组
	//printf("%d\n", sizeof(arr + 0));//4 arr+0得到一个char * ,只要是指针变量,就是占四个字节
	//printf("%d\n", sizeof(*arr)); // 1 *arr得到一个 char ,只要是指针变量,就是占4个字节
	//printf("%d\n", sizeof(arr[1])); // 1 arr[1]得到的就是一个char,就是占一个字节
	//printf("%d\n", sizeof(&arr));  //arr隐式转为指针,在32位操作系统下指针就位 4
	//printf("%d\n", sizeof(&arr + 1)); // 4 同上,隐式转为指针,指针+1还是指针
	//printf("%d\n", sizeof(&arr[0] + 1));// 4 &arr[0]得到char*,+1还是char*
	//printf("%d\n", strlen(arr));   未定义行为UB
	//printf("%d\n", strlen(arr + 0));//未定义行为
	//*arr得到的是char类型的,strlen要求的参数是char *类型的
	//printf("%d\n", strlen(*arr));//这个代码按理来说,是要编译报错的.但是C是弱类型的编程语言,把char和char*隐式转换了
	//printf("%d\n", strlen(arr[1]));//效果同上




	//第三组
	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr)); //7 sizeof是求内存的大小,这个大小要包含\0
	//printf("%d\n", sizeof(arr+0));//4 隐式转为char* 指针
	//printf("%d\n", sizeof(*arr));//得到一个char 打印1
	//printf("%d\n", sizeof(arr[1]));//得到一个char 打印1
	//printf("%d\n", sizeof(&arr));// 4 隐式转为指针char *
	//printf("%d\n", sizeof(&arr+1));//4 理由同上,指针+1还是指针
	//printf("%d\n", sizeof(&arr[0]+1));// 4 &arr[0]+1得到一个char * 指针
	//printf("%d\n", strlen(arr)); //6此处是求字符串长度,不算\0;
	//printf("%d\n", strlen(arr + 0));// 6
	//printf("%d\n", strlen(*arr));//未定义行为 UB *arr得到字符,char和char*类型不匹配.编译失败
	//printf("%d\n", strlen(arr[1]));//同上
	//printf("%d\n", strlen(&arr));//6 &arr 得到char(*)[7]类型,和char*类型不匹配,按理来说是编译失败,&arr碰巧和arr的到的地址指,是相同的值.纯属巧合
	//printf("%d\n", strlen(&arr + 1));//UB &arr+1跳过了整个数组,访问数组后面的空间,非法内存
	//printf("%d\n", strlen(&arr[0] + 1));//5  &arr[0]得到一个char*   char*+1跳过一个元素




	//第四组
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p)); //4 p是一个指针
	//printf("%d\n", sizeof(p+1)); //4 指针+1还是指针
	//printf("%d\n", sizeof(*p)); //1  p是char* 解引用后的到一个char 打印1
	//printf("%d\n", sizeof(p[1]));// 1 p[1]是char
	//printf("%d\n", sizeof(&p));     //4 p是char*   &p相当于char** 二级指针还是指针
	//printf("%d\n", sizeof(&p+1));     //4 理由同上
	//printf("%d\n", sizeof(&p[0]+1));     //4 p[0]是char &p[0]相当于char* 再加1还是char *
	//printf("%d\n", strlen(p));        //打印字符串 6
	//printf("%d\n", strlen(*p));       //UB *p是char strlen 要求参数是char *,类型不匹配
	//printf("%d\n", strlen(p[1]));        //p[1]是char ,类型不匹配
	//printf("%d\n", strlen(&p));        //UB &p得到char** 和char*是不同类型的,原则上是编译失败的,此时 把char**强转成了char* 并不是一个真正的字符串
	//printf("%d\n", strlen(&p+1));  //UB 同上
	//printf("%d\n", strlen(&p[0]+1));//5 &p[0]相当于一个char* 指针+1跳过一个元素输出字符串长度为5


	//第五组 二维数组
	//所谓的二维数组,本质上就是一个一维数组.里边的每一个元素又是一个一维数组
	//长度为3个元素的一维数组,里边的每个元素又是长度为4的一维数组
	int a[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};
	//printf("%d\n", sizeof(a));// 48 12个元素每个元素占4个字节
	//printf("%d\n", sizeof(a[0][0])); // 4   a[0][0]相当于int
	//printf("%d\n", sizeof(a[0]));     //16  a[0]相当于int[4]
	//printf("%d\n", sizeof(a[0]+1));     //4  a[0]相当于int[4]再加1  隐式转成了int*
	//*(a[0]+1)相当于a[0][1]等价于2
	//printf("%d\n", sizeof(*  (a[0] + 1)  ));//4  a[0]等价于int[4]再+1,隐式转为int * 再*得到int
	//printf("%d\n", sizeof((&a[0] + 1))); // 4 a[0]+1相当于int* 再& 得到int** 还是指针
	//printf("%d\n", sizeof(*(&a[0] + 1)));//4 a[0]+1相当于int* 再& 得到int** 还是指针 再*得到int *
	//printf("%d\n", sizeof(*a));   //*a等价于*(a+0)=>a[0]结果int[4]
	//printf("%d\n", sizeof(a[100]));//16 sizeof是一个运算符(不是函数),特点是,编译期求值
	return 0;

}
