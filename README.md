# C-language-designing
2018年秋冬学期
##素数应用
7-104 素数对猜想 （20 分）
让我们定义d
​n
​​ 为：d
​n
​​ =p
​n+1
​​ −p
​n
​​ ，其中p
​i
​​ 是第i个素数。显然有d
​1
​​ =1，且对于n>1有d
​n
​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10
​5
​​ )，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
 #include<stdio.h>
#include<math.h>
//判断是否为素数 
int prime(int m){
	int i;
	int t=sqrt(m);
	for(i=2;i<=t;i++)
	  if(m%i==0)
	    break;
	if(i>t&&m!=1)
	   return 1;
	return 0; 
}

//将指定区间的数组保存到s[]中 
void saveprimes(int n,int*s){
 int i,k=0;
	for(i=2;i<=n;i++){
		if(prime(i)){
		   s[k]=i;
		   k++;
		}
	}
}
main(){
	int n,i,cnt=0;
	int s[70000]={0}; 
	scanf("%d",&n);
    saveprimes(n,s);
   for(i=0;s[i+1];i++){
     if(s[i+1]-s[i] == 2)
      cnt++;
   } 
   printf("%d",cnt);
	return 0; 
}
