#define _CRT_SECURE_NO_WARNINGS

////��C�����У�static���������α����ͺ�����
////1.���ξֲ�����:static�ı��˾ֲ��������������ڣ��þ�̬�ֲ�����������������Ȼ���ڣ�
////����������������ڲŽ���
//#include<stdio.h>
//void test()
//{
//	int a = 1;
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}//��ӡ10��2
//	return 0;
//}
//
//
//#include<stdio.h>
//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}//��ӡ2��11
//	return 0;
//}

//////2.����ȫ�ֱ�����һ��ȫ�ֱ�����static���Σ�ʹ�����ȫ�ֱ���ֻ���ڱ�Դ�ļ���ʹ�ã�����������Դ�ļ���ʹ��
////add.c
//int a = 20;
////test.c
//int main()
//{
//	printf("%d", a);//����ʹ��
//	return 0;
//}
//
////add.c
//static int a = 20;
////test.c
//extern int a;
//int main()
//{
//	printf("%d", a);//������ʹ��
//	return 0;
//}

////3.static���κ�����ʹ���������ֻ���ڱ�Դ�ļ���ʹ�ã�����������Դ�ļ���ʹ��
////add.c
//int Add(int x, int y)
//{
//	return x + y;
//}
////test.c
//extern int Add(int x, int y);
//int main()
//{
//	printf("%d\n", Add(2, 3));//����ʹ��
//	return 0;
//}
//
//
////add.c
//static int Add(int x, int y)
//{
//	return x + y;
//}
////test.c
//extern int Add(int x, int y);
//int main()
//{
//	printf("%d\n", Add(2, 3));//������ʹ��
//	return 0;
//}






////typedef��ʹ��
//typedef unsigned int uint;
//int main()
//{
//	unsigned int a = 0;
//	uint b = 0;//b������Ҳ��unsigned int
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = ~a;
//	printf("%d\n", b);//-2
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 8;
//	int b = a << 1;//16
//	int c = a >> 1;//4
//	printf("%d,%d",b,c);
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	float a = 0;
//	a = 7 / 2;
//	printf("%f ", a);//3.500000
//	return 0;
//}


////�����ʹ��
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//		return 0;
//	}
//}



////дһ���������������Ľϴ�ֵ
//#include<stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("��������������>\n");
//	scanf("%d %d", &a, &b);
//	int ret = Add(a, b);
//	printf("%d\n", ret);
//	return 0;
//}



////дһ���������������Ľϴ�ֵ
//#include<stdio.h>
//int Max(int x, int y)
//{
//	if (x >= y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("��������������>\n");
//	scanf("%d %d", &a, &b);
//	int ret = Max(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

