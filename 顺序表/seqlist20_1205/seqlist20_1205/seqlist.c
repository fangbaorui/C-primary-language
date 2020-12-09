#include<stdio.h>
#include"seqlist.h"
#include<stdlib.h>
#include<string.h>

//初始化一个空的顺序表
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}


//尾插：时间复杂度O（1）
void seqListPushBack(seqList* sl,SLDataType val)
{
	//if (sl == NULL)
	//	return;
	////检查容量
	//seqListCheckCapacity(sl);
	////尾插
	//sl->data[sl->size] = val;
	//sl->size++;

	seqListInsert(sl, sl->size, val);
}

//尾删
void seqListpopBack(seqList* sl)
{
	//if (sl == NULL)
	//	return;
	//if (sl->size > 0)
	//	sl->size--;

	seqListErase(sl, sl->size-1);
}


//检查容量
void seqListCheckCapacity(seqList* sl)
{
	if (sl->size == sl->capacity)
	{
		//空间已满，扩容
		//1.开新的空间
		int newCapacity = sl->capacity == 0 ? 1 : 2 * sl->capacity;
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
		//2.拷贝
		memcpy(tmp, sl->data, sizeof(SLDataType) * sl->size);
		//3.释放原有的空间
		free(sl->data);
		sl->data = tmp;

		//以上3步相当于用realloc
		sl->data = (SLDataType*)realloc(sl->data, newCapacity * sizeof(SLDataType));

		//4.更新容量
		sl->capacity = newCapacity;
	}
}

//打印
void seqListPrint(seqList* sl)
{
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d", sl->data[i]);
	}
	printf("\n");
}


//访问任意位置的元素
SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->data[pos];
}

//判空
void seqListEmpty(seqList* sl)
{
	if (sl = NULL || sl->data == 0)
		return 0;
	else
		return 1;
}

//有效元素个数
int seqListSize(seqList* sl)
{
	if (sl = NULL || sl->data == 0)
		return 0;
	else
		return sl->size;
}

//头插
void seqListPushFront(seqList* sl, SLDataType val)
{
	//if (sl == NULL)
	//	return;
	////检查容量
	//seqListCheckCapacity(sl);

	////移动元素，从后向前移动
	//int end = sl->size;
	//while (end > 0)
	//{
	//	sl->data[end] = sl->data[end - 1];
	//	end--;
	//}

	////插入
	//sl ->data[0] = val;
	//sl->size++;

	//在第0个位置插入
	seqListInsert(sl, 0, val);
}


//头删
void seqListPopFront(seqList* sl)
{
	//if (sl == NULL || sl->size == 0)
	//	return;
	////从前向后移动元素
	//int start = 1;
	//while (start < sl->size)
	//{
	//	sl->data[start - 1] = sl->data[start];
	//	start++;
	//}

	////更新size
	//sl->size--;

	seqListErase(sl, 0);
}

//任意位置插入
void seqListInsert(seqList* sl, int pos, SLDataType val)
{
	if (sl == NULL)
		return;
	//判断范围
	if (pos >= 0 && pos <= sl->size)
	{
		seqListCheckCapacity(sl);
		//移动元素;[pos,size）,左闭右开区间
		int end = sl->size;
		while (end > pos)
		{
			sl->data[end] = sl->data[end - 1];
			end--;
		}
		//插入:pos
		sl->data[pos] = val;
		sl->size++;
	}
}


//任意位置删除
void seqListErase(seqList* sl, int pos)
{
	if (sl == NULL || sl->size == 0)
		return;
	if (0 <= pos && pos < sl->size)
	{
		//移动元素：从前向后
		int start = pos + 1;
		while (start < sl->size)
		{
			sl->data[start - 1] = sl->data[start];
			start++;
		}
		sl->size--;
	}
}


//销毁
void seqListDestroy(seqList* sl)
{
	if (sl != NULL && sl->data != NULL)
	{
		free(sl->data);
		sl->data = NULL;
	}
}


void test()
{
	seqList sl;
	initseqList(&sl);
	seqListPushBack(&sl, 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	seqListPushBack(&sl, 4);
	seqListPushBack(&sl, 5);
	seqListPrint(&sl);//1 2 3 4 5

	seqListpopBack(&sl);
	seqListPrint(&sl);//1 2 3 4

	seqListpopBack(&sl);
	seqListPrint(&sl);//1 2 3

	seqListpopBack(&sl);
	seqListPrint(&sl);//1 2

	seqListpopBack(&sl);
	seqListPrint(&sl);//1

	seqListpopBack(&sl);
	seqListPrint(&sl);
	
}

int main()
{
	test();
		return 0;
}