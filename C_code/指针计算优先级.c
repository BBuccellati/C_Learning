#include <stdio.h>
#include <stdlib.h>


int main()
{

    int a[6] = {1, 2, 3, 4, 5, 6};
    int *p = a;
    printf("%d\n", *p++);   // 先执行*p 并打印 1 ，再指针 p->a[1]
    printf("%d\n", (*p)++); // 先执行*p并打印  2 ，然后a[1]+1 = 3, 即数组更新为 a[] = {1 3 3 4 5 6} 指针还是指向a[1]
    printf("%d\n", *(p++)); // 先执行*p 并打印 3 ，再指针 p->a[2]
    printf("%d\n", *(++p)); // 先执行p->a[3] ，   再打印a[3] = 4
    printf("%d\n", ++*(p)); // 先执行*p = 4，再自增 即a[3]+`1 = 5, 并打印 5 即数组更新为 a[] = {1 3 3 5 5 6} 指针还是指向a[3]
    printf("%d\n", *(p--)); // 先执行*p 并打印 5 ，再指针 p->a[2]
    printf("%d\n", *(--p)); //   先执行--p ,指针p->a[1] 再打印3
    system("pause");
    return 0;
}