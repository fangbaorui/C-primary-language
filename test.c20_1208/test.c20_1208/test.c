////ģ��ʵ��memcpy
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	//��¼dest����ʼ��ַ
//	void* ret = dest;
//	while (count--)
//	{
//		//����һ���ֽ�
//		*(char*)dest = *(char*)src;
//		//ÿ�ο���һ���ֽڣ���Ҫ��ǿ������ת��������ǰ��++����Ϊ++�����ȼ���ǿ������ת����
//		dest = (char*)dest + 1;//++(char*)dest;
//		src = (char*)src + 1;//++(char*)dest;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	//memcpy(arr2,arr1, 20);//5��int���ͣ�20���ֽ�
//	my_memcpy(arr2, arr1, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);//1 2 3 4 5 0 0 0 0 0
//	}
//	return 0;
//}



////ģ��ʵ��memcpy
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest);
//	assert(src);
//	//��¼dest����ʼ��ַ
//	void* ret = dest;
//	if (dest < src)   //��ǰ��󿽱�������Ҫ������Ԫ�ر�����
//	{
//		while (count--)
//		{
//			//����һ���ֽ�
//			*(char*)dest = *(char*)src;
//			//ÿ�ο���һ���ֽڣ���Ҫ��ǿ������ת��������ǰ��++����Ϊ++�����ȼ���ǿ������ת����
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


//ʹ��memcpy
#include<stdio.h>
#include<string.h>
int main()
{
	int arr1[5] = { 1,2,3,4,5};
	int arr2[5] = { 1,2,3,3,3 };
	int ret = memcmp(arr1, arr2, 20);
		printf("%d ", ret);//����һ������0������
	return 0;
}


//������ʽ�������ӷ�
//���ڷǸ�����X���ԣ�X��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����飬
//���磬���X=1231����ô������ʽΪ[1,2,3,1],�����Ǹ�����X��������ʽA����������X+K��������ʽ
//����A=[2,7,4],k=181,���[4,5,5],���ͣ�274+181=455
//����A=[9,9,9,9,9,9,9,9,9],���[1,0,0,0,0,0,0,0,0,0,0],����999999999+1=10000000000
//����˼·����λ��ӣ�ÿһλ�ӷ��Ľ������Ӧλ����ֵ+��һ���Ľ�λ��0<=���<=19
//�����λ�����һ��Ԫ�ؿ�ʼ�������λ��%10  /10
int* addToArryForm(int* A, int ASize, int K, int* returnSize)
{
	//��������K��λ��
	int len = 0;
	int num = K;
	while (num)
	{
		len++;
		num /= 10;
	}
	//��������
	int arrLen = len > ASize ? len + 1 : ASize + 1;
	int* arr = (int*)malloc(sizeof(int)* arrLen);

	int idx = 0;
	//��λ
	int step = 0;
	int end = ASize - 1;
	while (end >= 0 || K > 0)
	{
		//��λ��ӣ���һ����λ+��Ӧλ��ֵ
		int curSum = step;
		//�ۼӶ�Ӧλ��ֵ
		if (end >= 0)
			curSum += A[end];
		if (K > 0)
			curSum += K % 10;
		//�ж��Ƿ��н�λ
		if (curSum > 9)
		{
			step = 1;
			//curSum��ֵ��10-19֮��
			curSum -= 10;
		}
		else
			step = 0;
		//���浱ǰλ��ֵ��������
		arr[idx++] = curSum;

		//������һλ�Ľ��
		end--;
		K /= 10;
	}
	//�ж����λ�Ƿ��н�λ
	if (step == 1)
		arr[idx++] = 1;

	//˳����ת
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
	//��������ĳ���
	*returnSize = idx;
	return arr;
}


