////����ָ��
////����ָ����ָ������ָ�룬�������Ǻ����ĵ�ַ��&���������Ǻ����ĵ�ַ��
//#include<stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);//�������Ǻ����ĵ�ַ
//	printf("%p\n", &test);&���������Ǻ����ĵ�ַ,�������һ��
//	return 0;
//}


////����ָ���ʹ��
//#include<stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int my_strlen(const char* str)
//{
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int (*ps)(const char*) = &my_strlen;
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//
//	//int(*p)[10] = &Add;//ȡ������ĵ�ַ��p��������ָ��
//	//����ָ����һ��ָ������ָ��->��ź����ĵ�ַ
//	//int (*p)(int, int) = &Add;
//	int (*p)(int, int) = Add;
//	int sum = Add(2, 3);
//	printf("%d\n", sum);//5
//	int num = (*p)(2, 3);
//	printf("%d\n", num);//5
//	int a = p(2, 3);
//	printf("%d\n", a);//5
//
//	return 0;
//}



////����ָ���ʹ��
//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)  //char* my_strcpy,char*����Ҫ�����ַ�ָ��
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;   //��ָ��ret��¼dest�ַ�������ʼ��ַ
//	while (*dest++ = *src++) //++���ȼ�����*��srt++�����õ�\0��ֵ��dest������ѭ��
//	{
//		;
//	}
//	return ret;  //����dest����ʼ��ַ
//}
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hehe";
//	char* (*pf)(char*, const char*) = &my_strcpy;
//	(*pf)(arr1, arr2); //����ָ�����
//	printf("%s\n", arr1);
//	return 0;
//}



////����ָ�����飺��ŵ��Ǻ���ָ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//#include<stdio.h>
//int main()
//{
//	//����ָ��
//	int (*pf1)(int, int) = Add;
//	int (*pf2)(int, int) = Sub;
//
//	//����ָ������
//	int (*pf[4])(int, int) = { Add,Sub };
//	return 0;
//}




////������1
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("***** 1.add         2.sub  *******\n");
//	printf("***** 3.mul         4.div  *******\n");
//	printf("*****     0.exit           *******\n");
//	printf("**********************************\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)  //�����ǳ���Ϊ0
//{
//	return x / y;
//}
//int main()
//{
//	int x = 0; 
//	int y = 0;
//	int input = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("����������������\n");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("����������������\n");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("����������������\n");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("����������������\n");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}



////������2   ʹ��ת�Ʊ�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("***** 1.add         2.sub  *******\n");
//	printf("***** 3.mul         4.div  *******\n");
//	printf("*****     0.exit           *******\n");
//	printf("**********************************\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)  //�����ǳ���Ϊ0
//{
//	return x / y;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	int ret = 0;
//
//	//ת�Ʊ�->����ָ���������;
//	int (*pfarr[])(int, int) = { 0,add,sub,mul,div };
//	do
//	{
//		menu();
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("�˳�������\n");
//			break;
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("����������������\n");
//			scanf("%d %d", &x, &y);
//			ret = pfarr[input](x, y);
//			printf("����ǣ�%d\n", ret);
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//		
//	} while (input);
//	return 0;
//}




////ָ��  ����ָ������  ��ָ��
//int main()
//{
//	int (*p)(int, int);//����ָ��
//	int (*pfarr[5])(int, int);//����ָ������
//	int (*(*ppfarr)[5])(int, int) = &pfarr;//[]�����д�ɲ�д
//	return 0;
//}




////������3  ���ûص�����
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("***** 1.add         2.sub  *******\n");
//	printf("***** 3.mul         4.div  *******\n");
//	printf("*****     0.exit           *******\n");
//	printf("**********************************\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)  //�����ǳ���Ϊ0
//{
//	return x / y;
//}
//void calc(int (*pf)(int x, int y))//void calc(int (*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("����������������\n");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);
//	printf("%d\n", ret);
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(add);
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(div);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}