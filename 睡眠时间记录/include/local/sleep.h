//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef __WIN32__
#include<windows.h>
#endif

#define MAXFILENAMELEN 100 //文件路径最大长度
struct sleepdata
{
	int logid;					  //编号
	char date[11];				  //日期
	double in_hour;				  //以小时计
	double period;				  //以睡眠周期计
	double sum7days;			  //7天总睡眠周期
	char create_date[20];		  //保存创建时间
	double tmp, tmp1, tmp2, tmp3; //暂时未想到的--预留24字节
};
extern long size; //储存sizeof(struct sleepdata)
//函数声明
int inputchoice(void);
FILE *openfile(char filename[], char *openmode);
void closefile(FILE *fp);
long getLogcount(FILE *cfptr);
double getprevHours(FILE *cfptr, int endid);
void createNewStructTo(struct sleepdata *sleeplog);
void newlog(FILE *cfptr);
void listall(FILE *cfptr);
void fresh(FILE *dfptr);
void correction(FILE *dfptr);
//time related functions-in
long getTimenow_long(void);
long getDatenow(void);
char *getTimenow_str(char Time[]);

//test functions-in "tests.c"
void getprevHours_test(FILE *fp, int IDfortest);