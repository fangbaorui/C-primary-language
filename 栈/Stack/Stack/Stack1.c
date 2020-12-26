#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int SDataType;
//˳���ʵ��ջ
typedef struct stack
{
	SDataType* data;
	size_t size;
	size_t capacity;
}stack;

//��ʼ��ջ
void stackInit(stack* st);

//��ջ
void stackPush(stack* st, SDataType val);

//��ջ
void stackPop(stack* st);

//ջ�Ĵ�С
int stackSize(stack* st);

//�п�
int stackEmpty(stack* st);

//�������������
void checkCapacity(stack* st);



//��ʼ��ջ
void stackInit(stack* st)
{
	//��ջ
	if (st == NULL)
		return;
	st->data = NULL;
	st->size = st->capacity = 0;
}

//�������������
void checkCapacity(stack* st)
{
	if (st->size == st->capacity)
	{
		int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
		st->capacity = newCap;
	}
}

//��ջ��β��
void stackPush(stack* st, SDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->data[st->size++] = val;
}

//��ջ��βɾ
void stackPop(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	st->size--;
}

//��ȡջ��Ԫ��
int stackTop(stack* st)
{
	return st->data[st->size - 1];
}

//�п�:Ϊ�շ���1����Ϊ�շ���0
int stackEmpty(stack* st)
{
	if (st == NULL || st->size == 0)
		return 1;
	return 0;
}

//ջ�Ĵ�С
int stackSize(stack* st)
{
	if (st == NULL || st->size == 0)
		return 0;
	return st->size;
}

void test()
{
	stack st;
	stackInit(&st);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);

	while (stackEmpty(&st) != 1)  //while(!stackEmpty(&st))
	{
		printf("%d ", stackTop(&st));
		stackPop(&st);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}





//�ڶ���ջ:˳���ʵ��ջ
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct stack
{
	DataType* arr;
	size_t size;
	size_t capacity;
}stack;

//��ʼ��ջ
void stackInit(stack* st,size_t n);

//��ջ��β��
void stackPush(stack* st, DataType data);

//��ջ��βɾ
void stackPop(stack* st);

//�п�
int stackEmpty(stack* st);

//��ȡջ��Ԫ��
DataType stackTop(stack* st);

//ջ�Ĵ�С
size_t stackSize(stack* st);

//����ջ
void stackDestory(stack* st);

//��ʼ��ջ,����һ���ռ�
void stackInit(stack* st,size_t n)
{
	st->arr = (DataType*)malloc(sizeof(DataType) * n);
	st->capacity = n;
	st->size = 0;
}

//��ջ��β��
void stackPush(stack* st, DataType data)
{
	if (st == NULL)
		return;
	//�������
	if (st->size == st->capacity)
	{
		st->capacity *= 2;
		st->arr = (DataType*)realloc(st->arr, sizeof(DataType) * st->capacity);
	}
	//β��
	st->arr[st->size++] = data;
}

//��ջ��βɾ
void stackPop(stack* st)
{
	if (st->size)
		st->size--;
}

//��ȡջ��Ԫ��
DataType stackTop(stack* st)
{
	return st->arr[st->size - 1];
}

//ջ�Ĵ�С
size_t stackSize(stack* st)
{
	return st -> size;
}

//����ջ
void stackDestory(stack* st)
{
	free(st->arr);
	st->arr = NULL;
	st->size = st->capacity = 0;
}

//�п�:Ϊ�շ���1�����շ���0
int stackEmpty(stack* st)
{
	if (st->size == 0)
		return 1;
	return 0;
}

void test()
{
	stack st;
	stackInit(&st,1);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	while (!stackEmpty(&st))
	{
		printf("%d ", stackTop(&st));
		stackPop(&st);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}