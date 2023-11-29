#include <stdio.h>
#include <stdlib.h>

void Swap(int *p1,int *p2);
int main()
{
  int x = 4, y = 6;
  Swap(&x, &y);
  printf("x = %d y = %d\n", x, y);
  system("pause");
  return 0;
}
void Swap(int *p1,int *p2)
{
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
