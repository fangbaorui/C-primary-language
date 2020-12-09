#include<stdio.h>
#include"seqlist.h"
#include<stdlib.h>
#include<string.h>

//��ʼ��һ���յ�˳���
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}


//β�壺ʱ�临�Ӷ�O��1��
void seqListPushBack(seqList* sl,SLDataType val)
{
	//if (sl == NULL)
	//	return;
	////�������
	//seqListCheckCapacity(sl);
	////β��
	//sl->data[sl->size] = val;
	//sl->size++;

	seqListInsert(sl, sl->size, val);
}

//βɾ
void seqListpopBack(seqList* sl)
{
	//if (sl == NULL)
	//	return;
	//if (sl->size > 0)
	//	sl->size--;

	seqListErase(sl, sl->size-1);
}


//�������
void seqListCheckCapacity(seqList* sl)
{
	if (sl->size == sl->capacity)
	{
		//�ռ�����������
		//1.���µĿռ�
		int newCapacity = sl->capacity == 0 ? 1 : 2 * sl->capacity;
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
		//2.����
		memcpy(tmp, sl->data, sizeof(SLDataType) * sl->size);
		//3.�ͷ�ԭ�еĿռ�
		free(sl->data);
		sl->data = tmp;

		//����3���൱����realloc
		sl->data = (SLDataType*)realloc(sl->data, newCapacity * sizeof(SLDataType));

		//4.��������
		sl->capacity = newCapacity;
	}
}

//��ӡ
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


//��������λ�õ�Ԫ��
SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->data[pos];
}

//�п�
void seqListEmpty(seqList* sl)
{
	if (sl = NULL || sl->data == 0)
		return 0;
	else
		return 1;
}

//��ЧԪ�ظ���
int seqListSize(seqList* sl)
{
	if (sl = NULL || sl->data == 0)
		return 0;
	else
		return sl->size;
}

//ͷ��
void seqListPushFront(seqList* sl, SLDataType val)
{
	//if (sl == NULL)
	//	return;
	////�������
	//seqListCheckCapacity(sl);

	////�ƶ�Ԫ�أ��Ӻ���ǰ�ƶ�
	//int end = sl->size;
	//while (end > 0)
	//{
	//	sl->data[end] = sl->data[end - 1];
	//	end--;
	//}

	////����
	//sl ->data[0] = val;
	//sl->size++;

	//�ڵ�0��λ�ò���
	seqListInsert(sl, 0, val);
}


//ͷɾ
void seqListPopFront(seqList* sl)
{
	//if (sl == NULL || sl->size == 0)
	//	return;
	////��ǰ����ƶ�Ԫ��
	//int start = 1;
	//while (start < sl->size)
	//{
	//	sl->data[start - 1] = sl->data[start];
	//	start++;
	//}

	////����size
	//sl->size--;

	seqListErase(sl, 0);
}

//����λ�ò���
void seqListInsert(seqList* sl, int pos, SLDataType val)
{
	if (sl == NULL)
		return;
	//�жϷ�Χ
	if (pos >= 0 && pos <= sl->size)
	{
		seqListCheckCapacity(sl);
		//�ƶ�Ԫ��;[pos,size��,����ҿ�����
		int end = sl->size;
		while (end > pos)
		{
			sl->data[end] = sl->data[end - 1];
			end--;
		}
		//����:pos
		sl->data[pos] = val;
		sl->size++;
	}
}


//����λ��ɾ��
void seqListErase(seqList* sl, int pos)
{
	if (sl == NULL || sl->size == 0)
		return;
	if (0 <= pos && pos < sl->size)
	{
		//�ƶ�Ԫ�أ���ǰ���
		int start = pos + 1;
		while (start < sl->size)
		{
			sl->data[start - 1] = sl->data[start];
			start++;
		}
		sl->size--;
	}
}


//����
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