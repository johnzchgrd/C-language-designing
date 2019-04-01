/*程序实现功能：
 *1、新建睡眠时间记录*
 *2、查询所有睡眠时间记录*
 *3、判断最近一周的睡眠时间是否达标   <35?  flag
 *4、数据加密保护->加密算法 
 *5、对日期进行排序
 *6、支持修改特定编号的记录* 
 *7、刷新数据*
 *8、自动计算睡眠时间(可借鉴之前的代码--一天之内两时间之差，输入两个4位数，不过需要优化)
 *9、智能识别输入格式（日期是否存在等） 
 *10、日间模式/夜间模式转换* 
 *11、生成创建时间和修改时间 getdate函数，返回20190304（int类型）
 *12、支持重载文件 
 *13、支持更改周期
 *14、功能10的自动转换
 */
 
 /*
  *author: Johnzchgrd
  *
  *create-date: 2019/03/05
  *
  */



#include"sleep.h" 

main(){
  FILE*fp;
  int choice;//选项 
  int IDfortest;//测试用 
  char filename[MAXFILENAMELEN], *today_in_hhmmss[20];
  printf("Today is:%s\n",getTimenow_str(today_in_hhmmss));
  printf("Enter file for data storage:\n");
  scanf_s("%s", filename, MAXFILENAMELEN);

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
      	fp=openfile(filename,"rb+");//need to change open mode for merging
        correction(fp);
        closefile(fp);
        break;
      case 4:
      	fp=openfile(filename,"rb");
        fresh(fp);
        closefile(fp);
        break;
      case 5:
	    printf("Enter new filename:\n");
        scanf_s("%s",filename,MAXFILENAMELEN);
        break;
      case 6://测试用接口 
      	fp=openfile(filename,"rb");
		getprevHours_test(fp,IDfortest);
        closefile(fp);
        break;
      case 7:
	    system("color f0"); //日间 
	    break;
	  case 8:
	  	system("color 07"); //夜间 
	  	break;
      default:
        printf("Invalid input!\n");
    }
    }
    
  return 0;

}

