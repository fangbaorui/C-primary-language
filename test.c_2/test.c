////һ�������ж�ĳһ���Ƿ�������
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


////��ax^2+bx+c=0���̵ĸ���Ҫ�����κε�a��b��c��ֵ
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c, disc, x1, x2, realpart, imagpart;//realpartʵ����imagpart�鲿
//	printf("please enter a,,b,c:\n");
//	scanf("%lf,%lf,%lf", &a, &b, &c);
//	if (fabs(a) < 1e-6)   //ʵ���ڼ���ʹ洢ʱ����һЩ΢С������˲���ֱ�ӵ���0
//	{
//		printf("This is not a quadratic!\n");//a<1e-6��Ϊ���Ƕ��η���
//		x1 = -c / b;
//		printf("x1=%8.4f\n", x1);
//	}
//	else   //���η���
//	{
//		disc = b * b - 4 * a * c;
//		if (disc > 1e-6)    //b^2-4ac>0,����������ȵ�ʵ��
//		{
//			x1 = (-b - sqrt(disc)) / (2 * a);
//			x2 = (-b + sqrt(disc)) / (2 * a);
//			printf("real roots:%8.4f and %8.4f\n", x1, x2);
//		}
//		else if (fabs(disc) < 1e-6)   //b^2-4ac=0,��������ȵ�ʵ��
//		{
//			printf("has two equal roots:%8.4f\n", -b / (2 * a));
//		}
//		else   //û��ʵ��
//		{
//			realpart = -b / (2 * a);
//			imagpart = sqrt(-disc) / (2 * a);
//			printf("%8.4f+%8.4fi\n", realpart, imagpart);
//			printf("%8.4f-%8.4fi\n", realpart, imagpart);
//		}
//	}
//	return 0;
//}



////��Բ���ʵĽ���ֵ
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
//		pi = pi + t;//�ۼ�ֵ
//		n = n + 2;  
//		s = -s;  //����ȡ������֤һ��һ��
//		t = s/n;
//	}
//	pi = pi * 4;
//		printf("%f\n", pi);
//	return 0;
//}



////���쳲���������ǰ20��
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


////��100-200��Χ�ڲ��ܱ�3�����������
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



////�ж�����m�Ƿ�������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	int k = 0;
//	int i = 0;
//	k = sqrt(m); //k���ڸ�����m
//	for (i = 2; i <= k; i++)
//	{
//		if (m % i == 0)
//		{
//			break;  //�������������˵����������
//		}
//	}
//	if (i > k)  //���ѭ����i=k+1ʱ��˵�������������Ͳ�������
//	{
//		printf("m is not a prime");
//	}
//	else
//	{
//		printf("m is a prime");
//	}
//	return 0;
//}



////��100-200��ȫ������
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


////�����룬����ĸA�����ĸE��a���e����������ĵ�4����ĸ��W���A��X���B��Y���C��Z���D��
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