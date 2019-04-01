#include"sleep.h" 

//修改指定编号记录
void correction(FILE* dfptr){
	int wrongid,idfindflag=0;
	FILE* tmpnew;
	struct sleepdata sleep,*newsleep;
	printf("Enter the ID of the data you want to correct:\n");
	scanf("%d",&wrongid);
	newsleep = (struct sleepdata*)malloc(sizeof(struct sleepdata));
	fseek(dfptr,0L,SEEK_SET);
	while(!feof(dfptr)){
		fread(&sleep,size,1,dfptr);
		
		if(sleep.logid==wrongid)
		{
			
		    createNewStructTo(newsleep);
		    newsleep->logid = sleep.logid;
		    
			if(newsleep->logid<7){
			  	   newsleep->sum7days=0;
			    }
			    else{
			    	 newsleep->sum7days = getprevHours(dfptr,newsleep->logid);
			    }
		    
		    fseek(dfptr,0L,SEEK_SET);
		    tmpnew = openfile("b.dat","wb+");
			while(1) {
				fread(&sleep,size,1,dfptr);
				if(feof(dfptr))
				 break;
				if(sleep.logid == wrongid){
					fwrite(newsleep,size,1,tmpnew);
				}
				else{
					fwrite(&sleep,size,1,tmpnew);
				}
			}
			
			closefile(tmpnew);
			free(newsleep);
			idfindflag=1;
			printf("Corrcetion finished!\n");
			break;
		}
	}
	if(idfindflag==0)
	  printf("No ID: %d found!\n",wrongid);
} 
//遍历刷新weeklysum
void fresh(FILE* dfptr){
	struct sleepdata freshtmp;
	char* filename_tmp[MAXFILENAMELEN];
	static int name_num = 0;
	sprintf(filename_tmp,"freshed_%d.dat",name_num++);
	FILE* tmpptr = openfile(filename_tmp,"wb");
	int count=getLogcount(dfptr);
	fseek(dfptr,0L,SEEK_SET);
	while(count--){
		fread(&freshtmp,size,1,dfptr);
		if(freshtmp.logid<7&&freshtmp.logid>0){
	  	   freshtmp.sum7days=0;
	    }
	    else{
	    	 freshtmp.sum7days = getprevHours(dfptr,freshtmp.logid) / 1.5;
	    }
	    fwrite(&freshtmp,size,1,tmpptr);
	} 
	closefile(tmpptr);
	printf("Fresh completed!Saved to %s\n",filename_tmp);
}


