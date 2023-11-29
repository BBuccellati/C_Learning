#include <stdio.h>
#include <stdlib.h>
struct Sample
{
	short int n;
	char c[11];   
	float f;
	double b;
}s;

int main(void)
{
	printf("变量s所占字节数为:%d个字节\n",sizeof(s));  
	printf("结构成员   地址\n");
	printf("    n     %#X  %d\n", &s.n,sizeof(s.n));
	printf("    c     %#X  %d\n", s.c,sizeof(s.c));
	printf("    f     %#X  %d\n", &s.f, sizeof(s.f));
	printf("    b     %#X  %d\n", &s.b, sizeof(s.b));
	system("pause");
	return 0;
}

