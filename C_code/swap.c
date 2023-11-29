#include<stdio.h>
#include<stdlib.h>

//交换两个值
void swap(int a,int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
//利用传值的方式不能交换两个实参的值
int main(void)
{
    int x = 5;
    int y = 10;
    printf("交换前x=%d,y=%d\n",x,y);
    swap(x,y);
    printf("交换前x=%d,y=%d\n",x,y);
    system("pause");
    return 0;
}