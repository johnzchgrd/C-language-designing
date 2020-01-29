#include <stdio.h>
#define DANWEI long long unsigned int
DANWEI fibo(DANWEI n)
{
    static DANWEI n1 = -1, n2 = -1;
    DANWEI ret;
    if (n < 1)
        ret = 0;
    else if (n == 1 || n == 2)
        ret = 1;
    else
    {
        if (n1 == -1 || n2 == -1)
            ret = fibo(n - 1) + fibo(n - 2);
        else
            ret = n1 + n2;
    }
    n1 = n2;
    n2 = ret;

    return ret;
}
int main(void)
{
    for (DANWEI i = 1; i < 100; i++)
        printf("%llu ", fibo(i));
    return 0;
}
