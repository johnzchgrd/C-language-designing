//#include"student.h"
extern Count;//全局变量-总人数
//输入学生信息
void new_student(struct student students[]){
	int i,n;
	if(Count>MaxSize){
		printf("Too many Students!!!");
		return;
	}
	printf("请输入学生数(0~50)：");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("学生编号：");
		scanf("%d",&students[i].num);
		printf("姓名：");
		scanf("%s",students[i].name);
		printf("数学：");
		scanf("%d",&students[i].math);
		printf("英语：");
		scanf("%d",&students[i].english);
		printf("计算机：");
		scanf("%d",&students[i].computer);
		Count++;
	}
}
//输出学生信息
void output_student(struct student students[]){
	int i;
	if(Count==0){
		printf("人数不能为空！\n");
		return;
	}
	printf("编号\t姓名\t数学\t英语\t计算机\t平均值\n");
	for(i=0;i<Count;i++){
		printf("%d",students[i].num);
		printf("%s",students[i].name);
		printf("%d",students[i].math);
		printf("%d",students[i].english);
		printf("%d",students[i].computer);
		printf("%d",students[i].average);
	}
}
