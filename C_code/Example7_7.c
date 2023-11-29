#include <stdio.h>
#include <stdlib.h>
int search(const int *p, int n, int x); // 函数声明

int main()
{
    int a[6] = {1, 5, 2, 3, 9, 7};
    int x;
    printf("输入要查找的元素：");
    scanf("%d", &x);
    int k = search(a, 6, x);
    if (k == -1)
        printf("未找到!\n");
    else
        printf("找到了，是数组中的第%d个元素:", k + 1);
    system("pause");
    return 0;
}

int search(const int *p, int n, int x)
{ // 在数组中找元素值为x的元素
  // 找到返回在数组中的下标，找不到返回-1
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == x)
        {
            pos = i;
            break;
        }
    }
    
    return pos;
}
