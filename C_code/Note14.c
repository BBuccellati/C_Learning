#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i = 4, j;
    j = (++i) + (++i) + (++i);
    printf("%d", j);
    system("pause");
    return 0;
}