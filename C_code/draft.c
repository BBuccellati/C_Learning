/* #include <stdio.h>
#include<stdlib.h>
#define N 100
void Swap(int *p1, int *p2);
int main(void)
{
  int (*p) [10];    //这里的p是一个指着变量，指向一个整型的一维数组，这个一维数组的长度是10
  int a[10];
  int (*p) [10] = &a;   //a是有10个单元的整型数，p指向了这个数组。那么为什么不是p = a；因为a是a[0]单元的地址，是一个整型空间的地址，与p类型不匹配
  //以下第二条语句会报错
  int a[11];
  int(*p)[10] = &a; //p只能是10个整型空间的地址，不能是其他类型的地址
  //数组指针的主要用途是指向二维数组的某一行

  int x = 5;        //多级指针常与多维数组一起使用
  int *p, **pp, ***ppp;
  p = &x;       //p为一级指针
  pp = &p;      //pp是二级指针
  ppp = &pp;    //ppp值三级指针

  int *ptr[10];   //这里ptr是数组名，有10个元素，每个元素的类型是int*，也就是每个元素值是整型空间的地址，

  double (*funcPtr)(double,double);
  // 这里的funPtr就是函数指针，如果用某个名字替代“(*funcPtr)”，那么这就是一个函数声明。
  //定义函数指针时括号是不能省略的，否则就变成了函数声明。
  //funcPtr指针变量只能指向有两个double形参且返回值为double的函数。
  //也就是说，如果有函数int add(int ,int), add与funcPtr是不同类型的

}
void Swap(int *p1, int *p2)
{
  int *p = (int *)malloc(sizeof(int));
  *p = *p1;
  *p1 = *p2;
  *p2 = *p;
  free(p);
} */
//Example12_
/*
格式控制参数
%d -> 十进制有符号整数
%u -> 无符号十进制整数
%f -> 十进制浮点数
%o -> 八进制数
%x -> 十六进制数
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char word[5];
  word[0] = 'y', word[1] = 'o', word[2] = 'u';
  for (int i = 0; i <= 2;i++)
  {
    printf("%c\n", word[i]);
  }

    system("pause");
  return 0;
}