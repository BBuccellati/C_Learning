#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct coord // 结构类型定义
{
    int x;
    int y;
};

int main(void)
{
    struct coord first, second; // 结构变量声明
    double distance;            // 两点间距离

    printf("请输入第一个点坐标：");
    scanf("%d %d", &first.x, &first.y); // 点运算符访问结构成员
    printf("请输入第二个点坐标：");
    scanf("%d %d", &second.x, &second.y);
    int xDiff = first.x - second.x; // 横坐标的差
    int yDiff = first.y - second.y; // 纵坐标的差
    distance = sqrt(xDiff * xDiff + yDiff * yDiff);
    printf("两点间距离是：%f\n", distance);
    system("pause");
    return 0;
}
