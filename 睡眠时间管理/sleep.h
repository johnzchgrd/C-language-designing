#include<stdio.h>
#include<stdlib.h>

struct sleepdata{
	int logid;//编号
	char date[11];//日期
	double in_hour;//以小时计
	double period;//以睡眠周期计
	double sum7days;//7天总睡眠周期
};
long size = sizeof(struct sleepdata);  //储存sizeof(struct sleepdata)
