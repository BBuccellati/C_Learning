#include <stdio.h>
#include <stdlib.h>
/*
0 1 2 3
4 5 6 7
8 9 a b
c d e f
*/
//地址变化
/*
c20 c24 c28 c2c
c30 c34 c38 c3c
...
c70 c74 c78 c7c
*/
int main(void)
{
    int x = 5;
    int *p[3] = {NULL, NULL, NULL};
    p[0] = (int *)malloc(7 * sizeof(int));
    p[1] = (int *)malloc(5 * sizeof(int));
    p[2] = &x;
    printf("%d\n",sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("%#X\n", p[i]);  //加'#'显示0X前缀
    }
    system("pause");
    return 0;
}
