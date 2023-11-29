#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p, *q, **pp;
    p = (int *)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        *(p + i) = i + 1;
    }
    q = (int *)malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        *(q + i) = i + 5;
    }

    pp = (int **)malloc(2 * sizeof(int *));
    *pp++ = p;
    *pp = q;
    printf("%d,%d\n", *(*(pp + 1) + 1), **(--pp));
    /*
    ()内的pp运算是对最地层指针进行运算
    如：
    *(pp + 1) 先计算二级指针，将其指向二级指针的第二块地址，然后跳到第二块地址对应元素q[0]的地址
    *()则是中层指针，在括号内的pp计算完毕后指向对应一级指针
    */

    free(p);
    free(q);
    free(pp);
    system("pause");
    return 0;
}