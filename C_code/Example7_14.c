#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])    //argc 命令行参数个数
{
    int i, x, max;

    if (argc <= 1)  //若只有一个数
    {
        printf("用法:max 数1 数2 ... 数n");
        system("pause");
        exit(0);
    }
    //printf("123");
    max = atoi(argv[1]);
    for (i = 2; i < argc; i++)
    {
        x = atoi(argv[i]);
        if (x > max)
            max = x;
    }

    printf("最大的数为：%d\n", max);
    system("pause");
    return 0;
}
