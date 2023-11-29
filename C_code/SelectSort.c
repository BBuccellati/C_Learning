#include<stdio.h>
#include<stdlib.h>
void SelectSort(int r[],int n);
const int N = 6;
int main(void)
{
    int a[N];       //定义一个能存放6个元素的一维数组

    printf("输入%d个整数:\n",N);
    for(int i = 0;i < N;i++)
        scanf("%d",&a[i]);      //输入6个元素
    SelectSort(a, N);       //调用排序函数

    printf("排序后结果为：");
    for(int i = 0; i < N; i++)
        printf("%d ",a[i]);     //将排好序的数组打印出来
    printf("\n");
    system("pause");
    return 0;
}
void SelectSort(int r[], int n)
{
    int i, j, mink; //mink存放最小元素的下标
    for(i = 0; i < n -1; i++)   //只需n-1趟即可完成排序
    {
        mink = i;       //首先假定最小值下标为i
        for(j = i + 1;j < n; j++)   //从i后面的一个元素开始比较
        {
        if(r[mink] > r[j]) mink = j;    //如果最小值下标不为mink，则将最小值下标j的值赋给mink
        }
        if(mink != i)   //判断最小值下标不为i
        {
        int t;      //定义中间变量
        t = r[i]; r[i] = r[mink]; r[mink] = t;      //将最小值赋给第一个元素
        }
    }
}
