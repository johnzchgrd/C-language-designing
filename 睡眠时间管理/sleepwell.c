/*程序实现功能：
 *1、新建睡眠时间记录*
 *2、查询所有睡眠时间记录*
 *3、判断最近一周的睡眠时间是否达标 
 *4、数据加密保护->加密算法 
 *5、对日期进行排序
 *6、支持修改特定日期或编号的记录 
 *7、刷新数据 
 *8、自动计算睡眠时间
 *9、智能识别输入格式
 */
 
 /*
  *author: Johnzchgrd
  *
  *date: 2019/03/05
  *
  */

#include"sleep.h"
#include"fileio.c" 
#include"basiclib.c"
#include"create_new.c" 
#include"list.c"

/*
//具体修改程序
void make_right(FILE* dfptr, long offset){
	fseek(dfptr, offset,SEEK_SET);
	
}
//遍历刷新weeklysum
 */
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

main(){
  FILE*fp;
  int choice;//选项 
  char filename[11];//文件路径长度最大为11 
  printf("Enter file for data storage:\n");
  scanf("%11s",filename);
  
  while((choice = inputchoice())!=0){
    switch(choice){
      case 1:
        fp=openfile(filename,"ab+");
        newlog(fp);
        closefile(fp);
        break;
      case 2:
        fp=openfile(filename,"rb");
        listall(fp);
        closefile(fp);
        break;
      case 3:
      	fp=openfile(filename,"rb+");
        correction(fp);
        closefile(fp);
        break;
      default:
    printf("Invalid input!\n");
    }
    }
    
  return 0;

}

