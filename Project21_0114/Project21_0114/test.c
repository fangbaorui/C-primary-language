#define _CRT_SECURE_NO_WARNINGS

////дһ�����������ж�һ�����ǲ�������
//#include<stdio.h>
//#include<math.h>
//����1��ʾ������������0��ʾ��������
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


////дһ�������ж�һ���ǲ�������
//#include<stdio.h>
////����1��ʾ�����꣬����0��ʾ��������
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



//дһ������ʵ��һ��������������Ķ��ֲ���
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
//			return mid;//�ҵ���
//	}
//	return -1;//�Ҳ���
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
//	//Ҫ���ҵ���Ϊkey
//	int key = 7;
//	//����ҵ��˾ʹ�ӡ�±�
//	int ret = bin_search(arr,0,9, 7);
//	printf("%d\n", ret);
//	return 0;
//}


//дһ��������ÿ�ε�������������ͻὫnum��ֵ����1
int add_num(int num)
{
	num++;
}


