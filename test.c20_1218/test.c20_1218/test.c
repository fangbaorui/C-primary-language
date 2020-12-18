#define _CRT_SECURE_NO_WARNINGS
//结构体的使用
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	short age;
//};
//int main()
//{
//	struct Stu s = { "zhangsan",20 };
//	printf("%s %d\n", s.name, s.age);
//	printf("%s %d\n", (&s)->name, (&s)->age);
//	struct Stu* ps = &s;
//	printf("%s %d\n", ps->name, ps->age);
//	printf("%s %d\n", (*ps).name, (*ps).age);
//	return 0;//打印的结果都是一样的
//}


////打印1到100的奇数
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d ", i);
//		}
//		i+=2;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("未成年\n");
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("未成年\n");
//	else
//		printf("成年\n");
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("少年\n");
//	else if (age >= 18 && age < 30)
//		printf("青年\n");
//	else if (age >= 30 && age < 50)
//		printf("中年\n");
//	else if (age >= 50 && age < 100)
//		printf("老年\n");
//	else
//		printf("长寿\n");
//	return 0;
//}

////悬空else
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	if (b == 2)
//		printf("hehe\n");
//	else
//		printf("haha\n");
//	return 0;//什么都不打印，else与最近的if匹配
//}


//switch语句，解决多分支问题
//#include<stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期1\n");
//		break;
//	case 2:
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//	case 5:
//		printf("星期5\n");
//		break;
//	case 6:
//		printf("星期6\n");
//		break;
//	case 7:
//		printf("星期7\n");
//		break;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n)
//		{
//		case 1:
//			n++;
//		case 2: 
//			m++; n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//	}
//	printf("m=%d,n=%d\n", m, n);//5,3
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);  //1 2 3 4
//		i++;
//	}
//	return 0; 
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);  //1 2 3 4 
//		i++;
//	}
//	while (i <= 10);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);  //1 2 3 4 死循环，i一直等于4
//		i++;
//	} while (i <= 10);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//		putchar(ch);
//	return 0;
//}


////只打印数组字符
//#include<stdio.h>
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("请输入密码：");
//	scanf("%s", password);
//
//	//处理缓冲区多余的字符,把所有的字符全部获取到，避免在空格处断了
//	while (getchar() != '\n')
//	{
//		;
//	}
//	printf("请确定（Y/N):");
//	ch = getchar();
//	if ('Y' == ch)
//		printf("确认成功\n");
//	else
//		printf("放弃确认\n");
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);//0 1 2 3 4 6 7 8 9，不打印5
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i, j;
//	for (i = 0,j=0; i < 2&&j<5; i++,j++)
//	{
//		printf("hehe\n");//打印两个hehe
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	for (; ; )  //当判断部分省略，默认恒为真
//	{
//		printf("hehe\n");//死循环一直打印hehe
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)  //k=0,0为假，一次都不循环
//		k++;
//	return 0;
//}