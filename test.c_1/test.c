////��һ��������ʵ�������������нϴ���
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int max(int a, int b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d %d", &x, &y);
//	int ret = max(x, y);
//	printf("%d\n", ret);
//	return 0;
//}


////��5���Լ�1��+2��+3��+4��+5��
////��һ��������ʵ�������������нϴ���
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main()
//{
//	int i = 1;
//	int n = 1;
//	int num = 0;
//	for (i = 1; i <= 5; i++)
//	{
//		n = n * i;
//		num = num + n;
//	}
//	printf("%d\n", n);//5!
//	printf("%d\n", num);//1��+2��+3��+4��+5��
//	return 0;
//}


////�������������߳��������������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	float a = 0;
//	float b = 0;
//	float c = 0;
//	double area = 0;
//	scanf("%f %f %f", &a, &b, &c);
//	float s = (a + b + c) / 2;
//	area = sqrt(s * (s - a) * (s - b) * (s - c));
//	printf("a=%f\n b=%f\n c=%f\n area=%f\n",a,b,c,area );
//	return 0;
//}


////�й���2010��11��1�յ�����ȫ���˿��ղ飬ȫ���˿�Ϊ1370536875�ˣ�������������Ϊ0.5%�����㵽2050���ж�����
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double pi = 1370536875;//�˿ڻ���
//	double pl = 0;//2050���˿���
//	int year = 2050 - 2010;
//	double r = 0.005;
//	pl = pi * pow(1 + r, year);
//	printf("%lf\n", pl);
//	return 0;
//}


////��ax^2+bx+c=0���̵ĸ����ɼ�������a��b��c����b^-4ac>0
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a = 0;
//	double b = 0;
//	double c = 0;
//	double d = 0;
//	double p = 0;
//	double q = 0;
//	double x1 = 0;
//	double x2 = 0;
//	scanf("%lf %lf %lf", &a,&b,&c);
//	d = b * b - 4 * a * c;
//	q = (-b) / (2 * a);
//	p = sqrt(q) / (2 * a);
//	x1 = q - p;
//	x2 = q + p;
//	printf("x1=%f x2=%f\n", x1,x2);
//	return 0;
//}



////getchar,putchar��Ӧ��
//#include<stdio.h>
//int main()
//{
//	char a='B';
//	char b = 'O';
//	char c = 'Y';
//	putchar(a);
//	putchar(b);
//	putchar(c);
//	putchar('\n');
//	putchar('a');
//	putchar('b');
//	putchar('c');
//	return 0;	
//}

//#include<stdio.h>
//int main()
//{
//	char a, b, c;
//	a = getchar();
//	b = getchar();
//	c = getchar();
//	putchar(a);
//	putchar(b);
//	putchar(c);
//	putchar('\n');
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	putchar(getchar());
//	putchar(getchar());
//	putchar(getchar());
//	putchar('\n');
//	return 0;
//}




////�����������������С�������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	int tmp = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a > c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b > c)
//	{
//		tmp = c;
//		c = b;
//		b = tmp;
//	}
//	printf("%d,%d,%d\n", a, b, c);
//	return 0;
//}


////����һ���ַ����б����Ƿ��Ǵ�д��ĸ������ǣ�����ת����Сд��ĸ��������ǣ���ת����Ȼ�����
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch >= 'A' && ch <= 'Z')
//		ch = ch + 32;
//	printf("%c", ch);
//	return 0;
//}


//Ҫ���տ��Գɼ��ĵȼ�����ٷ��Ʒ����Σ�AΪ85�����ϣ�BΪ70-84�֣�CΪ60-69�֣�
//D��Ϊ60�����¡��ɼ��ȼ��ɼ�������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char grade;
	scanf("%c", &grade);
	switch (grade)
	{
	    case 'A':
			printf("85-100��\n");
			break;
		case 'B': 
			printf("70-84��\n");
			break;
		case 'C':
			printf("60-69��\n");
			break;
		case 'D':
			printf("0-60��\n");
			break;
		default:
			printf("data error!\n");
	}
	return 0;
}
