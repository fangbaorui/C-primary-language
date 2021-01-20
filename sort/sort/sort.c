#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//��������
void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
//��������,ʱ�临�Ӷ�o��n^2��
void insertSort(int* arr, int n)
{
	//�����һ����������,�����ٲ���
	//δ��������ݣ�[1,n) --> [1,n-1]
	for (int i = 1; i < n; i++)
	{
		//���������ݵ����һ��λ����ǰ����
		int end = i - 1;
		//�����������
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)
		{
			//�����������ƶ�
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = data;
	}
}


//ϣ������
void shellSort(int* arr, int n)
{
	//gap��ͬ���������ڼ��
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//���һ�����򣬼��������1����֤�������ݶ���ͬһ��
		//һ��ϣ������
		for (int i = gap; i < n; i++)
		{
			//���������ݵ����һ��λ����ǰ����
			int end = i - gap;
			//�����������
			int data = arr[i];
			while (end >= 0 && arr[end] >= data)
			{
				//�����������ƶ�
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}


//ѡ������
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


//ѡ������
void selectSort2(int* arr, int n)
{
	//��δ���������������ֵ����ŵ�δ�������ʼλ��
	//δ��������䣺[start,end]
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//�ҵ���Сֵ��λ��
		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		//����Сֵ�濪ʼ��λ��
		Swap(arr, start, minIdx);
		//ʣ���δ��������䣺[start+1,end]
		++start;
	}
}


//ѡ������
void selectSort3(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//ÿ�δ�δ����������ҵ�һ�����ֵ��һ����Сֵ
	//��Сֵ����ͷ�������ֵ����β��
	//�����Ĵ�������һ��
	while (start < end)
	{
		int minIdx = start;
		int maxIdx = start;

		//�ҵ����ֵ����Сֵ
		for (int j = start + 1; j <= end; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
			if (arr[j] > arr[maxIdx])
				maxIdx = j;
		}
		//��Сֵ����ͷ��
		Swap(arr, start, minIdx);

		//�ж����ֵ��λ���Ƿ�����ʼλ��:��Ҫ�ı�һ����ţ����򽻻�ֻ�ǽ���ֵ��û�н������
		//����maxIdx�������startλ�ã�������ʱ���õ�������Сֵ
		if (maxIdx == start)
			maxIdx = minIdx;

		Swap(arr, end, maxIdx);
		start++;
		end--;
	}
}


//���µ���
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
//���򣺽����
void heapSort(int* arr, int n)
{
	//����,�����һ����Ҷ�ӽ�㿪ʼ���µ���
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



//ð������
void bubbleSort(int* arr, int n)
{
	//����Ԫ�ؽ��бȽ�
	//ÿһ�α����ķ�Χ��0����δ�������ݵ����һ��λ��
	int end = n;
	//һ��Ԫ�ؾͲ��������ˣ�������Ӧ��λ��
	while (end > 1)
	{
		//flag,��ǣ����������������˵���ź��ˣ�����
		int flag = 0;
		//һ��ð������
		//for(int i=0;i<end-1;i++)
		for (int i = 1; i < end; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				//��������
				Swap(arr, i - 1, i);
				flag = 1;
			}
		}
		if (!flag)
			break;
		//����n-1��
		end--;
	}
}


//�������򣬲��ȶ�
//��������ʱ��û���Ż�ʱ�����ܻᵼ��ջ���o��n^2����ջ�ĵ��ò���Լ�������ݵĸ���n
//���һ�λ���
int partion1(int* arr, int begin, int end)
{
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	//����������λ�ã����ػ���֮�󣬻�׼ֵ����λ��
	return begin;
}
//�ݹ����һ�λ���
void quickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div��һ�λ���֮�󣬻�׼ֵ��λ��
	int div = partion1(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]
	//[div+1��end]
	quickSort1(arr, begin, div - 1);
	quickSort1(arr, div + 1, end);
}


//�Ż���Ŀ�������
//��������ʱ���Ż��󻮷ּƽϾ���o��nlogn����ջ�ĵ��ò���logn
//ѡǰ�к�λ�õ��м�ֵΪ��׼ֵ
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
//���һ�λ���
int partion2(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ������ʼλ��
	Swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	//����������λ�ã����ػ���֮�󣬻�׼ֵ����λ��
	return begin;
}
//�ݹ����һ�λ���
void quickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div��һ�λ���֮�󣬻�׼ֵ��λ��
	int div = partion2(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]
	//[div+1��end]
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
	printf("��������\n");
	scanf("%d", &n);
	//��������������
	srand(time(NULL));

	//��̬���������������
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

	//������������鿽������һ����
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

	//����Ŀ���
	begin = clock();
	quickSort1(copy8, 0, n - 1);
	end = clock();
	printf("����quickSort1: %lld\n", end - begin);

	////����Ŀ���
	//begin = clock();
	//quickSort1(copy8, 0, n-1);
	//end = clock();
	//printf("����quickSort1: %lld\n", end - begin);

	begin = clock();
	quickSort2(copy9, 0, n - 1);
	end = clock();
	printf("�Ż�������quickSort2: %lld\n", end - begin);

	begin = clock();
	quickSort2(copy9, 0, n - 1);
	end = clock();
	printf("�Ż�������quickSort2: %lld\n", end - begin);
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