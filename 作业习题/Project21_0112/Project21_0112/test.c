#define _CRT_SECURE_NO_WARNINGS

//���������������������������Լ��
//�������еĽϴ�ֵ��ֵ��m������i = m % n,
//�ж������Ƿ�Ϊ0�����Ϊ0�����������Ϊn��
//����m = n; n = i; ��������ֱ������iΪ0����ʱ�������Ϊn��
//#include<stdio.h>
//int main()
//{
//    int m = 0;
//    int n = 0;
//    int i = 0;
//    scanf("%d %d", &m, &n);
//    while (n != 0)
//    {
//        i = m % n;
//        m = n;
//        n = i;
//    }
//    printf("%d\n", m);
//    return 0;
//}


//��ӡ1000�굽2000��֮�������
//#include<stdio.h>
//int main()
//{
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//дһ�����룺��ӡ100~200֮�������
//дһ�����룺��ӡ100~200֮�������
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 101; i < 200; i += 2)
//	{
//		m = (int)sqrt(i);
//		for (j = 2; j <= m; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (j > m)
//			printf("%d ", i);
//	}
//	return 0;
//}




////��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9 || i / 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d", count);
//	return 0;
//}



//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int n = 1;
//	double num = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		num = num + (1.0 / i) * n;
//		n *= -1;
//	}
//	printf("%lf\n", num);
//	return 0;
//}



////��10 �����������ֵ
////ð������
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10 - 1; i++)
//	{
//		for (j = 0; j < 10 - 1 - i; j++)
//		{
//			if (arr[j + 1] > arr[j])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//	printf("%d\n", arr[0]);
//	return 0;
//}



////����Ļ�����9 * 9�˷��ھ���
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d   ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}



////��������Ϸ
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("************************\n");
//	printf("********** 1.play ******\n");
//	printf("********** 2.exit ******\n");
//	printf("************************\n");
//}
//
//
//void game()
//{
//	//����һ��1��100֮��������,rand()
//	int random = rand() % 100 + 1;
//	int guess = 0;
//	while (1)
//	{
//		printf("������֣�>");
//		scanf("%d", &guess);
//		if (guess > random)
//		{
//			printf("�´���\n");
//		}
//		else if (guess < random)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	//����ʱ�������һ�����ֵ��������������õ���ʼ��
//	srand((unsigned)time(NULL));
//	do
//	{
//		//��ӡ�˵�
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();  //��������Ϸ����
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ���������������\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//���ֲ���
//��������б�������
#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 0;
	scanf("%d", &n);
	int mid = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else if (arr[mid] > n)
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ��� %d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("û�ҵ�\n");
	}
	return 0;
}