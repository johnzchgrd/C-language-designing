//#include"student.h"
extern Count;//ȫ�ֱ���-������
//����ѧ����Ϣ
void new_student(struct student students[]){
	int i,n;
	if(Count>MaxSize){
		printf("Too many Students!!!");
		return;
	}
	printf("������ѧ����(0~50)��");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("ѧ����ţ�");
		scanf("%d",&students[i].num);
		printf("������");
		scanf("%s",students[i].name);
		printf("��ѧ��");
		scanf("%d",&students[i].math);
		printf("Ӣ�");
		scanf("%d",&students[i].english);
		printf("�������");
		scanf("%d",&students[i].computer);
		Count++;
	}
}
//���ѧ����Ϣ
void output_student(struct student students[]){
	int i;
	if(Count==0){
		printf("��������Ϊ�գ�\n");
		return;
	}
	printf("���\t����\t��ѧ\tӢ��\t�����\tƽ��ֵ\n");
	for(i=0;i<Count;i++){
		printf("%d\t",students[i].num);
		printf("%s\t",students[i].name);
		printf("%d\t",students[i].math);
		printf("%d\t",students[i].english);
		printf("%d\t",students[i].computer);
		printf("%3.2f\n",students[i].average);
	}
}