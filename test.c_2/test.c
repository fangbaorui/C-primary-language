////一个程序，判断某一年是否是闰年
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int leap_year = 0;
//	scanf("%d", &leap_year);
//	if((leap_year%4==0&&leap_year%100!=0)||(leap_year%400==0))
//	{
//		printf("%d is leap year\n", leap_year);
//	}
//	else
//	{
//		printf("%d is not leap year\n", leap_year);
//	}
//	return 0;
//}


////求ax^2+bx+c=0方程的根，要求处理任何的a，b，c的值
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c, disc, x1, x2, realpart, imagpart;//realpart实部，imagpart虚部
//	printf("please enter a,,b,c:\n");
//	scanf("%lf,%lf,%lf", &a, &b, &c);
//	if (fabs(a) < 1e-6)   //实数在计算和存储时会有一些微小的误差，因此不能直接等于0
//	{
//		printf("This is not a quadratic!\n");//a<1e-6认为不是二次方程
//		x1 = -c / b;
//		printf("x1=%8.4f\n", x1);
//	}
//	else   //二次方程
//	{
//		disc = b * b - 4 * a * c;
//		if (disc > 1e-6)    //b^2-4ac>0,有两个不相等的实根
//		{
//			x1 = (-b - sqrt(disc)) / (2 * a);
//			x2 = (-b + sqrt(disc)) / (2 * a);
//			printf("real roots:%8.4f and %8.4f\n", x1, x2);
//		}
//		else if (fabs(disc) < 1e-6)   //b^2-4ac=0,有两个相等的实根
//		{
//			printf("has two equal roots:%8.4f\n", -b / (2 * a));
//		}
//		else   //没有实根
//		{
//			realpart = -b / (2 * a);
//			imagpart = sqrt(-disc) / (2 * a);
//			printf("%8.4f+%8.4fi\n", realpart, imagpart);
//			printf("%8.4f-%8.4fi\n", realpart, imagpart);
//		}
//	}
//	return 0;
//}



////求圆周率的近似值
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n = 1;
//	float pi = 0;
//	float s = 1;
//	float t = 1;
//	while (fabs(t) > 1e-6)
//	{
//		pi = pi + t;//累加值
//		n = n + 2;  
//		s = -s;  //符号取反，保证一正一负
//		t = s/n;
//	}
//	pi = pi * 4;
//		printf("%f\n", pi);
//	return 0;
//}



////输出斐波那契数列前20项
//#include<stdio.h>
//int main()
//{
//	int f1 = 1;
//	int f2 = 1;
//	int i = 0;
//	for(i = 1; i <= 20; i++)
//	{
//		printf("%12d %12d", f1, f2);
//		if (i % 2 == 0)
//		{
//			printf("\n");
//		}
//		f1 = f1 + f2;
//		f2 = f2 + f1;
//	}
//	return 0;
//}


////把100-200范围内不能被3整除的数输出
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (i % 3 == 0)
//			continue;
//		else
//		{
//			printf("%d  ", i);
//		}
//		printf("\n");
//	}
//}



////判断整数m是否是素数
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	int k = 0;
//	int i = 0;
//	k = sqrt(m); //k等于根号下m
//	for (i = 2; i <= k; i++)
//	{
//		if (m % i == 0)
//		{
//			break;  //如果可以整除，说明不是素数
//		}
//	}
//	if (i > k)  //如果循环完i=k+1时，说明不能整除，就不是素数
//	{
//		printf("m is not a prime");
//	}
//	else
//	{
//		printf("m is a prime");
//	}
//	return 0;
//}



////求100-200的全部素数
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	int k = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		k = (int)sqrt(i);
//		for (j = 2; j <= k; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (j > k)
//		{
//			printf("%d  ", i);
//		}
//	}
//	return 0;
//}


////译密码，将字母A变成字母E，a变成e，即变成其后的第4个字母，W变成A，X变成B，Y变成C，Z变成D。
//#include<stdio.h>
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//		{
//			ch = ch + 4;
//			if ((ch <= 'Z'+4 &&ch > 'Z' )|| ch > 'z')
//			{
//				ch = ch - 26;
//			}
//		}printf("%c", ch);
//	}
//	return 0;
//}