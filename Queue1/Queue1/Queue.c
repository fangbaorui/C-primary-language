#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��βָ��ĵ�����ʵ�ֶ���

//�������
typedef int QDataType;
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}QNode;

//��������
typedef struct Queue
{
	//ͷβָ��
	QNode* head;
	QNode* tail;
	//size����Ԫ�ظ���
	size_t size;
}Queue;

//��ʼ������
void QueueInit(Queue* q);

//�������
struct QNode* creatNode(QDataType val);

//���:β��
void QueuePush(Queue* q, QDataType val);

//���ӣ�ͷɾ
void QueuePop(Queue* q);

//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q);

//��ȡ��βԪ��
QDataType QueueRear(Queue* q);

//����Ԫ�ظ���
int QueueSize(Queue* q);

//�п�
int QueueEmpty(Queue* q);


//��ʼ������
void QueueInit(Queue* q)
{
	//�ն���
	if (q == NULL)
		return;
	q->head = q->tail = NULL;
	q->size = 0;
}

//�������
struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
	node->data = val;
	node->next = NULL;
	return node;
}

//���:β��
void QueuePush(Queue* q, QDataType val)
{
	struct QNode* node = creatNode(val);
	//��һ���ڵ�
	if (q->head == NULL)
		q->head = q->tail = node;
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
	q->size++;
}

//���ӣ�ͷɾ
void QueuePop(Queue* q)
{
	if (q == NULL||q->head==NULL)
		return;
	//ͷɾ
	struct QNode* next = q->head->next;
	free(q->head);
	q->head = next;
	//���ɾ���ǿն���
	if (q->head == NULL)
		q->tail = NULL;
	q->size--;
}


//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q)
{
	return q->head->data;
}

//��ȡ��βԪ��
QDataType QueueRear(Queue* q)
{
	return q->tail->data;
}

//����Ԫ�ظ���
int QueueSize(Queue* q)
{
	if (q == NULL)
		return 0;
	return q->size;
}

//�п�
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


