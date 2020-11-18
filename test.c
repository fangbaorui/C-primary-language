//预定义符号
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (i = 0; i < 10; i++)
//	{
//		printf("file:%s  line:%d  data:%s  time:%s  %d\n", \
//			__FILE__, __LINE__, __DATE__, __TIME__,arr[i]);
//		return 0;
//	}
//}


////预定义符号写入文件
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		perror("open file for writting!");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "file:%s  line:%d  date:%s  time:%s  %d\n", \
//			__FILE__, __LINE__, __DATE__, __TIME__, arr[i]);
//	}
//	fcloce(pf);
//	pf = NULL;
//	return 0;
//}



//#define定义标识符


//举个例子
//#define MAX 1000
//#define reg register       //register是个关键字创建一个简短的名字
//#define do_forever for(;;)     //用更形象的符号来替换一种实现
//#define CASE break;case        //在写case语句的时候自动把 break写上。
//// 如果定义的 stuff过长，可以分成几行写，除了最后一行外，每行的后面都加一个反斜杠(续行符)。续航符后面不能加空格，否则会被认为是转义字符
//#define DEBUG_PRINT printf("file:%s\tline:%d\t \
//                        date:%s\ttime:%s\n", \
//						 __FILE__, __LINE__, \


//#define MAX 1000;
//int a = MAX;   //->int a=1000;;   后面的分号是空语句


//在define定义标识符的时候，要不要在最后加上“；”？
//#include<stdio.h>
//#define MAX 1000;
//int main()
//{
//	int a = 5;
//	int b = 0;
//	if (a > 3)
//		b = MAX;
//	else
//		b = 10;
//	printf("%d", b);//会报错，if后面跟了两条语句，第二条为空语句，else没有匹配的if
//	return 0;
//}



//#defined宏定义
//#include<stdio.h>
//#define MAX(X,Y)  X>Y?X:Y  //参数无类型
//int Max(int X,int Y)  //函数参数有类型
//{
//	return X > Y ? X : Y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = Max(a,b); //20
//	printf("%d\n", max);
//	max = MAX(a, b);
//	printf("%d\n", max);  //20
//	return 0;
//}


//#include<stdio.h>
//#define SQUARE(X) X*X
////#define DOUBLE(X) X+X
//#define DOUBLE(X) (X+X)
//int main()
//{
//	printf("%d\n", SQUARE(5));  //25
//	printf("%d\n", SQUARE(4+1));  //9
//	//printf("%d\n",10*DOUBLE(5));  //55
//	printf("%d\n", 10 * DOUBLE(5)); //100
//	return 0;
//}



////使用 # ，把一个宏参数变成对应的字符串
//#include<stdio.h>
////#define PRINT(X) printf("the value of X is %d\n", X);
//#define PRINT(X) printf("the value of "#X" is %d\n", X);
//int main()
//{
//	int a = 100;
//	int b = 200;
//	//PRINT(a);  //the value of X is 100
//	//PRINT(b);//the value of X is 200
//	PRINT(a); //the value of a is 100
//	PRINT(b); //the value of b is 200
//	return 0;
//}


////使用 # ，把一个宏参数变成对应的字符串,把参数类型传进去
//#include<stdio.h>
//#define PRINT(FORMAT,X) printf("the value of "#X" is "FORMAT"\n", X);//可以八变量的类型传进去
//int main()
//{
//	float a = 99.9;
//	PRINT("%f",a); //the value of a is 99.900002
//	return 0;
//}



////##的作用
//#include<stdio.h>
//#define CAT(X,Y) X##Y
//int main()
//{
//	int zhangsanage = 20;
//	printf("%d\n", CAT(zhangsan,age));//20
//	return 0;
//}



////带副作用的宏参数  x+1不带副作用  ++x带副作用
//#include<stdio.h>
//#define MAX(X,Y)  ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int ret = ((a++) > (b++) ? (a++) : (b++));
//	printf("a=%d  b=%d\n", a, b); //11  13
//	printf("%d\n", ret);//12
//	return 0;
//}




////带副作用的宏参数  x+1不带副作用  ++x带副作用
//#include<stdio.h>
//#define MALLOC(num,type)  (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	if (p!=NULL)  //malloc开辟的空间要判空
//	return 0;
//	free(p);   // malloc开辟的空间要用free来释放
//	p = NULL;
//}


//#define name指令用于移除一个宏定义
#include<stdio.h>
#define MAX 100
int main()
{
	printf("%d\n",MAX);
#undef MAX
	//printf("%d\n", MAX);此处的宏定义已经被移除了
	return 0;
}