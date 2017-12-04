#include "stuHead.h"

char menu_select()
{
	char MenuItem;

	printf("\n ");
	printf("          | *********学生成绩管理系统********* |          \n");
	printf("          | ---------------------------------- |          \n");
	printf("          |              主菜单项              |          \n");
	printf("          | ---------------------------------- |          \n");
	printf("          |	  1 --- 录入学生信息  	       |          \n");
	printf("          |	  2 --- 修改学生信息	       |          \n");
	printf("          |	  3 --- 查询学生信息	       |          \n");
	printf("          |	  4 --- 删除学生成绩	       |          \n");
	printf("          |	  5 --- 显示学生信息	       |          \n");
	printf("          |	  0 --- 退出系统  	       |          \n");	
	
	do
	{		
		printf("\n请输入选项（0－5）：");
		fflush(stdin);
		scanf("%c",&MenuItem);
	}while(MenuItem<'0'||MenuItem>'5');

	return MenuItem;
}

void input(Student * stu)
{
     int i;
     char num[11];
     Student *rear,*p,*s;
     char cContinue;
     int flag=1;
     
     rear = stu;
     while(rear->next!=NULL)
     {
           rear = rear->next;
     }
     
     while (flag)
     {
          printf("请输入学生的学号：");
          scanf("%s",num);
          
		  p = stu->next;
          while(p!=NULL)
          {
		       if(strcmp(p->no,num)!=0)
		          p = p->next;
		       else
				  break;
          }
          
          if(p!=NULL)
          {
          	   printf("该学号已存在，请重新输入正确的学号！\n"); 
          	   flag = 1;
          	   continue;
          }
          else
          {
		       s = (Student *)malloc(sizeof(Student));
			   strcpy(s->no,num);
			   
			   printf("请输入学生的姓名：");
			   scanf("%s",s->name);
			   
			   for(i=0;i<MAXSUB;i++)
	           {
	                printf("请输入学生的第%d门课程的成绩：",i+1);
	                scanf("%d",&(s->score[i]));
	                if(s->score[i]>100||s->score[i]<0)
	                {
	                     printf("输入数据错误，请重新输入0-100之间的考试分数！\n");
	                     i--;
	                }
	           }
			   
			   s->sum=0;
	           for(i=0;i<MAXSUB;i++)
	                s->sum+=s->score[i];
	           s->average=(float)s->sum/MAXSUB;
	
	           s->next = NULL;
	           rear->next = s;
	           rear = s;
		          
	           fflush(stdin);
	           printf("需要继续录入吗？(Y/N)");			
	           scanf("%c",&cContinue);
	           switch(cContinue)
	           {
	                case 'Y':
					case 'y':
	                     flag = 1;
	                     break;
	                case 'N':
	 				case 'n':
	                     flag = 0;
	                     break;
	           }
          }
     }
}


void output(Student * stu)
{
     int i;
     Student * p = stu->next;
     printf("| 学号 |   姓名       | 成绩1 | 成绩2 | 成绩3 | 成绩4 | 总分  | 平均分|\n");
     printf("|------|--------------|-------|-------|-------|-------|-------|-------|\n");
     while (p!=NULL)
     {
           printf("|%-6s|%-14s|", p->no,p->name);
           for(i=0;i<MAXSUB;i++)
               printf("%7d|",p->score[i]);
           printf("%7d|%7.2f|\n",p->sum,p->average);
           p = p->next;
     }
}


void search(Student * stu)
{
    char menuItem;
    printf("	| ------------------------------------------------|\n");
    printf("	|                    查询子菜单项                 |\n");
    printf("	| ------------------------------------------------|\n");
    printf("	|                    1---按照学号查询             |\n");
    printf("	|                    2---按照姓名查询             |\n");
    printf("	|                    0---返回主菜单               |\n");
    printf("	| ------------------------------------------------|\n");
	do
	{
		printf("\n请输入菜单项数字(0-2):");
		fflush(stdin);
		scanf("%c",&menuItem);
	}while(menuItem<'0'||menuItem>'2');
	switch(menuItem)
	{
	    case '1':
		         searchByNo(stu);
		         break;
	    case '2':
		         searchByName(stu);
		         break;	
	}
}


Student * searchByNo(Student * stu)
{
    char num[11];
    int i;
	Student *p = stu->next;
	printf("请输入学生的学号：");
	scanf("%s",num);
	
	while (p!=NULL)
		if(strcmp(p->no,num)!=0)
		    p = p->next;
		else
			break;
	
	if(p==NULL)
		printf("您输入的学号不存在！\n");
	else
	{
		printf("| 学号 |   姓名       | 成绩1 | 成绩2 | 成绩3 | 成绩4 | 总分  | 平均分|\n");
		printf("|------|--------------|-------|-------|-------|-------|-------|-------|\n");
	    printf("|%-6s|%-14s|", p->no,p->name);
        for(i=0;i<MAXSUB;i++)
            printf("%7d|",p->score[i]);
        printf("%7d|%7.2f|\n",p->sum,p->average);
	}
	return p; 
}


