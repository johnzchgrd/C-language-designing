#include"student.h"
#include"io.c"
#include"modify.c"
#include"aver_sort.c"
int Count=0;
main(void){
	struct student students[MaxSize];
	new_student(students);
	output_student(students);
	average(students);
	_sort(students);
	output_student(students);
	modify(students);
	average(students);
	output_student(students);
	system("pause");
	return 0;
}
