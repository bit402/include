//#include<stdio.h>
//typedef struct stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//	int number;
//}stu;
//void print1(stu s)
//{
//	printf("%s\n", s.name);
//	printf("%d\n", s.age);
//	printf("%s\n", s.sex);
//	printf("%d\n", s.number);
//}
//void print2(stu* ps)
//{
//	printf("%s\n", ps->name);
//	printf("%d\n", ps->age);
//	printf("%s\n", ps->sex);
//	printf("%d\n", ps->number);
//}
//int main()
//{
//	struct stu s = { "张三",18,"男",888 };
//	print1(s);
//	print2(&s);
//	return 0;
//}
// 
//#include<stdio.h>
//int main()
//{
//	int a = 0x11223344;
//	return 0;
//	查看在内存中储存是大端存储还是小端存储
//}

//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//	{
//		printf("小端存储\n");
//	}
//	else
//	{
//		printf("大端存储\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int check_says()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int check_says()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	return *p;
//}
//int check_says()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int main()
//{
//	int ret = check_says();
//	if (ret == 1)
//	{
//		printf("小端存储");
//	}
//	else
//	{
//		printf("大端存储");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("%d,%d,%d", a, b, c);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char a = -128;
//	printf("%u", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a = 128;
//	printf("%u", a);
//	return 0;
//}