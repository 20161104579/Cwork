#include "stuHead.h"

char menu_select()
{
	char MenuItem;

	printf("\n ");
	printf("          | *********ѧ���ɼ�����ϵͳ********* |          \n");
	printf("          | ---------------------------------- |          \n");
	printf("          |              ���˵���              |          \n");
	printf("          | ---------------------------------- |          \n");
	printf("          |	  1 --- ¼��ѧ����Ϣ  	       |          \n");
	printf("          |	  2 --- �޸�ѧ����Ϣ	       |          \n");
	printf("          |	  3 --- ��ѯѧ����Ϣ	       |          \n");
	printf("          |	  4 --- ɾ��ѧ���ɼ�	       |          \n");
	printf("          |	  5 --- ��ʾѧ����Ϣ	       |          \n");
	printf("          |	  0 --- �˳�ϵͳ  	       |          \n");	
	
	do
	{		
		printf("\n������ѡ�0��5����");
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
          printf("������ѧ����ѧ�ţ�");
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
          	   printf("��ѧ���Ѵ��ڣ�������������ȷ��ѧ�ţ�\n"); 
          	   flag = 1;
          	   continue;
          }
          else
          {
		       s = (Student *)malloc(sizeof(Student));
			   strcpy(s->no,num);
			   
			   printf("������ѧ����������");
			   scanf("%s",s->name);
			   
			   for(i=0;i<MAXSUB;i++)
	           {
	                printf("������ѧ���ĵ�%d�ſγ̵ĳɼ���",i+1);
	                scanf("%d",&(s->score[i]));
	                if(s->score[i]>100||s->score[i]<0)
	                {
	                     printf("�������ݴ�������������0-100֮��Ŀ��Է�����\n");
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
	           printf("��Ҫ����¼����(Y/N)");			
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
     printf("| ѧ�� |   ����       | �ɼ�1 | �ɼ�2 | �ɼ�3 | �ɼ�4 | �ܷ�  | ƽ����|\n");
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
    printf("	|                    ��ѯ�Ӳ˵���                 |\n");
    printf("	| ------------------------------------------------|\n");
    printf("	|                    1---����ѧ�Ų�ѯ             |\n");
    printf("	|                    2---����������ѯ             |\n");
    printf("	|                    0---�������˵�               |\n");
    printf("	| ------------------------------------------------|\n");
	do
	{
		printf("\n������˵�������(0-2):");
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
	printf("������ѧ����ѧ�ţ�");
	scanf("%s",num);
	
	while (p!=NULL)
		if(strcmp(p->no,num)!=0)
		    p = p->next;
		else
			break;
	
	if(p==NULL)
		printf("�������ѧ�Ų����ڣ�\n");
	else
	{
		printf("| ѧ�� |   ����       | �ɼ�1 | �ɼ�2 | �ɼ�3 | �ɼ�4 | �ܷ�  | ƽ����|\n");
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
	printf("������ѧ����������");
	scanf("%s",sname);
	
	while (p!=NULL)
		if(strcmp(p->name,sname)!=0)
		    p = p->next;
		else
			break;
	
	if(p==NULL)
		printf("����������������ڣ�\n");
	else
	{
		printf("| ѧ�� |   ����       | �ɼ�1 | �ɼ�2 | �ɼ�3 | �ɼ�4 | �ܷ�  | ƽ����|\n");
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
			printf("�Ƿ��޸�������Ϣ��(Y/N)");
			fflush(stdin);
			scanf("%c",&answer);
		}while(answer!='Y'&&answer!='N'&&answer!='y'&&answer!='n');
		
		if(answer=='Y'||answer=='y')
		{
			while (flag)
			{
				printf("����������ѧ����ѧ�ţ�");
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
			         printf("��ѧ���Ѵ��ڣ�������������ȷ��ѧ�ţ�\n"); 
          	         flag = 1;
          	         continue;
                }
                else
                {
			         strcpy(s->no,num);
					 printf("����������ѧ����������");
			         scanf("%s",s->name);
			   
			         for(i=0;i<MAXSUB;i++)
	                 {
	                    printf("����������ѧ���ĵ�%d�ſγ̵ĳɼ���",i+1);
	                    scanf("%d",&(s->score[i]));
	                    if(s->score[i]>100||s->score[i]<0)
	                    {
	                         printf("�������ݴ�������������0-100֮��Ŀ��Է�����\n");
	                         i--;
	                    }
	                 }
	                 
	                 s->sum=0;
	                 for(i=0;i<MAXSUB;i++)
	                     s->sum+=s->score[i];
	                 s->average=(float)s->sum/MAXSUB;
	                 
	                 flag = 0;
	                 
	                 printf("\n�޸ĺ��ѧ����Ϣ���£�\n");
                     printf("| ѧ�� |   ����       | �ɼ�1 | �ɼ�2 | �ɼ�3 | �ɼ�4 | �ܷ�  | ƽ����|\n");
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
			printf("�Ƿ�ɾ��������Ϣ��(Y/N)");
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
                   printf("ѧ����Ϣɾ���ɹ���");
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
		printf("���ִ���\n");
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
