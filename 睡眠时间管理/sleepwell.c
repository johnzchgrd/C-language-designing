/*����ʵ�ֹ��ܣ�
 *1���½�˯��ʱ���¼*
 *2����ѯ����˯��ʱ���¼*
 *3���ж����һ�ܵ�˯��ʱ���Ƿ���   <35?  flag
 *4�����ݼ��ܱ���->�����㷨 
 *5�������ڽ�������
 *6��֧���޸��ض���ŵļ�¼* 
 *7��ˢ������*
 *8���Զ�����˯��ʱ��(�ɽ��֮ǰ�Ĵ���--һ��֮����ʱ��֮���������4λ����������Ҫ�Ż�)
 *9������ʶ�������ʽ�������Ƿ���ڵȣ� 
 *10���ռ�ģʽ/ҹ��ģʽת��* 
 *11�����ɴ���ʱ����޸�ʱ�� getdate����������20190304��int���ͣ�
 *12��֧�������ļ� 
 *13��֧�ָ�������
 *14������10���Զ�ת��
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
  int choice;//ѡ�� 
  int IDfortest;//������ 
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
      case 6://�����ýӿ� 
      	fp=openfile(filename,"rb");
		getprevHours_test(fp,IDfortest);
        closefile(fp);
        break;
      case 7:
	    system("color f0"); //�ռ� 
	    break;
	  case 8:
	  	system("color 07"); //ҹ�� 
	  	break;
      default:
        printf("Invalid input!\n");
    }
    }
    
  return 0;

}

