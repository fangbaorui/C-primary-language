#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//交换函数
void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
//插入排序,时间复杂度o（n^2）
void insertSort(int* arr, int n)
{
	//假设第一个数据有序,不用再插入
	//未插入的数据：[1,n) --> [1,n-1]
	for (int i = 1; i < n; i++)
	{
		//从有序数据的最后一个位置向前遍历
		int end = i - 1;
		//待插入的数据
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)
		{
			//大的数据向后移动
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = data;
	}
}


//希尔排序
void shellSort(int* arr, int n)
{
	//gap是同组数据相邻间隔
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//最后一趟排序，间隔必须是1，保证所有数据都在同一组
		//一趟希尔排序
		for (int i = gap; i < n; i++)
		{
			//从有序数据的最后一个位置向前遍历
			int end = i - gap;
			//待插入的数据
			int data = arr[i];
			while (end >= 0 && arr[end] >= data)
			{
				//大的数据向后移动
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}


//选择排序
void selectSort1(int* arr, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		int key = i;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (arr[j] < arr[key])
				key = j;
		}
		if (key != i)
		{
			int tmp = arr[i];
			arr[i] = arr[key];
			arr[key] = tmp;
		}
	}
}


//选择排序
void selectSort2(int* arr, int n)
{
	//从未排序的序列中找最值，存放到未排序的起始位置
	//未排序的区间：[start,end]
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//找到最小值的位置
		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		//把最小值存开始的位置
		Swap(arr, start, minIdx);
		//剩余的未排序的区间：[start+1,end]
		++start;
	}
}


//选择排序
void selectSort3(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//每次从未排序的区间找到一个最大值和一个最小值
	//最小值放在头部，最大值放在尾部
	//遍历的次数减少一遍
	while (start < end)
	{
		int minIdx = start;
		int maxIdx = start;

		//找到最大值与最小值
		for (int j = start + 1; j <= end; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
			if (arr[j] > arr[maxIdx])
				maxIdx = j;
		}
		//最小值放在头部
		Swap(arr, start, minIdx);

		//判断最大值的位置是否在起始位置:需要改变一下序号，否则交换只是交换值，没有交换序号
		//否则maxIdx的序号在start位置，交换的时候拿到的是最小值
		if (maxIdx == start)
			maxIdx = minIdx;

		Swap(arr, end, maxIdx);
		start++;
		end--;
	}
}


//向下调整
void shiftDown(int* arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//升序：建大堆
void heapSort(int* arr, int n)
{
	//建堆,从最后一个非叶子结点开始向下调整
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(arr, end, 0);
		shiftDown(arr, end, 0);
		--end;
	}
}



//冒泡排序
void bubbleSort(int* arr, int n)
{
	//相邻元素进行比较
	//每一次遍历的范围：0——未排序数据的最后一个位置
	int end = n;
	//一个元素就不用在排了，就在相应的位置
	while (end > 1)
	{
		//flag,标记，如果不发生交换就说明排好了，结束
		int flag = 0;
		//一轮冒泡排序
		//for(int i=0;i<end-1;i++)
		for (int i = 1; i < end; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				//大的向后移
				Swap(arr, i - 1, i);
				flag = 1;
			}
		}
		if (!flag)
			break;
		//进行n-1轮
		end--;
	}
}


//快速排序，不稳定
//数据有序时：没有优化时，可能会导致栈溢出o（n^2），栈的调用层数约等于数据的个数n
//完成一次划分
int partion1(int* arr, int begin, int end)
{
	//选择基准值
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//从后向前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//从前向后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//交换
		Swap(arr, begin, end);
	}
	//交换基准值和相遇位置的数据
	Swap(arr, start, begin);
	//返回相遇的位置，返回划分之后，基准值所在位置
	return begin;
}
//递归调用一次划分
void quickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div：一次划分之后，基准值的位置
	int div = partion1(arr, begin, end);
	//左右两部分进行快速排序；
	//[begin,div-1]
	//[div+1，end]
	quickSort1(arr, begin, div - 1);
	quickSort1(arr, div + 1, end);
}


