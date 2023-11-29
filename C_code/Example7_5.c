#include <stdio.h>

void f(const int *ptr);
int main(void)
{
    int y;
    f(&y);

    return 0;
}
void f(const int *ptr)
{
   // *ptr = 100; // 编译错误，因为ptr是常量指针
}