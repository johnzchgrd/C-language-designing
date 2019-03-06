//???????
void listall(FILE*cfptr){
    struct sleepdata sleeplog;
    int flag=0;//???????? 
    fseek(cfptr,0L,SEEK_SET);
   	  printf("%-4s%-15s%-8s%-10s%-5s\n","ID","DATE","HOURS","PERIODS","WeeklySum");
	  while(1){
	    fread(&sleeplog,size,1,cfptr);
	    if(feof(cfptr))
	      break;
	    printf("%-4d%-15s%-8.2lf%-10.2lf%-5.2lf\n",sleeplog.logid,
		                                           sleeplog.date,
												   sleeplog.in_hour,
												   sleeplog.period,
												   sleeplog.sum7days);
	    flag=1; 
	  }
    if(flag==0){
    	printf("No data found in the file!\n");
	}
  
}
