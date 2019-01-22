//#include"student.h"
extern Count;
//计算个人平均成绩
void average(struct student s[]){
	int i;
	for(i=0;i<Count;i++){
		s[i].average=(s[i].math+s[i].english+s[i].computer)/3.0;
	}
}
//平均成绩排序
void _sort(struct student s[]){
	struct student tmp;
	int i,index,j;
	for(i=0;i<Count-1;i++){
		index=i;
		for(j=i+1;j<Count;j++){
			if(s[j].average>s[index].average)
			   index=j;
		}
		tmp=s[index];
		s[index]=s[i];
		s[i]=tmp;
	}
}