Student * searchByName(Student * stu)
{
	char sname[20];
	int i;
	Student *p = stu->next;
	printf("请输入学生的姓名：");
	scanf("%s",sname);
	
	while (p!=NULL)
		if(strcmp(p->name,sname)!=0)
		    p = p->next;
		else
			break;
	
	if(p==NULL)
		printf("您输入的姓名不存在！\n");
	else
	{
		printf("| 学号 |   姓名       | 成绩1 | 成绩2 | 成绩3 | 成绩4 | 总分  | 平均分|\n");
		printf("|------|--------------|-------|-------|-------|-------|-------|-------|\n");
	    printf("|%-6s|%-14s|", p->no,p->name);
        for(i=0;i<MAXSUB;i++)
               printf("%7d|",p->score[i]);
        printf("%7d|%7.2f|\n",p->sum,p->average);
	}
	return p;
}


void update(Student * stu)
{
    char answer;
    int flag = 1,i;
    char num[11];
	Student *s = searchByNo(stu);
	Student *p;
	
	if(s!=NULL)
	{
		do
		{
			printf("是否修改以上信息？(Y/N)");
			fflush(stdin);
			scanf("%c",&answer);
		}while(answer!='Y'&&answer!='N'&&answer!='y'&&answer!='n');
		
		if(answer=='Y'||answer=='y')
		{
			while (flag)
			{
				printf("请重新输入学生的学号：");
				scanf("%s",num);
			
			    p = stu->next;
			    while(p!=NULL)
                {
				   if(strcmp(p->no,num)!=0)
		               p = p->next;
		           else
				       break;
                }
				
				if(p!=NULL)
                {
			         printf("该学号已存在，请重新输入正确的学号！\n"); 
          	         flag = 1;
          	         continue;
                }
                else
                {
			         strcpy(s->no,num);
					 printf("请重新输入学生的姓名：");
			         scanf("%s",s->name);
			   
			         for(i=0;i<MAXSUB;i++)
	                 {
	                    printf("请重新输入学生的第%d门课程的成绩：",i+1);
	                    scanf("%d",&(s->score[i]));
	                    if(s->score[i]>100||s->score[i]<0)
	                    {
	                         printf("输入数据错误，请重新输入0-100之间的考试分数！\n");
	                         i--;
	                    }
	                 }
	                 
	                 s->sum=0;
	                 for(i=0;i<MAXSUB;i++)
	                     s->sum+=s->score[i];
	                 s->average=(float)s->sum/MAXSUB;
	                 
	                 flag = 0;
	                 
	                 printf("\n修改后的学生信息如下：\n");
                     printf("| 学号 |   姓名       | 成绩1 | 成绩2 | 成绩3 | 成绩4 | 总分  | 平均分|\n");
                     printf("|------|--------------|-------|-------|-------|-------|-------|-------|\n");
                     printf("|%-6s|%-14s|", s->no,s->name);
                     for(i=0;i<MAXSUB;i++)
                         printf("%7d|",s->score[i]);
                     printf("%7d|%7.2f|\n",s->sum,s->average);
	            }
		    }
	    }
	}
}


void del(Student * stu)
{
    char answer;
	Student *s = searchByNo(stu);
	Student *pre;
	
	if(s!=NULL)
	{
		do
		{
			printf("是否删除以上信息？(Y/N)");
			fflush(stdin);
			scanf("%c",&answer);
		}while(answer!='Y'&&answer!='N'&&answer!='y'&&answer!='n');
		
		if(answer=='Y'||answer=='y')
		{
			pre = stu;
		    while (pre!=NULL)
		       if(strcmp(pre->next->no,s->no)!=0)
		          pre = pre->next;
		       else
		       {
                   pre->next = s->next;
                   printf("学生信息删除成功！");
                   break;
               }
		}
	}
}


void load(Student * stu)
{
	char no[12],name[20];
	int s[4];
	int i;
	Student *p,*q;
	FILE *fp;
	p=stu;
	fp=fopen("List.txt","r");
	if (fp==NULL)
	{
		printf("no information\n");
	}
	else
	{
		printf("information found(list.txt)");
		while (fscanf(fp,"%s %s %d %d %d %d",no,name,s[0],s[1],s[2],s[3])!=EOF)
	    {
		    q= (Student *)malloc(sizeof(Student));
		    strcpy(q->no,no);
		    strcpy(q->name,name);
		    for(i=0;i<4;i++)
		    	q->score[i]=s[i];
		    q->next=NULL;
            p->next=q;
            p=p->next;
     	}
	}
	fclose(fp);
}


void save(Student * stu)
{
	Student *p;
	FILE *fp;
	p= stu->next;
	fp=fopen("List.txt","w");
	if (fp==NULL)
	{
		printf("出现错误\n");
		exit(1);
	}
	while (p!=NULL)
	{
		fprintf(fp,"%s %s %d %d %d %d\n",p->no,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
		p = p->next;
	}
	fclose(fp);
    printf("save\n");
}
