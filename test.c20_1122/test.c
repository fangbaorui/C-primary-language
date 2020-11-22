#define _CRT_SECURE_NO_WARNINGS
////求最小公倍数
////1.给两个数A,B，用（A*i）%B=0,时就找到了(i从1增加到B)
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 1;
//	scanf("%d %d", &a, &b);
//	while (((a * i) % b )!= 0) //等于0就退出循环，就找到了
//	{
//		i++;
//	}
//	printf("%d\n", (a * i));
//	return 0;
//}

////2.一个数从a增加到a*b，如果可以同时整数两数，那么就找到了
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	for (i = a; i <=a * b; i++)
//	{
//		if ((i % a == 0) && (i % b == 0))
//		{
//			break;
//		}
//	}
//	printf("%d\n", i);
//	return 0;
//}

////3.两个数的乘积除以两数的最大公约数
////求一个数的最大公约数
////辗转相除法：1.将两数中较小值赋给b，2.a%b的值赋给c，若c等于0；则a为最大公约数，
////否则，a=b，b=c，继续a%b直到等于0
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int temp = 0;  
//	scanf("%d %d", &a, &b);
//	int n = a * b;
//	if (a < b)   //让b为两个中的较小值
//	{
//		temp = a;  //temp为临时变量，交换a，b的
//		a = b;
//		b = temp;
//	}
//	while (b!=0)
//	{
//		int c =a % b;  //c为b和a的求模
//		a = b;
//		b = c;
//	}
//	int m = n/ a;//a和b两数之积除以最大公约数
//	printf("%d\n", m);
//}


//#include<stdio.h>
//int main()
//{
//	int a, b, n, m;
//	int c, t;
//	printf("请输入两个数：\n");
//	scanf("%d %d", &a, &b);
//	n = a;
//	m = b;
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	while (b != 0)
//	{
//		c = a % b;
//		a = b;
//		b = c;
//	}
//	printf("两个数的最大公约数为：%d\n", a);
//	printf("两个数的最小公倍数为：%d\n", m * n / a);
//	return 0;
//}



////求两数的最大公约数
////1.把两数中的较大值赋值给m，求余i=m%n,
////判断余数是否为0，如果为0，则最大公因数为n，否则m=n;n=i;接着求余直到余数i为0，此时最大公因数为n。
//#include<stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	scanf("%d %d", &m, &n);
//	while (n!=0)
//	{
//		i = m % n;
//		m = n;
//		n = i;
//	}
//	printf("%d\n", m);
//	return 0;
//}


////2.如果a,b相等，最大公因数为两个数的任何一个，如果a>b时，a=a-b，b>a时，a=a-b，
////一直减到a=b时,最大公因数为a，b中一个
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	while (a != b)
//	{
//		if (a > b)
//			a = a - b;
//		else
//			b = b - a;
//	}
//		printf("%d\n", a);
//}


////3.输入两个值让a为较小值，让i从a到1计算，当a%i与b%i同时为0时，则i为最大公约数
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int temp = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		temp = a;
//		a = b;
//		b = temp;
//	}
//	int i = 0;
//		for(i = a; i >1; i--)
//		{
//			if ((a % i == 0) && (b % i == 0))
//			{
//				break;
//			}
//		}
//		printf("%d\n", i);
//		return 0;
//}