////模拟实现memcpy
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	//记录dest的起始地址
//	void* ret = dest;
//	while (count--)
//	{
//		//拷贝一个字节
//		*(char*)dest = *(char*)src;
//		//每次拷贝一个字节，需要先强制类型转换，必须前置++，因为++的优先级比强制类型转换高
//		dest = (char*)dest + 1;//++(char*)dest;
//		src = (char*)src + 1;//++(char*)dest;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	//memcpy(arr2,arr1, 20);//5个int类型，20个字节
//	my_memcpy(arr2, arr1, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);//1 2 3 4 5 0 0 0 0 0
//	}
//	return 0;
//}



////模拟实现memcpy
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest);
//	assert(src);
//	//记录dest的起始地址
//	void* ret = dest;
//	if (dest < src)   //从前向后拷贝，避免要拷贝的元素被覆盖
//	{
//		while (count--)
//		{
//			//拷贝一个字节
//			*(char*)dest = *(char*)src;
//			//每次拷贝一个字节，需要先强制类型转换，必须前置++，因为++的优先级比强制类型转换高
//			dest = (char*)dest + 1;//++(char*)dest;
//			src = (char*)src + 1;//++(char*)dest;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr+2, arr, 16);//1 2 1 2 3 4 7 8 9 10
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);//1 2 1 2 3 4 7 8 9 10
//	}
//	return 0;
//}


//使用memcpy
#include<stdio.h>
#include<string.h>
int main()
{
	int arr1[5] = { 1,2,3,4,5};
	int arr2[5] = { 1,2,3,3,3 };
	int ret = memcmp(arr1, arr2, 20);
		printf("%d ", ret);//返回一个大于0的数字
	return 0;
}


//数组形式的整数加法
//对于非负整数X而言，X的数组形式是每位数字按从左到右的顺序形成的数组，
//例如，如果X=1231，那么数组形式为[1,2,3,1],给定非负整数X的数组形式A，返回整数X+K的数组形式
//输入A=[2,7,4],k=181,输出[4,5,5],解释：274+181=455
//输入A=[9,9,9,9,9,9,9,9,9],输出[1,0,0,0,0,0,0,0,0,0,0],解释999999999+1=10000000000
//解题思路：地位相加，每一位加法的结果：对应位的数值+上一步的进位，0<=结果<=19
//数组低位：最后一个元素开始，数组低位：%10  /10
int* addToArryForm(int* A, int ASize, int K, int* returnSize)
{
	//计算整数K的位数
	int len = 0;
	int num = K;
	while (num)
	{
		len++;
		num /= 10;
	}
	//申请数组
	int arrLen = len > ASize ? len + 1 : ASize + 1;
	int* arr = (int*)malloc(sizeof(int)* arrLen);

	int idx = 0;
	//进位
	int step = 0;
	int end = ASize - 1;
	while (end >= 0 || K > 0)
	{
		//逐位相加：上一步进位+对应位的值
		int curSum = step;
		//累加对应位的值
		if (end >= 0)
			curSum += A[end];
		if (K > 0)
			curSum += K % 10;
		//判断是否有进位
		if (curSum > 9)
		{
			step = 1;
			//curSum的值在10-19之间
			curSum -= 10;
		}
		else
			step = 0;
		//保存当前位的值，逆序存放
		arr[idx++] = curSum;

		//计算下一位的结果
		end--;
		K /= 10;
	}
	//判断最高位是否有进位
	if (step == 1)
		arr[idx++] = 1;

	//顺序逆转
	int start = 0;
	end = idx - 1;
	while (start < end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
	//保存数组的长度
	*returnSize = idx;
	return arr;
}


