//#include"student.h"
extern Count;
//�޸ĳɼ�
void modify(struct student s[]){
	int num,course,score,i;
	printf("ѡ��Ҫ�޸ĵ�ѧ����ţ�");
	scanf("%d",&num);
	printf("ѡ��Ҫ�ĵĿ�Ŀ(1.��ѧ2.Ӣ��3.�����)��");
	scanf("%d",&course);
	printf("�������³ɼ���");
	scanf("%d",&score);
	//�޸Ĳ���
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
//����ѧ��
void search_student(struct student students[],int num){
	int i,flag=0;
	if(Count==0){
		printf("ѧ����������Ϊ�գ�");
		return;
	}
	for(i=0;i<Count;i++){
		if(students[i].num==num){
			flag=1;
			break;
		}
		if(flag){
			printf("��ţ�%d  ",students[i].num);
			printf("������%s  ",students[i].name);
			printf("��ѧ��%d  ",students[i].math);
			printf("Ӣ�%d  ",students[i].english);
			printf("�������%d  ",students[i].computer);
			printf("ƽ���֣�%d\n",students[i].average);
		}
		else printf("~���޴���~");
	}
}
