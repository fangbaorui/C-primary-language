#define _CRT_SECURE_NO_WARNINGS
//�ṹ���ʹ��
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
//	return 0;//��ӡ�Ľ������һ����
//}


////��ӡ1��100������
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
//		printf("δ����\n");
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("δ����\n");
//	else
//		printf("����\n");
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("����\n");
//	else if (age >= 18 && age < 30)
//		printf("����\n");
//	else if (age >= 30 && age < 50)
//		printf("����\n");
//	else if (age >= 50 && age < 100)
//		printf("����\n");
//	else
//		printf("����\n");
//	return 0;
//}

////����else
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
//	return 0;//ʲô������ӡ��else�������ifƥ��
//}


//switch��䣬������֧����
//#include<stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("����1\n");
//		break;
//	case 2:
//		printf("����2\n");
//		break;
//	case 3:
//		printf("����3\n");
//		break;
//	case 4:
//		printf("����4\n");
//		break;
//	case 5:
//		printf("����5\n");
//		break;
//	case 6:
//		printf("����6\n");
//		break;
//	case 7:
//		printf("����7\n");
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
//		printf("%d ", i);  //1 2 3 4 ��ѭ����iһֱ����4
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


////ֻ��ӡ�����ַ�
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
//	printf("���������룺");
//	scanf("%s", password);
//
//	//��������������ַ�,�����е��ַ�ȫ����ȡ���������ڿո񴦶���
//	while (getchar() != '\n')
//	{
//		;
//	}
//	printf("��ȷ����Y/N):");
//	ch = getchar();
//	if ('Y' == ch)
//		printf("ȷ�ϳɹ�\n");
//	else
//		printf("����ȷ��\n");
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
//		printf("%d ", i);//0 1 2 3 4 6 7 8 9������ӡ5
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i, j;
//	for (i = 0,j=0; i < 2&&j<5; i++,j++)
//	{
//		printf("hehe\n");//��ӡ����hehe
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	for (; ; )  //���жϲ���ʡ�ԣ�Ĭ�Ϻ�Ϊ��
//	{
//		printf("hehe\n");//��ѭ��һֱ��ӡhehe
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)  //k=0,0Ϊ�٣�һ�ζ���ѭ��
//		k++;
//	return 0;
//}