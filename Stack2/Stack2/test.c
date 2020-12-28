#define _CRT_SECURE_NO_WARNINGS
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
void stackInit(stack* st, size_t n);

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
void stackInit(stack* st, size_t n)
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
	return st->size;
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
	stackInit(&st, 1);
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