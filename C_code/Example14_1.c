#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100

int main(void)
{
    int prime[N + 1];
    int n;
    scanf("%d", &n);

/*     //将prime[]所有元素置0
    for (int i = 0; i <= N;i++)
    {
        prime[i] = 0;
    } */

    //将prime[]所有元素置0
    menset(prime, 0, sizeof(prime));
    prime[1] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if(prime[i] == 0)
        {
            for (int j = i * 2; j < n;j += i)
                prime[j] = 1;
        }
    }

    int t = 0;
    for (int i = 2; i < n;i++)
    {
        
        if(prime[i]==0)
        {
            printf("%d ", i);
            t++;
            if(t%5==0)
                printf("\n");
        }
    }

        system("pause");
    return 0;
}
