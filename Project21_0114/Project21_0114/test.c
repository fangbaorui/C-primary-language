#define _CRT_SECURE_NO_WARNINGS

////写一个函数可以判断一个数是不是素数
//#include<stdio.h>
//#include<math.h>
//返回1表示是素数，返回0表示不是素数
//int is_prime(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	for (int i = 101; i <= 200; i += 2)
//	{
//		if (is_prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}


////写一个函数判断一年是不是闰年
//#include<stdio.h>
////返回1表示是闰年，返回0表示不是闰年
//int is_leapyear(int n)
//{
//	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	for (int i = 1000; i <= 2000; i+=4)
//	{
//		if (is_leapyear(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}



//写一个函数实现一个整型有序数组的二分查找
//#include<stdio.h>
//int bin_search(int arr[],int left,int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;//找到了
//	}
//	return -1;//找不到
//}
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	//要查找的数为key
//	int key = 7;
//	//如果找到了就打印下标
//	int ret = bin_search(arr,0,9, 7);
//	printf("%d\n", ret);
//	return 0;
//}


//写一个函数，每次调用这个函数，就会将num的值增加1
int add_num(int num)
{
	num++;
}


