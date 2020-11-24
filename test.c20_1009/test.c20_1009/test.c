
////字符指针
//#include<stdio.h>
//int main()
//{
//	//字符指针
//	char ch = 'a';
//	char* pc = &ch;//把ch的地址放在pc指针中
//	*pc = 'c';     //通过pc的地址，把'c'赋值给ch
//	printf("%c\n", *pc);//'c'
//
//	//常量字符串
//	char* str = "hello wrold";//GCC编译器会报错，没用const修饰不够严谨
//	const char* ptr = "hello wrold";  //str和ptr本质上是存了字符串的首地址
//	printf("%s\n", str);  //hello wrold
//	printf("%s\n",ptr);   //hello wrold
//
//	char* pstr = "hello world";
//	//*pstr = 'w';  //常量字符串不能被修改
//	printf("%s\n", pstr);
//
//	char arr[10] = "abcdef";
//	char* p = arr;
//	*p = 'w';  //数组可以改
//	printf("%s\n", p);//wbcdef
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	char arr1[] = "hello world";//数组
//	char arr2[] = "hello world";//数组
//	char* arr3 = "hello world"; //指针
//	char* arr4 = "hello world"; //指针
//	//C/C++会把常量字符串存储到单独的一个内存区域，当几个指针。指向同一个字符串的时候，他们实际会指向同一块内存。
//	//但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块。
//
//	if (arr1 == arr2)
//	{
//		printf("arr1==arr2");
//	}
//	else
//	{
//		printf("arr1!=arr2");
//	}
//	if (arr3 == arr4)
//	{
//		printf("arr3==arr4");
//	}
//	else
//	{
//		printf("arr3!=arr4");
//	}
//	return 0;
//}



////指针数组
//#include<stdio.h>
//int main()
//{
//	int* arr1[10];//整型指针数组:是一个数组，有10个元素，每个元素的类型是int*
//	char* arr2[4];//一级字符指针数组：是一个数组，有4个元素，每个元素的类型是char*
//	char** arr3[5];//二级字符指针数组：是一个数组，有5个元素，每个元素的类型是char**
//	return 0;
//}



////指针数组
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = { &a,&b,&c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", *(arr[i]));//*比[]优先级高
//	}
//	return 0;
//}



////指针数组
//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3 };
//	int arr2[] = { 2,3,4 };
//	int arr3[] = { 3,4,5 };
//	int* arr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");//1 2 3      2 3 4     3 4 5
//	}
//	return 0;
//}



////指针数组
//#include<stdio.h>
//int main()
//{
//	char* p1 = "zhangsan";
//	char* p2 = "lisi";
//	char* p3 = "wangwu";
//	char* arr[] = { p1,p2,p3 };
//	char* arr1[] = { "zhangsan","lisi","wangwu" };//和上面效果一样
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s\n", arr[i]);
//		printf("%s\n", arr1[i]);
//	}
//	return 0;
//}



////数组指针->能够指向数组的指针，类型如int(*p)[10],p先和*结合，表示p是一个指针变量，
////指向的是一个大小为10个整型的数组
//#include<stdio.h>
//int main()
//{
//	//数组指针=数组的地址，&数组名拿到的是数组的地址
//	char arr[5];
//	char (*pa)[5] = &arr;
//	char* ch[5];
//	char* (*pc)[5] = &ch;
//
//	int arr[3] = { 1,2,3 };
//	int* p = arr;//数组名是首元素地址
//	return 0;
//}


////数组指针
//#include<stdio.h>
//int main()
//{
//	//int* p3;
//	//p3 + 1;//跳过4个字节
//	//char* p4;
//	//p4 + 1;//跳过1个字节
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p1 = arr;
//	printf("%p\n", p1);//打印地址
//	printf("%p\n", p1+1);// p1 + 1,跳过一个元素的4个字节
//	printf("%p\n", arr+1);
//
//	int(*p2)[10] = &arr;//数组指针
//	printf("%p\n", p2);
//	printf("%p\n", p2+1);//p2+1，跳过整个数组
//	printf("%p\n", &arr+1);
//
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr);//三个打印结果一样
//
//	return 0;
//}



////数组指针的使用
//#include<stdio.h>
//void print1(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void print2(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr+i));
//		printf("%d ", arr[i]);//这两个打印结果一样
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	print1(arr, 10);
//	print2(arr, 10);
//	return 0;
//}



//#include<stdio.h>
////二位数组
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////数组指针
//void print2(int (*arr)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//			//printf("%d ", (*(p + i))[j]);
//			//printf("%d ", *(*(p + i) + j));//三个效果一样
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,0 };
//	print1(arr, 3, 5);
//	print2(arr, 3, 5);
//	return 0;
//}


////一维数组传参
//#include<stdio.h>
//void test1(int arr1[]) {}//可以
//void test1(int arr1[10]) {}//可以
//void test1(int* arr1) {}//可以
//void test2(int* arr2[10]) {}//可以
//void test2(int** arr2) {}//可以
//int main()
//{
//	int arr1[10] = { 0 };
//	int* arr2[10] = { 0 };
//	test1(arr1);
//	test2(arr2);
//	return 0;
//}


////二维数组传参
//#include<stdio.h>
//void test(int arr[3][5]) {}//可以
//void test(int arr[][5]) {}//可以
//void test(int arr[][]) {}//不可以
//void test(int* arr) {}//不可以
//void test(int* arr[5]) {}//不可以
//void test(int** arr) {}//不可以
//void test(int (*arr)[5]) {}//可以
//int main()
//{
//	int arr1[3][5] = { 0 };
//	test(arr);
//	return 0;
//}


////一级指针传参
//#include<stdio.h>
//void test(int* p){}
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int arr[10];
//	test(&a);//可以
//	test(p);//可以
//	test(arr);//可以
//  return 0;
//}


////二级指针传参
//#include<stdio.h>
//void test(int** p) {}
//int main()
//{
//	int* p1;
//	int** p2;
//	int* arr[10];
//	test(&p1);//可以
//	test(p2);//可以
//	test(arr);//可以
//	return 0;
//}


