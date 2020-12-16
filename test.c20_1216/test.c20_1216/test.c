#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	//32位平台下
//	printf("%d\n", sizeof(char));//1
//	printf("%d\n", sizeof(short));//2
//	printf("%d\n", sizeof(int));//4
//	printf("%d\n", sizeof(long));//4
//	printf("%d\n", sizeof(long long));//8
//	printf("%d\n", sizeof(float));//4
//	printf("%d\n", sizeof(double));//8
//	printf("%d\n", sizeof(long double));//8
//	return 0;
//}


////1）字面常量
//100;
//'a';
////2）const修饰的常变量
//const int a = 10;
//a = 20;//错误，a不能被修改
//const int n = 10;
//arr[n] = { 0 };//错误，方括号中放常量
////3）#define定义的标识符常量
//#define num 100
//num = 200;//错误，常量不能被修改;
////4）枚举常量
//enum Sex
//{
//	MALE,  //0
//	FEMALE,  //1
//	SECRET  //2
//};
//MALE = 10;//错误，常量不可被修改
//enum Sex
//{
//	MALE,  //0
//	FEMALE=5,  //5
//	SECRET  //6
//};


//#include <stdio.h>
////下面代码，打印结果是什么？为什么？（突出'\0'的重要性）
//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = { 'b', 'i', 't' };
//	char arr3[] = { 'b', 'i', 't', '\0' };
//	printf("%s\n", arr1);//bit
//	printf("%s\n", arr2);//bit+随机值，没有'\0'作为结束标志
//	printf("%s\n", arr3);//bit
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	printf("c:\code\test.c\n");//c:code  est.c
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	printf("%d\n", strlen("c:\test\328\test.c"));//14   ,/328被看做是/32 和8，因为八进制数字里面没有8
//	return 0;
//}


/*int a=10;
/*int b=20;
*/
int c = 30;//嵌套不能注释这一行
*/