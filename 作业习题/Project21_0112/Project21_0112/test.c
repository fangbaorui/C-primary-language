#define _CRT_SECURE_NO_WARNINGS

//给定两个数，求这两个数的最大公约数
//把两数中的较大值赋值给m，求余i = m % n,
//判断余数是否为0，如果为0，则最大公因数为n，
//否则m = n; n = i; 接着求余直到余数i为0，此时最大公因数为n。
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


//打印1000年到2000年之间的闰年
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


//写一个代码：打印100~200之间的素数
//写一个代码：打印100~200之间的素数
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




////编写程序数一下 1到 100 的所有整数中出现多少个数字9
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



//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
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



////求10 个整数中最大值
////冒泡排序
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



////在屏幕上输出9 * 9乘法口诀表
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



////猜数字游戏
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
//	//生成一个1到100之间的随机数,rand()
//	int random = rand() % 100 + 1;
//	int guess = 0;
//	while (1)
//	{
//		printf("请猜数字：>");
//		scanf("%d", &guess);
//		if (guess > random)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < random)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	//利用时间戳传递一个随机值，放入随机数设置的起始点
//	srand((unsigned)time(NULL));
//	do
//	{
//		//打印菜单
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();  //猜数字游戏代码
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//二分查找
//所查的序列必须有序
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
			printf("找到了 %d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("没找到\n");
	}
	return 0;
}