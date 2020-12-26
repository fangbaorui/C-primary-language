#define _CRT_SECURE_NO_WARNINGS
//第二个栈:顺序表实现栈
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct stack
{
	DataType* arr;
	size_t size;
	size_t capacity;
}stack;

//初始化栈
void stackInit(stack* st, size_t n);

//入栈：尾插
void stackPush(stack* st, DataType data);

//出栈：尾删
void stackPop(stack* st);

//判空
int stackEmpty(stack* st);

//获取栈顶元素
DataType stackTop(stack* st);

//栈的大小
size_t stackSize(stack* st);

//销毁栈
void stackDestory(stack* st);

//初始化栈,给定一个空间
void stackInit(stack* st, size_t n)
{
	st->arr = (DataType*)malloc(sizeof(DataType) * n);
	st->capacity = n;
	st->size = 0;
}

//入栈：尾插
void stackPush(stack* st, DataType data)
{
	if (st == NULL)
		return;
	//检查容量
	if (st->size == st->capacity)
	{
		st->capacity *= 2;
		st->arr = (DataType*)realloc(st->arr, sizeof(DataType) * st->capacity);
	}
	//尾插
	st->arr[st->size++] = data;
}

//出栈：尾删
void stackPop(stack* st)
{
	if (st->size)
		st->size--;
}

//获取栈顶元素
DataType stackTop(stack* st)
{
	return st->arr[st->size - 1];
}

//栈的大小
size_t stackSize(stack* st)
{
	return st->size;
}

//销毁栈
void stackDestory(stack* st)
{
	free(st->arr);
	st->arr = NULL;
	st->size = st->capacity = 0;
}

//判空:为空返回1，不空返回0
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