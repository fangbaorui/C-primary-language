#define _CRT_SECURE_NO_WARNINGS


////计算n的阶乘
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("%d\n", ret);
//	return 0;
//}


////计算1!+2!+3!+...+10！的阶乘
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



////编写代码，演示多个字符从两端移动，向中间汇聚
////welcom to bit
////#############
////w###########t
////we#########it
////wel#######bit
////welc##### bit
////welco###o bit
////welcom#to bit
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "welcom to bit";
//	char arr2[] = "#############";
//	int left = 0;
//	int right = strlen(arr1)-1;
//	while (left <= right)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}



////二分查找
////所查的序列必须有序
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0;
//	scanf("%d", &n);
//	int mid = 0;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了 %d\n",mid);
//				break;
//		}
//	}
//	if (left > right)
//	{
//		printf("没找到\n");
//	}
//	return 0;
//}



////二分查找封装成函数
//int bin_search(int arr[], int left, int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了");
//			return mid;
//		}
//	}
//	printf("没找到");
//	return -1;
//}


////编写代码实现，模拟用户登录情景，并且只能登录三次，只允许输入三次密码，
////如果密码正确则提示登录成功，如果三次均输入错误，则退出程序。
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	//假设密码是"123456"
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：\n");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("密码正确\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误，重新输入\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码错误，退出程序\n");
//	}
//	return 0;
//}





//猜数字游戏
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
//void game()
//{
//	//生成一个1到100之间的随机数,rand()
//	int random = rand() % 100 + 1;
//	int guess = 0;
//	while(1)
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



////goto语句的使用
//#include<stdio.h>
//#include<windows.h>
//#include<string.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");//设置时间60后关机
//again:
//	printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");//取消关机
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


#include<stdio.h>
#include<windows.h>
#include<string.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");//设置时间60后关机
	while (1)
	{
		printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n");
		scanf("%s", input);
		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");//取消关机
			break;
		}
	}
	return 0;
}