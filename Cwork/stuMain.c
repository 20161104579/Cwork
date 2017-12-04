#include "stuHead.h"

int main()
{
	Student * stu= (Student *)malloc(sizeof(Student));
	stu->next = NULL;
	load(stu);
	while(1)
	{
		switch(menu_select())
		{
			case '1':
				input(stu);				
				break;
			case '2':
				update(stu);
				break;
			case '3':
				search(stu);
				break;
			case '4':
				del(stu);
				break;
			case '5':
				output(stu);
				break;
			case '0':
				save(stu);
				printf("Thank you for using£¡\n");
				system("pause");
				return 0;
		}
	}
}
