#include<stdio.h>
#include<string.h>
int main()
{
	//  int arr[10]={0};
	//%p��������ӡָ�����(��ӡ����һ������)
	////ָ��+1��ַ����һ��Ԫ��(ȡ����Ԫ�ص�sizeof)
	//printf("%p\n",arr);//arr��ʽתΪָ��,ָ����Ԫ�صĵ�ַ
	//printf("%p\n",arr+1);
	//dataprintf("%p\n",&arr); //&arrֱ�Ӷ�������ȡ��ַ,�õ�����һ��ָ����������ָ��,"����ָ��",int(*)[10]
	//libprintf("%p\n",&arr+1);
	// int (*p)[10]=&arr 
	//����ָ����ʵ�ʿ�����ʹ�ó���ʮ����,��ά���鴫�ε�ʱ������õ�
	// int arr[3][4]={0};//����Ϊ3��һά����,ÿ��Ԫ�صĳ���Ϊ4


	//��һ��(��32λϵͳ��)
	//int arr[] = { 1,2,3,4 };
	//printf("%d\n",sizeof(arr));//��ӡ16,intΪ4,�ĸ�Ԫ��,���Դ�ӡ16
	//printf("%d\n",sizeof(arr+0));//��ӡ 4,int* arr. 
	//printf("%d\n", sizeof(*arr));//4, arr�Ѿ���ʽתΪint* �ڽ�����,�õ� int
	//printf("%d\n", sizeof(arr + 1));//4,arr�Ѿ���ʽתΪָ��
	//printf("%d\n", sizeof(&arr));  //4,����ָ��,
	//printf("%d\n", sizeof(arr[1]));   //4,int����
	//printf("%d\n", sizeof(*&arr));         //16, &arr������ָ��,�ٴ�*��������п�ʼȥint(*)[4]���Ͷ�Ӧ���ֽ���
	//printf("%d\n", sizeof(&arr + 1)); //4 ,&arr������ָ��,int(*)[4]��+1����һ��ָ��,���Ի����ĸ��ֽ�
	//printf("%d\n", sizeof(&arr[0]));//4 arr[0]Ϊint &������ʽתΪָ��õ�int*����
	//printf("%d"\n, sizeof(&arr[0] + 1);// 4 ͬ��, ָ��+1����ָ��



	//�ڶ���
	//char arr[] = { 'a','b','c','d','e','f'};
	//printf("%d\n", sizeof(arr)); // 6 arr����һ����ͨ���ַ�����
	//printf("%d\n", sizeof(arr + 0));//4 arr+0�õ�һ��char * ,ֻҪ��ָ�����,����ռ�ĸ��ֽ�
	//printf("%d\n", sizeof(*arr)); // 1 *arr�õ�һ�� char ,ֻҪ��ָ�����,����ռ4���ֽ�
	//printf("%d\n", sizeof(arr[1])); // 1 arr[1]�õ��ľ���һ��char,����ռһ���ֽ�
	//printf("%d\n", sizeof(&arr));  //arr��ʽתΪָ��,��32λ����ϵͳ��ָ���λ 4
	//printf("%d\n", sizeof(&arr + 1)); // 4 ͬ��,��ʽתΪָ��,ָ��+1����ָ��
	//printf("%d\n", sizeof(&arr[0] + 1));// 4 &arr[0]�õ�char*,+1����char*
	//printf("%d\n", strlen(arr));   δ������ΪUB
	//printf("%d\n", strlen(arr + 0));//δ������Ϊ
	//*arr�õ�����char���͵�,strlenҪ��Ĳ�����char *���͵�
	//printf("%d\n", strlen(*arr));//������밴����˵,��Ҫ���뱨���.����C�������͵ı������,��char��char*��ʽת����
	//printf("%d\n", strlen(arr[1]));//Ч��ͬ��




	//������
	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr)); //7 sizeof�����ڴ�Ĵ�С,�����СҪ����\0
	//printf("%d\n", sizeof(arr+0));//4 ��ʽתΪchar* ָ��
	//printf("%d\n", sizeof(*arr));//�õ�һ��char ��ӡ1
	//printf("%d\n", sizeof(arr[1]));//�õ�һ��char ��ӡ1
	//printf("%d\n", sizeof(&arr));// 4 ��ʽתΪָ��char *
	//printf("%d\n", sizeof(&arr+1));//4 ����ͬ��,ָ��+1����ָ��
	//printf("%d\n", sizeof(&arr[0]+1));// 4 &arr[0]+1�õ�һ��char * ָ��
	//printf("%d\n", strlen(arr)); //6�˴������ַ�������,����\0;
	//printf("%d\n", strlen(arr + 0));// 6
	//printf("%d\n", strlen(*arr));//δ������Ϊ UB *arr�õ��ַ�,char��char*���Ͳ�ƥ��.����ʧ��
	//printf("%d\n", strlen(arr[1]));//ͬ��
	//printf("%d\n", strlen(&arr));//6 &arr �õ�char(*)[7]����,��char*���Ͳ�ƥ��,������˵�Ǳ���ʧ��,&arr���ɺ�arr�ĵ��ĵ�ַָ,����ͬ��ֵ.�����ɺ�
	//printf("%d\n", strlen(&arr + 1));//UB &arr+1��������������,�����������Ŀռ�,�Ƿ��ڴ�
	//printf("%d\n", strlen(&arr[0] + 1));//5  &arr[0]�õ�һ��char*   char*+1����һ��Ԫ��




	//������
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p)); //4 p��һ��ָ��
	//printf("%d\n", sizeof(p+1)); //4 ָ��+1����ָ��
	//printf("%d\n", sizeof(*p)); //1  p��char* �����ú�ĵ�һ��char ��ӡ1
	//printf("%d\n", sizeof(p[1]));// 1 p[1]��char
	//printf("%d\n", sizeof(&p));     //4 p��char*   &p�൱��char** ����ָ�뻹��ָ��
	//printf("%d\n", sizeof(&p+1));     //4 ����ͬ��
	//printf("%d\n", sizeof(&p[0]+1));     //4 p[0]��char &p[0]�൱��char* �ټ�1����char *
	//printf("%d\n", strlen(p));        //��ӡ�ַ��� 6
	//printf("%d\n", strlen(*p));       //UB *p��char strlen Ҫ�������char *,���Ͳ�ƥ��
	//printf("%d\n", strlen(p[1]));        //p[1]��char ,���Ͳ�ƥ��
	//printf("%d\n", strlen(&p));        //UB &p�õ�char** ��char*�ǲ�ͬ���͵�,ԭ�����Ǳ���ʧ�ܵ�,��ʱ ��char**ǿת����char* ������һ���������ַ���
	//printf("%d\n", strlen(&p+1));  //UB ͬ��
	//printf("%d\n", strlen(&p[0]+1));//5 &p[0]�൱��һ��char* ָ��+1����һ��Ԫ������ַ�������Ϊ5


	//������ ��ά����
	//��ν�Ķ�ά����,�����Ͼ���һ��һά����.��ߵ�ÿһ��Ԫ������һ��һά����
	//����Ϊ3��Ԫ�ص�һά����,��ߵ�ÿ��Ԫ�����ǳ���Ϊ4��һά����
	int a[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};
	//printf("%d\n", sizeof(a));// 48 12��Ԫ��ÿ��Ԫ��ռ4���ֽ�
	//printf("%d\n", sizeof(a[0][0])); // 4   a[0][0]�൱��int
	//printf("%d\n", sizeof(a[0]));     //16  a[0]�൱��int[4]
	//printf("%d\n", sizeof(a[0]+1));     //4  a[0]�൱��int[4]�ټ�1  ��ʽת����int*
	//*(a[0]+1)�൱��a[0][1]�ȼ���2
	//printf("%d\n", sizeof(*  (a[0] + 1)  ));//4  a[0]�ȼ���int[4]��+1,��ʽתΪint * ��*�õ�int
	//printf("%d\n", sizeof((&a[0] + 1))); // 4 a[0]+1�൱��int* ��& �õ�int** ����ָ��
	//printf("%d\n", sizeof(*(&a[0] + 1)));//4 a[0]+1�൱��int* ��& �õ�int** ����ָ�� ��*�õ�int *
	//printf("%d\n", sizeof(*a));   //*a�ȼ���*(a+0)=>a[0]���int[4]
	//printf("%d\n", sizeof(a[100]));//16 sizeof��һ�������(���Ǻ���),�ص���,��������ֵ
	return 0;

}
