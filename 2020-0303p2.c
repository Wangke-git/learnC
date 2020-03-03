#include<stdio.h>
#include<stdlib.h>
//杨氏矩阵,从左往右递增,从上而下递增
//是一张表
//二维数组
//1 , 2 ,3
//2 , 3 ,4
//3 , 4 ,5
//给定一个数,看二维数组中是否存在
//找到了,返回一,否则返回0
int Find(int arr[][3],int row,int col)
{
  int find=0;
  int i=row-1;
  int j=col;
  printf("请输入要查找的值:\n");
  scanf("%d",&find);
  while(i<row&&j<col)
  {
    if (arr[i][j]==find)
    {
      return 1;
      break ;
    }
    else 
    {
      if(arr[i][j]>find)
      {
        i--;
      }
      else 
      {
        j++;
      }
    }
  }
  return 0;
}
int main()
{
  int arr[][3]={{1,2,3},{2,3,4},{3,4,5}};
  printf("%d",Find(arr,3,3));
  system("pause");
  return 0;
}

