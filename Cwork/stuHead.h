#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSUB 4 

typedef struct Student
{	
	char no[12];	
	char name[20];  
	int score[MAXSUB];
	int sum;        
	float average;  
	struct Student * next;
}Student;

char menu_select();
void input(Student * stu);
void output(Student * stu);
void search(Student * stu);
Student * searchByNo(Student * stu);
Student * searchByName(Student * stu);
void update(Student * stu);
void del(Student * stu);
void load(Student * stu);
void save(Student * stu);
