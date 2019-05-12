#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define SHOWLENGTH 20
#define END 10e8  //10^9
#define START 10e5 //10^6

/*file name: temp.c
 *author: Johnzchgrd
 *date: 2019/05/11 16:16
 *descriptions: test for Proof of Sheldon Conjuecture, only n=7,21,181440 fit?
 *
 *CPU: Intel(R) Core(TM) i7-8550U CPU @ 1.80GHz 1.99GHz
 *
 *Manually using 3 threads, CPU occupation stays around 52%
 *verified domain:  
 *2~2080,0000(7,21,181440)
 *1e8~1,0245,0000(none)
 *
 *
 */

//判断是否为素数，是返回1，不是返回0
unsigned prime(unsigned m){
	unsigned i;
	for(i=2;i<=m/2;i++)
	  if(m%i==0)
	    break;
	if(i>m/2&&m!=1)
	   return 1;
   else
	  return 0; 
}

unsigned numbersplit(unsigned num){
		
		return num;
		
}

unsigned fastproduction(unsigned product, short bit){
	//传入bit范围2~9，手动加速
	switch(bit){
		case 3: return product + (product<<1);
		case 4: return product<<2;
		case 5: return product + (product<<2);
		case 6: return (product<<2) + (product<<1);
		case 7: return (product<<3) - product;
		case 8: return product<<3;
		case 9: return product + (product<<3);
		default:printf("\nThere's something wrong with the \
FASTPRODUCTION function when calculating %d x %hd.\n",product,bit);
		exit(1);
	}
	
}

unsigned sheldonprime(unsigned primenumber, unsigned prime){
	unsigned product = 1;//保存乘积——乘法运算的化简是降低计算时间复杂度的必由之路
	short smallest_bit;//从最低位开始，向高位提取，逐一向右移动所有位，遇到0直接跳出循环
	
	//分解传入素数
	while(prime != 0){
		smallest_bit = prime%10;//取最小位
		
		if(smallest_bit == 0)
			return 0;//考虑实际意义，直接返回即可；1不用改变product的值
		//core
		if(smallest_bit > 2)
		    product = fastproduction(product,smallest_bit);/////////此处需要改进/////////
		else if(smallest_bit == 2)
			product <<= 1;
		//end
		
		prime /= 10;//向右移动一位
	}
	
	//比较乘积与序号是否相同
	if(product == primenumber)
		return 1;
	else
		return 0;
}



int main(void){
	unsigned index, primenumber = 0, sheldonflag = 0;//遍历参数，第n个素数，是否为Sheldon素数的标志
	unsigned isprime;//判断是否为素数的中间变量
	unsigned start=START,end = END;
	
	printf("Start: %u, end: %u\n",numbersplit(start),numbersplit(end));
	//仿佛听到了CPU的咆哮声……
	for(index = start;index <= end;index++){
		printf("progress: %.*d\r",SHOWLENGTH,numbersplit(index));//显示进度--十分简陋
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
	//system("shutdown /s");
	
	return 0;
}
