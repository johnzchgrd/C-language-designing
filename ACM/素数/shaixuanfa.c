#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<assert.h>
//筛选法求指定区间所有素数
//来源：杭州电子科技大学  刘春英acm@hdu.edu.cn

/*
基本思想：素数的倍数一定不是素数
实现方法：用一个长度为N+1的数组保存信息（0表示素数，1表示非素数），
先假设所有的数都是素数（初始化为0），从第一个素数2开始，
把2的倍数都标记为非素数（置为1），一直到大于N；
然后进行下一趟，找到2后面的下一个素数3，进行同样的处理，
直到最后，数组中依然为0的数即为素数。
说明：整数1特殊处理即可。
*/
int main()
{
	#define ENDNUM 10000
	int a[ENDNUM] = {0};
	int isprime(int num)
	{
		if(num==1)
		return 0;
		int limit = sqrt(num),i;
		for (i = 2; i <= limit; i++)
		{
			if (num % i == 0)
				break;
		}
		if (i <= limit)
			return 0;
		else
			return 1;
	}
	for (int i = 0; i < ENDNUM; i++)
	{
		int num = i + 1;
		if (isprime(num) == 1)
		{
			for (int k = 2 * num; k <= ENDNUM; k += num)
			{
				a[k - 1] = 1;
			}
		}
		else
		{
			a[i] = 1;
		}
	}
	for (int i = 0; i < ENDNUM; i++)
	if(a[i]==0)
		assert(isprime(i+1)==1);

	return 0;
}
