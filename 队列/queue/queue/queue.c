#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��β���ĵ�����ʵ�ֶ���
typedef int QDataType;

//���
typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;

//����
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

//��ʼ������
void queueInit(Queue* q);

//�������
QNode* creatNode(QDataType* data);

//���:β��
void queuePush(Queue* q, QDataType data);

//���ӣ�ͷɾ
void queuePop(Queue* q);

//����
int queueSize(Queue* q);

//�п�
int queueEmpty(Queue* q);

//����
void queueDestory(Queue* q);

//��ȡ��ͷԪ��
QDataType queueFront(Queue* q);

//��ȡ��βԪ��
QDataType queueBack(Queue* q);

//��ʼ������
void queueInit(Queue* q)
{
	q->front = q->rear = NULL;
	q->size = 0;
}

//�������
QNode* creatNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	return node;
}

//���:β��
void queuePush(Queue* q, QDataType data)
{
	QNode* node = creatNode(data);
	//�ն��У����һ����㣬��β��ָ��������
	if (q->front == NULL)
		q->front = q->rear = node;
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
	q->size++;
}

//���ӣ�ͷɾ
void queuePop(Queue* q)
{
	//Ϊ�ղ಻��ɾ
	if (q->front)
	{
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
		//ɾ��֮�����Ϊ�ձ�Ҫ�ı�βָ��
		if (q->front == NULL)
			q->rear = NULL;
		q->size--;
	}
}

//����
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

//�п�
int queueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	return 0;
}

//����
void queueDestory(Queue* q)
{
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		//�ݻ�ֱ���ͷţ���������
		cur = next;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}

//��ȡ��ͷԪ��
QDataType queueFront(Queue* q)
{
	return q->front->data;
}

//��ȡ��βԪ��
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
