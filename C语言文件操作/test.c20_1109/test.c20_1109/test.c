//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <limits.h>
//#include <ctype.h>

//enum State
//{
//	VALID,
//	INVALID
//}state = VALID;
//
//int my_atoi(const char* str)
//{
//	int flag = 0;
//	state = INVALID;
//	//��ָ��
//	if (str == NULL)
//		return 0;
//	if (*str == '\0')
//		return 0;
//
//	//�հ��ַ��Ĵ���
//	while (isspace(*str))
//	{
//		str++;
//	}
//	//+-
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	//
//	long long ret = 0;
//	//
//	//flag = -1
//	//
//	while (isdigit(*str))
//	{
//		ret = ret * 10 + flag*(*str - '0');
//		if (ret > INT_MAX || ret < INT_MIN)
//		{
//			ret = 0;
//			return (int)ret;
//		}
//		str++;
//	}
//	if (*str == '\0')
//	{
//		state = VALID;
//		return (int)ret;
//	}
//
//	return (int)ret;
//}
//
//
//int main()
//{
//	//""
//	char*p = "   @-123";
//	int ret = my_atoi(p);//-123
//	if (state == VALID)
//	{
//		printf("%d\n", ret);
//	}
//	else
//	{
//		printf("%d\n", ret);
//	}
//
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");  //"wb"������д
//	fwrite(&a, 4, 1, pf); //�����Ƶ���ʽд���ļ��У�4���ֽڣ�дһ�ε�pf��
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//FILE   //�һ�ת��������Բ鿴FILE�ṹ������


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	FILE* pFile;
//	pFile = fopen("myfile.txt", "w");//д�ķ�ʽ��һ���½��ļ�
//	if (pFile != NULL)  //�п�
//	{
//		fputs("fopen example", pFile);
//		fclose(pFile);  //�ر��ļ�
//	}
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int  main()
//{
//	FILE* pf = fopen("test1.txt", "w");  //���ļ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//д�ļ�,д���ļ���
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//	fputc('d', pf);
//	fputc('e', pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int  main()
//{
//	FILE* pf = fopen("test1.txt", "w");  //���ļ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	���ַ�qд����Ļ��
//	fputc('q', stdout);
//
//	�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int  main()
//{
//	FILE* pf = fopen("test1.txt", "r");  //���ļ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	 ch = fgetc(pf);
//	printf("%c\n", ch);
//	 ch = fgetc(pf);
//	printf("%c\n", ch);
//	 ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	FILE* pf = fopen("test1.txt", "w");
//	if (pf == NULL)
//	{
//		perror("open file for writting");
//		return 1;
//	}
//	//���ļ�����д�ַ���
//	fputs("hello bit\n",pf);
//	fputs("haha\n", pf);
//
//	fclose(pf);//�ر��ļ�
//	pf = NULL;
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	char input[20] = { 0 };
//	FILE* pf = fopen("test1.txt", "r");
//	if (pf == NULL)
//	{
//		perror("open file for reading");
//		return 1;
//	}
//	//������
//	fgets(input,20,pf);
//	printf("%s", input);
//
//	fgets(input, 20, pf);
//	printf("%s", input);
//
//	fclose(pf);//�ر��ļ�
//	pf = NULL;
//	return 0;
//}



//�����ļ����п���
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	FILE* pfRead = fopen("test1.txt", "r");
//	if (pfRead == NULL){
//		perror("open file for reading");
//		return 1;
//	}
//	FILE* pfWrite = fopen("test2.txt", "w");
//	if (pfWrite == NULL){
//		perror("open file for writting");
//		fclose(pfRead);
//		pfRead = NULL;
//		return 1;
//	}
//
//	//�ļ�����
//	int ch = 0;
//	while (ch = fgetc(pfRead) != EOF)
//	{
//		fputc(ch, pfWrite);
//	}
//
//	//�ر��ļ�
//	fclose(pfRead);
//	pfRead = NULL;
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = { "zhangsan", 20, 66.5f };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf, "%s %d %f", s.name, s.age, s.score);
//	fclose(pf);
//		pf = NULL;
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = {0};
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
//	printf( "%s %d %f\n", s.name, s.age, s.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}




//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = { "zhangsan", 20, 66.5f };
//	char str[100] = { 0 };
//	sprintf(str, "%s %d %f", s.name, s.age, s.score);
//	printf("%s %d %f\n", s.name, s.age, s.score);
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = { "zhangsan", 20, 66.5f };
//	struct Stu temp = {0};
//	char str[100] = { 0 };
//	sprintf(str, "%s %d %f", s.name, s.age, s.score);
//	sscanf(str, "%s %d %f", temp.name, &(temp.age),&(temp.score));
//	printf("%s %d %f\n", temp.name, temp.age, temp.score);
//	return 0;
//}




//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = {"����",20,99.2f };
//	FILE* pf = fopen("test.dat", "wb");
//	if (pf == NULL)
//	{
//		perror("open file for writting");
//		return 1;
//	}
//	//д�ļ�
//	fwrite(&s, sizeof(struct Stu), 1, pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = { 0 };
//	FILE* pf = fopen("test.dat", "rb");
//	if (pf == NULL)
//	{
//		perror("open file for reading");
//		return 1;
//	}
//	//���ļ�
//	fread(&s, sizeof(struct Stu), 1, pf);
//	printf("%s %d %f\n", s.name, s.age, a.score);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}




//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//	fputs("ABCDEF", pf);
//	fseek(pf, 4, SEEK_SET);
//	int ret = ftell(pf);
//	printf("ret=%d\n", ret);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}