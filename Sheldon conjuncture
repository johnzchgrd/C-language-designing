#include<stdio.h>
#include<math.h>
#define MAX 10e64   //double: ±(10e-308~10e308)
#define START 2
#define END MAX

/*file name: temp.c
 *author: Johnzchgrd
 *date: 2019/05/11 16:16
 *descriptions: test for Proof of Sheldon Conjuecture, only n=7,21,181440 fit?
 */

//判断是否为素数，是返回1，不是返回0
int prime(int m){
	int i;
	for(i=2;i<=m/2;i++)
	  if(m%i==0)
	    break;
	if(i>m/2&&m!=1)
	   return 1;
   else
	  return 0; 
}

double fastproduction(double product, short bit){
	//传入bit范围2~9，手动加速
	switch(bit){
		case 2: return  
		case 3:
	}
}

int sheldonprime(int primenumber, int prime){
	double product = 1;//保存乘积——乘法运算的化简是降低计算时间复杂度的必由之路
	short smallest_bit = 1;//从最低位开始，向高位提取，逐一向右移动所有位，遇到0直接跳出循环
	double ratio=0;
	
	//分解传入素数
	while(prime != 0){
		smallest_bit = prime%10;//取最小位
		if(smallest_bit == 0)
			return 0;//考虑实际意义，直接返回即可
		if(smallest_bit > 1)
		    product = fastproduction(product,smallest_bit);/////////此处需要改进/////////
		
		prime /= 10;//向右移动一位
	}

	
	//比较乘积与序号是否相同
	if(product == primenumber)
		return 1;
	else
		return 0;
}


int main(void){
	int index, primenumber = 0, sheldonflag = 0;//遍历参数，第n个素数，是否为Sheldon素数的标志
	int isprime;
	double delta = END - START;
	//仿佛听到了CPU的咆哮声……
	for(index = START;index <= END;index++){
		//printf("progress: %.2f%%\r",index/(delta));
		printf("progress: %064d\r",index);//显示进度--暂未成功
		isprime = prime(index);//判断是否为素数
		if(isprime == 1){
			primenumber++;
			sheldonflag = sheldonprime(primenumber, index);
			if(sheldonflag == 1){
				printf("P(%d) = %d is a Sheldon prime.\n", primenumber, index);
			}
		}
	}
	
	printf("Search finished.\n");
	
	return 0;
}
