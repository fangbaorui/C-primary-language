#define _CRT_SECURE_NO_WARNINGS

////在C语言中，static是用来修饰变量和函数的
////1.修饰局部变量:static改变了局部变量的生命周期，让静态局部变量处理作用域依然存在，
////到程序结束生命周期才结束
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
//	}//打印10个2
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
//	}//打印2到11
//	return 0;
//}

//////2.修饰全局变量：一个全局变量被static修饰，使得这个全局变量只能在本源文件内使用，不能在其他源文件内使用
////add.c
//int a = 20;
////test.c
//int main()
//{
//	printf("%d", a);//可以使用
//	return 0;
//}
//
////add.c
//static int a = 20;
////test.c
//extern int a;
//int main()
//{
//	printf("%d", a);//不可以使用
//	return 0;
//}

////3.static修饰函数：使得这个函数只能在本源文件内使用，不能在其他源文件内使用
////add.c
//int Add(int x, int y)
//{
//	return x + y;
//}
////test.c
//extern int Add(int x, int y);
//int main()
//{
//	printf("%d\n", Add(2, 3));//可以使用
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
//	printf("%d\n", Add(2, 3));//不可以使用
//	return 0;
//}






////typedef的使用
//typedef unsigned int uint;
//int main()
//{
//	unsigned int a = 0;
//	uint b = 0;//b的类型也是unsigned int
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


////数组的使用
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



////写一个函数求两个数的较大值
//#include<stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数：>\n");
//	scanf("%d %d", &a, &b);
//	int ret = Add(a, b);
//	printf("%d\n", ret);
//	return 0;
//}



////写一个函数求两个数的较大值
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
//	printf("请输入两个数：>\n");
//	scanf("%d %d", &a, &b);
//	int ret = Max(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

