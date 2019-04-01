#include"sleep.h"  
//�ҵ�����7�죨�������������ڣ���˯��Сʱ���ܺ�
double getprevHours(FILE* cfptr, int endid){
    struct sleepdata tmp;
    int startid = endid - 6;
    int flag=0;
    double sumofhours=0;
    fseek(cfptr,0L,SEEK_SET); 
    while(1){
	    fread(&tmp,size,1,cfptr);
	    if(feof(cfptr))
	      break;
	    if(tmp.logid==startid)
	    	while(!feof(cfptr)){
			    sumofhours += tmp.in_hour;
			    if(tmp.logid==endid){
	    			flag=1;
	    			break;
			      }
			    fread(&tmp,size,1,cfptr);
		       }
		if(flag==1)
		   break;
	}
	  	   
    return sumofhours;
} 
//�½�sleepdata�ṹ,���Զ�����id
void createNewStructTo(struct sleepdata* sleeplog){
	printf("Enter date(e.g. 2019-01-01 or 02-02):\n");
    scanf_s("%s",sleeplog->date,10);
    printf("Enter your sleeping time in hour:\n");
    scanf("%lf",&sleeplog->in_hour);
    sleeplog->period = sleeplog->in_hour / 1.5;
    //sleeplog.logid = getLogcount(cfptr) + 1;
	getTimenow_str(sleeplog->create_date);
}
//�½���¼
void newlog(FILE*cfptr){
    struct sleepdata* sleeplog;
    sleeplog = (struct sleepdata*)malloc(sizeof(struct sleepdata));//��̬���䣬����ͨ�������޸Ľṹ�� 
    createNewStructTo(sleeplog);
	sleeplog->logid = getLogcount(cfptr) + 1;
    if(sleeplog->logid<7){
  	   sleeplog->sum7days=0;
    }
    else{
    	 sleeplog->sum7days = getprevHours(cfptr,sleeplog->logid) / 1.5;
    }
    fseek(cfptr,0L,SEEK_END);
    fwrite(sleeplog,size,1,cfptr);
    
    printf("Time: %s\nID��%d created!\nYou've slept %.2f periods on %s.\n",
		                                        sleeplog->create_date,
		                                        sleeplog->logid,
                                                sleeplog->period,
												sleeplog->date);
	free(sleeplog);//free allocated memory
}