//优化后的快速排序
//数据有序时：优化后划分计较均衡o（nlogn），栈的调用层数logn
//选前中后位置的中间值为基准值
int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	//mid < begin
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])   //end < mid < begin
			return mid;
		else if (arr[begin] > arr[end])   //mid < end < begin
			return end;
		else                       //mid < begin <end
			return begin;
	}
	else
	{
		//begin < mid
		if (arr[mid] < arr[end])   //begin < mid < end
			return mid;
		else if (arr[begin] < arr[end])   //begin < end < mid
			return end;
		else                         //end < begin < mid
			return begin;
	}
}
//完成一次划分
int partion2(int* arr, int begin, int end)
{
	//获取基准值的位置
	int mid = getMid(arr, begin, end);
	//把基准值放在起始位置
	Swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//从后向前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//从前向后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//交换
		Swap(arr, begin, end);
	}
	//交换基准值和相遇位置的数据
	Swap(arr, start, begin);
	//返回相遇的位置，返回划分之后，基准值所在位置
	return begin;
}
//递归调用一次划分
void quickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div：一次划分之后，基准值的位置
	int div = partion2(arr, begin, end);
	//左右两部分进行快速排序；
	//[begin,div-1]
	//[div+1，end]
	quickSort2(arr, begin, div - 1);
	quickSort2(arr, div + 1, end);
}


void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void testinsertSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	insertSort(arr, sz);
	printArr(arr, sz);
}



void testshellSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	shellSort(arr, sz);
	printArr(arr, sz);
}


void testselectSort1()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selectSort1(arr, sz);
	printArr(arr, sz);
}


void testselectSort2()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selectSort2(arr, sz);
	printArr(arr, sz);
}


void testselectSort3()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selectSort3(arr, sz);
	printArr(arr, sz);
}


void testheapSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, sz);
	printArr(arr, sz);
}


void testbubbleSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, sz);
	printArr(arr, sz);
}


void testquickSort1()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	quickSort1(arr, 0, sz - 1);
	printArr(arr, sz);
}


void testquickSort2()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	quickSort2(arr, 0, sz - 1);
	printArr(arr, sz);
}




void test()
{
	int n;
	printf("数据量：\n");
	scanf("%d", &n);
	//设置随机数的起点
	srand(time(NULL));

	//动态开辟数组存放随机数
	int* arr = (int*)malloc(sizeof(int) * n);
	int* copy1 = (int*)malloc(sizeof(int) * n);
	int* copy2 = (int*)malloc(sizeof(int) * n);
	int* copy3 = (int*)malloc(sizeof(int) * n);
	int* copy4 = (int*)malloc(sizeof(int) * n);
	int* copy5 = (int*)malloc(sizeof(int) * n);
	int* copy6 = (int*)malloc(sizeof(int) * n);
	int* copy7 = (int*)malloc(sizeof(int) * n);
	int* copy8 = (int*)malloc(sizeof(int) * n);
	int* copy9 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	//将随机数的数组拷贝两份一样的
	memcpy(copy1, arr, sizeof(int) * n);
	memcpy(copy2, arr, sizeof(int) * n);
	memcpy(copy3, arr, sizeof(int) * n);
	memcpy(copy4, arr, sizeof(int) * n);
	memcpy(copy5, arr, sizeof(int) * n);
	memcpy(copy6, arr, sizeof(int) * n);
	memcpy(copy7, arr, sizeof(int) * n);
	memcpy(copy8, arr, sizeof(int) * n);
	memcpy(copy9, arr, sizeof(int) * n);

	time_t begin = clock();
	insertSort(copy1, n);
	time_t end = clock();
	printf("insertSort: %lld\n", end - begin);

	begin = clock();
	shellSort(copy2, n);
	end = clock();
	printf("shellSort: %lld\n", end - begin);

	begin = clock();
	selectSort1(copy3, n);
	end = clock();
	printf("selectSort1: %lld\n", end - begin);

	begin = clock();
	selectSort2(copy4, n);
	end = clock();
	printf("selectSort2: %lld\n", end - begin);

	begin = clock();
	selectSort3(copy5, n);
	end = clock();
	printf("selectSort3: %lld\n", end - begin);

	begin = clock();
	heapSort(copy6, n);
	end = clock();
	printf("heapSort: %lld\n", end - begin);

	begin = clock();
	bubbleSort(copy7, n);
	end = clock();
	printf("bubbleSort: %lld\n", end - begin);

	//无序的快排
	begin = clock();
	quickSort1(copy8, 0, n - 1);
	end = clock();
	printf("无序quickSort1: %lld\n", end - begin);

	////有序的快排
	//begin = clock();
	//quickSort1(copy8, 0, n-1);
	//end = clock();
	//printf("有序quickSort1: %lld\n", end - begin);

	begin = clock();
	quickSort2(copy9, 0, n - 1);
	end = clock();
	printf("优化后无序quickSort2: %lld\n", end - begin);

	begin = clock();
	quickSort2(copy9, 0, n - 1);
	end = clock();
	printf("优化后有序quickSort2: %lld\n", end - begin);
}

int main()
{
	//testinsertSort();
	//testshellSort();
	//testselectSort1();
	//testselectSort2();
	//testselectSort3();
	//testheapSort();
	//testbubbleSort();
	//testquickSort1();
	//testquickSort2();

	test();
	return 0;
}