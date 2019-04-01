#include"sleep.h"  
void getprevHours_test(FILE* fp,int IDfortest){
	double sum = getprevHours(fp, IDfortest);
	printf("Enter ID:\n");
	scanf("%d", &IDfortest);
	printf("Sum of time:%.2f\nAverage sleeping time:%.2f\n",sum,sum/1.5 );
}
