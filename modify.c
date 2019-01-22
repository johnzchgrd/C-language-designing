//#include"student.h"
extern Count;
//修改成绩
void modify(struct student s[]){
	int num,course,score,i;
	printf("选择要修改的学生编号：");
	scanf("%d",&num);
	printf("选择要改的科目(1.数学2.英语3.计算机)：");
	scanf("%d",&course);
	printf("请输入新成绩：");
	scanf("%d",&score);
	//修改部分
	for(i=0;i<Count;i++){
		if(s[i].num==num)
		  break;
	}
	if(i<Count)
	  switch(course){
	  	case 1:s[i].math=score;break;
	  	case 2:s[i].english=score;break;
	  	case 3:s[i].computer=score;break;
	  }
}
//查找学生
void search_student(struct student students[],int num){
	int i,flag=0;
	if(Count==0){
		printf("学生数量不能为空！");
		return;
	}
	for(i=0;i<Count;i++){
		if(students[i].num==num){
			flag=1;
			break;
		}
		if(flag){
			printf("编号：%d  ",students[i].num);
			printf("姓名：%s  ",students[i].name);
			printf("数学：%d  ",students[i].math);
			printf("英语：%d  ",students[i].english);
			printf("计算机：%d  ",students[i].computer);
			printf("平均分：%d\n",students[i].average);
		}
		else printf("~查无此人~");
	}
}
