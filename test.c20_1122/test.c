#define _CRT_SECURE_NO_WARNINGS
////����С������
////1.��������A,B���ã�A*i��%B=0,ʱ���ҵ���(i��1���ӵ�B)
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 1;
//	scanf("%d %d", &a, &b);
//	while (((a * i) % b )!= 0) //����0���˳�ѭ�������ҵ���
//	{
//		i++;
//	}
//	printf("%d\n", (a * i));
//	return 0;
//}

////2.һ������a���ӵ�a*b���������ͬʱ������������ô���ҵ���
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

////3.�������ĳ˻��������������Լ��
////��һ���������Լ��
////շת�������1.�������н�Сֵ����b��2.a%b��ֵ����c����c����0����aΪ���Լ����
////����a=b��b=c������a%bֱ������0
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int temp = 0;  
//	scanf("%d %d", &a, &b);
//	int n = a * b;
//	if (a < b)   //��bΪ�����еĽ�Сֵ
//	{
//		temp = a;  //tempΪ��ʱ����������a��b��
//		a = b;
//		b = temp;
//	}
//	while (b!=0)
//	{
//		int c =a % b;  //cΪb��a����ģ
//		a = b;
//		b = c;
//	}
//	int m = n/ a;//a��b����֮���������Լ��
//	printf("%d\n", m);
//}


//#include<stdio.h>
//int main()
//{
//	int a, b, n, m;
//	int c, t;
//	printf("��������������\n");
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
//	printf("�����������Լ��Ϊ��%d\n", a);
//	printf("����������С������Ϊ��%d\n", m * n / a);
//	return 0;
//}



////�����������Լ��
////1.�������еĽϴ�ֵ��ֵ��m������i=m%n,
////�ж������Ƿ�Ϊ0�����Ϊ0�����������Ϊn������m=n;n=i;��������ֱ������iΪ0����ʱ�������Ϊn��
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


////2.���a,b��ȣ��������Ϊ���������κ�һ�������a>bʱ��a=a-b��b>aʱ��a=a-b��
////һֱ����a=bʱ,�������Ϊa��b��һ��
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


////3.��������ֵ��aΪ��Сֵ����i��a��1���㣬��a%i��b%iͬʱΪ0ʱ����iΪ���Լ��
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