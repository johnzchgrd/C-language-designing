#include"sleep.h"  
//列出所有记录 
void listall(FILE*cfptr){
    struct sleepdata sleeplog;
    int flag=0;//是否为空标志 
    fseek(cfptr,0L,SEEK_SET);
   	  printf("%-4s%-15s%-8s%-10s%-13s%-25s\n","ID","DATE","HOURS","PERIODS","PeriodSum","Create Date");
	  while(1){
	    fread(&sleeplog,size,1,cfptr);
	    if(feof(cfptr))
	      break;
	    printf("%-4d%-15s%-8.2lf%-10.2lf%-13.2lf%-25s\n",sleeplog.logid,
		                                           sleeplog.date,
												   sleeplog.in_hour,
												   sleeplog.period,
												   sleeplog.sum7days,
		                                           sleeplog.create_date);
	    flag=1; 
	  }
    if(flag==0){
    	printf("No data found in the file!\n");
	}
  
}
