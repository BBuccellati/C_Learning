#include <stdio.h>      
#include <stdlib.h>     // malloc, free, rand,srand 
#include <time.h>       // time(0)

int main ()
{
 	int len;
  	char * buffer = NULL;     //声明指针变量并初始化为空指针
  	srand(time(0)); // 设置随机数种子 
  	printf ("你想要多长的串? ");
 	scanf ("%d", &len);

  	buffer = (char*) malloc (len+1);     //动态分配 len+1个字节空间 
  	if (buffer == NULL) exit (1);          //分配失败 

 	for (int i = 0; i < len; i++)               //产生随机串 
    	      buffer[i] = rand()%26 + 'a';
         buffer[len]='\0';                               //放字符串结束标志 
 
  	printf ("随机串: %s\n",buffer);
  	free (buffer);  //释放空间 

    system("pause");
  	return 0;
}
