////函数指针
////函数指针是指向函数的指针，函数名是函数的地址，&函数名还是函数的地址。
//#include<stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);//函数名是函数的地址
//	printf("%p\n", &test);&函数名还是函数的地址,两个结果一样
//	return 0;
//}


////函数指针的使用
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
//	//int(*p)[10] = &Add;//取出数组的地址，p就是数组指针
//	//函数指针是一个指向函数的指针->存放函数的地址
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



////函数指针的使用
//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)  //char* my_strcpy,char*类型要返回字符指针
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;   //用指针ret记录dest字符串的起始地址
//	while (*dest++ = *src++) //++优先级高于*，srt++解引用到\0赋值给dest，结束循环
//	{
//		;
//	}
//	return ret;  //返回dest的起始地址
//}
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hehe";
//	char* (*pf)(char*, const char*) = &my_strcpy;
//	(*pf)(arr1, arr2); //函数指针调用
//	printf("%s\n", arr1);
//	return 0;
//}



////函数指针数组：存放的是函数指针
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
//	//函数指针
//	int (*pf1)(int, int) = Add;
//	int (*pf2)(int, int) = Sub;
//
//	//函数指针数组
//	int (*pf[4])(int, int) = { Add,Sub };
//	return 0;
//}




////计算器1
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
//int div(int x, int y)  //不考虑除数为0
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
//		printf("请选择\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数\n");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("请输入两个操作数\n");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("请输入两个操作数\n");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("请输入两个操作数\n");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}



////计算器2   使用转移表
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
//int div(int x, int y)  //不考虑除数为0
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
//	//转移表->函数指针数组的用途
//	int (*pfarr[])(int, int) = { 0,add,sub,mul,div };
//	do
//	{
//		menu();
//		printf("请选择\n");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//			break;
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数\n");
//			scanf("%d %d", &x, &y);
//			ret = pfarr[input](x, y);
//			printf("结果是：%d\n", ret);
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//		
//	} while (input);
//	return 0;
//}




////指向  函数指针数组  的指针
//int main()
//{
//	int (*p)(int, int);//函数指针
//	int (*pfarr[5])(int, int);//函数指针数组
//	int (*(*ppfarr)[5])(int, int) = &pfarr;//[]里面可写可不写
//	return 0;
//}




////计算器3  利用回调函数
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
//int div(int x, int y)  //不考虑除数为0
//{
//	return x / y;
//}
//void calc(int (*pf)(int x, int y))//void calc(int (*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("请输入两个操作数\n");
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
//		printf("请选择\n");
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
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}