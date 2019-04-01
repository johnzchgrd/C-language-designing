//#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define MAXFILENAMELEN 100  //�ļ�·����󳤶�
struct sleepdata{
	int logid;//���
	char date[11];//����
	double in_hour;//��Сʱ��
	double period;//��˯�����ڼ�
	double sum7days;//7����˯������
	char create_date[20];//���洴��ʱ��
	double tmp,tmp1,tmp2,tmp3;//��ʱδ�뵽��--Ԥ��24�ֽ�
};
extern size; //����sizeof(struct sleepdata)
//��������
int inputchoice(void);
FILE* openfile(char filename[],char*openmode);
void closefile(FILE* fp);
long getLogcount(FILE*cfptr);
double getprevHours(FILE* cfptr, int endid);
void createNewStructTo(struct sleepdata* sleeplog);
void newlog(FILE*cfptr);
void listall(FILE*cfptr);
void fresh(FILE* dfptr); 
void correction(FILE* dfptr);
//time related functions-in 
long getTimenow_long(void);
long getDatenow(void);
char* getTimenow_str(char Time[]);

//test functions-in "tests.c"
void getprevHours_test(FILE* fp, int IDfortest);