////unsigned char 类型越界成为负数的计算
////请问该程序输出是多少？
//#include <stdio.h>
//int main()
//{
//    unsigned char i = 7;
//    int j = 0;
//    for (; i > 0; i -= 3)
//    {
//        ++j;
//    }
//    printf("%d\n", j); //173
//        return 0;
//}
////由于i -= 3会将i置成负数，不过i为unsigned类型的，并没有负数，所有i会在0~255之间循环，
////所有当i为 - 2时，其真实值应该为254，当i为 - 1时，为255.因为循环条件为i > 0, 
////所有只有当i = 0时才不满足条件，跳出循环。



////下面两个结构体, 在#pragmapack(4)和#pragmapack(8)的情况下，结构体的大小分别
//#pragma pack(4) //默认对齐数修改成4
//struct One {
//	double d;  //0-7偏移
//	char c;    //8偏移
//	           //9-11偏移浪费
//	int i;     //12-15偏移
//};             //结构体one占16字节
//struct Two {
//	char c;    //0偏移
//	           //1-3偏移浪费
//	double d;  //4-11偏移
//	int i;     //12-15偏移
//};             //结构体two占16字节
//
//#pragma pack(8) //默认对齐数修改成8
//struct One {
//	double d;  //0-7偏移
//	char c;    //8偏移
//			   //9-11偏移浪费
//	int i;     //12-15偏移
//};             //结构体one占16字节
//struct Two {
//	char c;    //0偏移
//			   //1-3偏移浪费
//	double d;  //8-15偏移
//	int i;     //16-19偏移
//	           //20-23偏移浪费
//};             //结构体two占24字节



////若输入1abcedf2df<回车>
//#include<stdio.h>
//int main()
//{
//	char a = 0, ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if (a % 2 != 0 && (ch > -'a' && ch <= 'z'))
//			ch = ch - 'a' + 'A';
//		a++;
//		putchar(ch);  //输出1AbCeDf2df
//	}
//	printf("\n");
//}



//#include<stdio.h>
//void main()
//{
//	int a = -3;
//	//-3的原码  10000000000000000000000000000011
//	//-3的补码  11111111111111111111111111111101
//	unsigned int b = 2;
//	//2的补码   00000000000000000000000000000010
//	//相加得到  11111111111111111111111111111111   -1的补码
//	long c = a + b;
//	printf("%ld\n", c);//-1
//}


//int f(int x)
//{
//	return ((x > 2) ? x * f(x - 1) : 3); //把2带进去（(2 > 2) ? 2 * f(2 - 1) : 3）得到3，f（2）=3
//	//将f（2）=3代入（(3 > 2) ? 3 * f(3 - 1) : 3）得到9
//}
//int i;
//i = f(f(2));  //i的值为9



////fun(21)的运行结果是多少？10
//int fun(int a) {
//	a ^= (1 << 5) - 1;   //1<<5-1,将1左移5位-1得到
//	                     //11111
//	             //21的补码10101
//	        // 安位异或得到01010     10
//	return a;  
//}



////标题：Fibonacci数列 | 时间限制：1秒 | 内存限制：32768K
////Fibonacci数列是这样定义的：F[0] = 0,F[1] = 1
////foreachi≥2:F[i] = F[i - 1] + F[i - 2]
////因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一
////个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少
////需要多少步可以变为Fibonacci数。
////思路：找到目标数在那两个斐波那契数之间，然后左找右找，看离那个近
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int f1 = 0;
//	int f2 = 1;
//	int f3 = 0;
//	while (1)
//	{
//		if (f2 == a)    //相等时最小步数为0
//		{
//			printf("%d", 0);
//			break;
//		}
//		else if (f2 > a)   //f2大于a时就可以确定a在f1与f2之间
//		{
//			if (abs(f2 - a) > abs(f1 - a))   
//			{
//				printf("%d", abs(f1 - a));
//			}
//			else
//			{
//				printf("%d", abs(f2 - a));
//			}
//			break;
//		}
//		f3 = f1 + f2;  //斐波那契数递增
//		f1 = f2;    //递增
//		f2 = f3;    //递增
//	}
//	return 0;
//}




////标题：替换空格 | 时间限制：1秒 | 内存限制：32768K | 语言限制：
////请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。例如，当字符串为WeAreHappy.则经过替换之
////后的字符串为We % 20Are % 20Happy。
////思路：将每个空格改成三个字符%20，有n个空格，字符串长度要加2n个字节，
////在原数组上改动，必须从后向前赋值，否则会覆盖掉其他有效值
//class Solution {
//public:
//	void replaceSpace(char* str, int length) {
//		//计算空格的个数
//		int space_n = 0;
//		for (int i = 0; i < length; i++)
//		{
//			if (str[i] == ' ')
//				space_n++;
//		}
//		//从后往前，依次挪动字符，遇到空格替换成%20
//		int newlen = length-1 +2* space_n;  //计算修改后数组下标最大值
//		for (int i = newlen; i >= 0; i--)
//		{
//			if (str[i] == ' ')
//			{
//				str[newlen--] = '0';
//				str[newlen--] = '2';
//				str[newlen--] = '%';
//			}
//			else
//			{
//				str[newlen--] = str[i];
//			}
//		}
//	}
//};

