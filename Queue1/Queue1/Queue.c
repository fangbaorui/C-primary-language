#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//带尾指针的单链表实现队列

//创建结点
typedef int QDataType;
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}QNode;

//创建链表
typedef struct Queue
{
	//头尾指针
	QNode* head;
	QNode* tail;
	//size计算元素个数
	size_t size;
}Queue;

//初始化队列
void QueueInit(Queue* q);

//创建结点
struct QNode* creatNode(QDataType val);

//入队:尾插
void QueuePush(Queue* q, QDataType val);

//出队：头删
void QueuePop(Queue* q);

//获取队头元素
QDataType QueueFront(Queue* q);

//获取队尾元素
QDataType QueueRear(Queue* q);

//队列元素个数
int QueueSize(Queue* q);

//判空
int QueueEmpty(Queue* q);


//初始化队列
void QueueInit(Queue* q)
{
	//空对列
	if (q == NULL)
		return;
	q->head = q->tail = NULL;
	q->size = 0;
}

//创建结点
struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
	node->data = val;
	node->next = NULL;
	return node;
}

//入队:尾插
void QueuePush(Queue* q, QDataType val)
{
	struct QNode* node = creatNode(val);
	//第一个节点
	if (q->head == NULL)
		q->head = q->tail = node;
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
	q->size++;
}

//出队：头删
void QueuePop(Queue* q)
{
	if (q == NULL||q->head==NULL)
		return;
	//头删
	struct QNode* next = q->head->next;
	free(q->head);
	q->head = next;
	//如果删完是空队列
	if (q->head == NULL)
		q->tail = NULL;
	q->size--;
}


//获取队头元素
QDataType QueueFront(Queue* q)
{
	return q->head->data;
}

//获取队尾元素
QDataType QueueRear(Queue* q)
{
	return q->tail->data;
}

//队列元素个数
int QueueSize(Queue* q)
{
	if (q == NULL)
		return 0;
	return q->size;
}

//判空
int QueueEmpty(Queue* q)
{
	return q->head == NULL;
}
void test()
{
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}


