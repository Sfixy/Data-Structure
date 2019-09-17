#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAXSIZE 1000
typedef int dataInt;
typedef char dataString;

//学生信息
typedef struct
{
	dataInt stu_id;
	dataInt stu_phone_num;
	dataInt age;
	dataString name[50];
}student_info;

//线性
typedef struct
{
	student_info number[MAXSIZE];
	int size;
}sequence_list;

//置空表
int CheckEmptyList(sequence_list *stu)
{
	return (stu->size == 0 ? 1 : 0);
}

//检查是否为空表
void EmptyList(sequence_list *stu)
{
	int check;
	stu->size = 0;
	check = CheckEmptyList(stu);
	if (check == 1)
	{
		printf_s("Sequence list is empty.\n");
		printf_s("End of program!\n");
	}
	else
	{
		printf_s("Sequence list is not empty.");
		printf_s("End of program!\n");
	}
}

//检查是否出现重复的学生id
int CheckStudentId(sequence_list* stu, int id)
{
	for (int i = 0; i < stu->size; i++)
	{
		if (stu->number[i].stu_id == id)
		{
			printf_s("This id already exists!\n");
			printf_s("Please input again.\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

//打印所有学生信息
void PrintStudentInfo(sequence_list* stu)
{
	for (int i = 0; i < stu->size; i++)
	{
		printf_s("name:%s	student_id:%d	age:%d	  telephone_number:%d\n", stu->number[i].name, stu->number[i].stu_id, stu->number[i].age, stu->number[i].stu_phone_num);
	}
}

//是否查看学生信息
void ViewStudentInfo(sequence_list* stu)
{

	char check;

	printf_s("Whether to view information about students\n");
	printf_s("Yes,please input y/Y.\n");
	printf_s("No,please input n/N.\n");
	
	getchar();

	while (true)
	{
		printf_s("Your operation: ");
		scanf_s("%c", &check, sizeof(check));
		if (check == 'Y' || check == 'y')
		{
			PrintStudentInfo(stu);
			printf_s("End of program!\n");
			break;
		}
		else if (check == 'N' || check == 'n')
		{
			printf_s("End of program!\n");
			break;
		}
		else
		{
			printf_s("Input error! Please input again.\n");
		}
	}
}

//增加学生
void AddStudentInfo(sequence_list* stu)
{

	int check;
	
	printf_s("name: ");
	scanf_s("%s", (stu->number[stu->size].name), sizeof(stu->number[stu->size].name));

	while (true)
	{
		int id;
		printf_s("student_id: ");
		scanf_s("%d", &id);
		check = CheckStudentId(stu, id);
		if (check == 0)
		{
			stu->number[stu->size].stu_id = id;
			break;
		}
		else if (check == 1)
		{
			continue;
		}
	}

	printf_s("age: ");
	scanf_s("%d", &stu->number[stu->size].age);

	printf_s("telephone_number: ");
	scanf_s("%d", &stu->number[stu->size].stu_phone_num);

	stu->size++;
}

//指定位置增加学生
void AddStudentInfo(sequence_list* stu,int postion)
{
	int check;

	printf_s("name: ");
	scanf_s("%s", (stu->number[postion-1].name), sizeof(stu->number[postion-1].name));

	while (true)
	{
		int id;
		printf_s("student_id: ");
		scanf_s("%d", &id);
		check = CheckStudentId(stu, id);
		if (check == 0)
		{
			stu->number[postion - 1].stu_id = id;
			break;
		}
		else if (check == 1)
		{
			continue;
		}
	}
	
	
	printf_s("age: ");
	scanf_s("%d", &stu->number[postion-1].age);

	printf_s("telephone_number: ");
	scanf_s("%d", &stu->number[postion-1].stu_phone_num);

	stu->size++;
}

//在末尾增加学生
void AppendStudent(sequence_list* stu)
{
	int num;
	printf_s("How many student that you want to add?\n");
	printf_s("Please input number: ");
	scanf_s("%d", &num);

	if (num + (stu->size) >= MAXSIZE)
	{
		printf_s("Student number out of range.\n");
		printf_s("Please exit\n");
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			AddStudentInfo(stu);
		}
	}
	ViewStudentInfo(stu);
}

//获取指定学生信息
void GetStudent(sequence_list* stu, int i)
{
	if (i > stu->size)
	{
		printf_s("Don't have this student!");
	}
	else
	{
		printf_s("name:%s	student_id:%d	age:%d	  telephone_number:%d\n", stu->number[i-1].name, stu->number[i-1].stu_id, stu->number[i-1].age, stu->number[i-1].stu_phone_num);
	}
}

//在指定位置插入一个学生
void InsertStudent(sequence_list* stu,int postion)
{
	if (stu->size == MAXSIZE)
	{
		printf_s("Can not insert,the list is full.\n");
		printf_s("End of program!\n");
	}
	else if (postion < 0 || postion > stu->size)
	{
		printf_s("Insert position does not exist.");
		printf_s("End of program!\n");
	}
	else
	{
		for (int i = stu->size; i >= postion; i--)
		{
			stu->number[i] = stu->number[i - 1];
		}
		AddStudentInfo(stu, postion);
	}
	ViewStudentInfo(stu);
}

//删除一个学生
void DeleteStudent(sequence_list* stu, int postion)
{
	if (stu->size == 0)
	{
		printf_s("No students\n");
		printf_s("Can't delete!\n");
		printf_s("End of program!\n");
	}
	else if (postion < 0 || postion > stu->size)
	{
		printf_s("Delete location does not exist!\n");
		printf_s("End of program!\n");
	}
	else
	{
		for (int i = postion; i < stu->size; i++)
		{
			stu->number[i] = stu->number[i + 1];
		}
		stu->size--;
		ViewStudentInfo(stu);
	}
}

//初始化操作
void Init(sequence_list *stu,int length)
{
	int button;
	int i = 1;
	int check;
	int postion;
	stu->size = 0;
	while (true)
	{
		printf_s("Please input %d number of student.\n", i);
		AddStudentInfo(stu);

		i++;
		if (i-1 == length)
		{
			printf_s("Input completed\n");
			printf_s("If you will continue operation,please input 1\n");
			printf_s("Exit,please input 0\n");
			scanf_s("%d", &button);
			switch (button)
			{
			case 1:
				printf_s("view information of student,please input 0\n");
				printf_s("Add students,please input 1\n");
				printf_s("Find a student,please input 2\n");
				printf_s("Clean list,please input 3\n");
				printf_s("Insert a student,please input 4\n");
				printf_s("Delete a student,please input 5\n");
				printf_s("Your operation: ");
				scanf_s("%d", &check);
				if (check == 0)
				{
					PrintStudentInfo(stu);
					printf_s("End of program!\n");
				}
				else if (check == 1)
				{
					AppendStudent(stu);
				}
				else if (check == 2)
				{
					int a;
					printf_s("Please input number of a student that you would like to find.\n");
					printf_s("Number: ");
					scanf_s("%d", &a);
					GetStudent(stu, a);
					printf_s("End of Program!\n");
				}
				else if (check == 3)
				{
					EmptyList(stu);
				}
				else if (check == 4)
				{
					printf_s("Please Inserted postion that you want to insert.\n");
					printf_s("Postion: ");
					scanf_s("%d",&postion);
					InsertStudent(stu, postion);
				}
				else if (check == 5)
				{
					printf_s("Please deleted postion that you want to delete.\n");
					printf_s("Postion: ");
					scanf_s("%d",&postion);
					DeleteStudent(stu, postion);
				}
				else
				{
					printf_s("No such operation!\n");
					printf_s("End of program!\n");
				}
				break;
			case 0:
				exit(0);
				break;
			default:
				break;
			}
			break;
		}
	}
}

int main()
{
	sequence_list* stu;
	int length;

	printf_s("How many student in your class?\n");
	printf_s("Please input number of student.\n");
	printf_s("Number: ");

	while (true)
	{
		scanf_s("%d", &length);

		if (length > MAXSIZE)
		{
			printf_s("Out of range!\n");
			printf_s("You don't have so many students\n");
			printf_s("Please input again\n");
		}
		else
		{
			stu = (sequence_list*)malloc(sizeof(sequence_list));
			Init(stu, length);
		}
	}
	system("pause");
	return 0;
}