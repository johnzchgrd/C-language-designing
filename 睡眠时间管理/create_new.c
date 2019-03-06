//找到前6天（不包括创建的日期）的睡眠周期总和
double getprevPeriods(FILE* cfptr, int endid){
    struct sleepdata tmp;
    int startid = endid - 5;
    int flag=0;
    double sumofperiods=0;
    fseek(cfptr,0L,SEEK_SET);//未知作用 
    while(1){
	    fread(&tmp,size,1,cfptr);
	    if(feof(cfptr))
	      break;
	    if(tmp.logid==startid)
	    	while(1){
	    		fread(&tmp,size,1,cfptr);
	    		
			    sumofperiods += tmp.period;
			    if(tmp.logid==endid){
	    			flag=1;
	    			break;
			      }
		       }
		if(flag==1)
		   break;
	}
	  	   
    return sumofperiods;
} 
//新建sleepdata结构,不自动生成id
void createNewStructTo(struct sleepdata* sleeplog){
	printf("Enter date(e.g. 2019-01-01):\n");
    scanf("%10s",sleeplog->date);
    printf("Enter your sleeping time in hour:\n");
    scanf("%lf",&sleeplog->in_hour);
    sleeplog->period = sleeplog->in_hour / 1.5;
    //sleeplog.logid = getLogcount(cfptr) + 1;

}
//新建记录
void newlog(FILE*cfptr){
    struct sleepdata* sleeplog;
    sleeplog = (struct sleepdata*)malloc(sizeof(struct sleepdata));
    createNewStructTo(sleeplog);
	sleeplog->logid = getLogcount(cfptr) + 1;
	
    if(sleeplog->logid<7){
  	   sleeplog->sum7days=0;
    }
    else{
    	 sleeplog->sum7days = getprevPeriods(cfptr,sleeplog->logid-1) + sleeplog->period;
    }
    fseek(cfptr,0L,SEEK_END);
    fwrite(&sleeplog,size,1,cfptr);
    
    printf("ID：%ld created!\nYou've slept %.2f periods on %s.\n",sleeplog->logid,
                                                                  sleeplog->period,
																  sleeplog->date);
	free(sleeplog);
}
