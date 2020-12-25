#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//带尾结点的单链表实现队列
typedef int QDataType;

//结点
typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;

//队列
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

//初始化队列
void queueInit(Queue* q);

//创建结点
QNode* creatNode(QDataType* data);

//入队:尾插
void queuePush(Queue* q, QDataType data);

//出队：头删
void queuePop(Queue* q);

//长度
int queueSize(Queue* q);

//判空
int queueEmpty(Queue* q);

//销毁
void queueDestory(Queue* q);

//获取对头元素
QDataType queueFront(Queue* q);

//获取队尾元素
QDataType queueBack(Queue* q);

//初始化队列
void queueInit(Queue* q)
{
	q->front = q->rear = NULL;
	q->size = 0;
}

//创建结点
QNode* creatNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	return node;
}

//入队:尾插
void queuePush(Queue* q, QDataType data)
{
	QNode* node = creatNode(data);
	//空队列：入队一个结点，首尾都指向这个结点
	if (q->front == NULL)
		q->front = q->rear = node;
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
	q->size++;
}

//出队：头删
void queuePop(Queue* q)
{
	//为空侧不能删
	if (q->front)
	{
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
		//删除之后如果为空表，要改变尾指针
		if (q->front == NULL)
			q->rear = NULL;
		q->size--;
	}
}

//长度
int queueSize(Queue* q)
{
	int num = 0;
	QNode* cur = q->front;
	while (cur)
	{
		++num;
		cur = cur->next;
	}
	return num;
	//return q->size;
}

//判空
int queueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	return 0;
}

//销毁
void queueDestory(Queue* q)
{
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		//摧毁直接释放，无需连接
		cur = next;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}

//获取对头元素
QDataType queueFront(Queue* q)
{
	return q->front->data;
}

//获取队尾元素
QDataType queueBack(Queue* q)
{
	return q->rear->data;
}

void test()
{
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);

	while (queueEmpty(&q) != 1)
	{
		printf("%d ", queueFront(&q));
		queuePop(&q);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}
