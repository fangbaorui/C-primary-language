#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�յĴ�ͷ˫��ѭ������

typedef int LDataType;
//˫����
typedef struct ListNode
{
	LDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//˫���ͷѭ������
typedef struct List
{
	struct ListNode* head;
}List;

//��ʼ������
void initList(List* lst);

//�������
struct ListNode* creatNode(LDataType val);

//β��
void listPushBack(List* lst, LDataType val);

//βɾ
void listPopBack(List* lst);

//��ӡ
void printList(List* lst);

//ͷ��
void listPushFront(List* lst, LDataType val);

//ͷɾ
void listPopFront(List* lst);

//������λ�õ�ǰ�����
void listInsert(ListNode* node, LDataType val);

//������λ��ɾ��
void listErase(ListNode* node);

//����
void listDestroy(List* lst);


//��ʼ������
void initList(List* lst)
{
	//�յĴ�ͷ˫��ѭ������
	//����ѭ���ṹ
	//����ͷ���
	lst->head = (struct ListNode*)malloc(sizeof(struct ListNode));
	lst->head->prev = lst->head->next = lst->head;
}

//�������
struct ListNode* creatNode(LDataType val)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = val;
	node->next = node->prev = NULL;
	return node;
}

//β��
void listPushBack(List* lst, LDataType val)
{
	//struct ListNode* tail = lst->head->prev;
	//struct ListNode* newNode = creatNode(val);

	//tail->next = newNode;
	//newNode->prev = tail;

	//lst->head->prev = newNode;
	//newNode->next = lst->head;

	listInsert(lst->head, val);
}

//βɾ
void listPopBack(List* lst)
{
	//if (lst->head->prev == lst->head)//lst->head->next==lst->head;
	//	return; //������
	//struct ListNode* tail = lst->head->prev;
	//struct ListNode* prev = tail->prev;
	//free(tail);

	//prev->next = lst->head;
	//lst->head->prev = prev;

	if (lst->head->prev == lst->head)//lst->head->next==lst->head;
		return; //������
	listErase(lst->head->prev);
}

//��ӡ
void printList(List* lst)
{
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//ͷ��
void listPushFront(List* lst, LDataType val)
{
	//struct ListNode* newNode = creatNode(val);
	//struct ListNode* next = lst->head -> next;

	//lst->head->next = newNode;
	//newNode->prev = lst->head;

	//next->prev = newNode;
	//newNode->next = next;
	listInsert(lst->head->next, val);
}

//ͷɾ
void listPopFront(List* lst)
{
	//if (lst->head->next == lst->head)
	//	return;
	//struct ListNode* next = lst->head->next;
	//struct ListNode* nextnext = next->next;
	//free(next);
	//lst->head->next = nextnext;
	//nextnext->prev = lst->head;

	if (lst->head->next == lst->head)
		return;
	listErase(lst->head->next);
}

//������λ�õ�ǰ�����
void listInsert(ListNode* node, LDataType val) 
{
	struct ListNode* newNode = creatNode(val);
	struct ListNode* prev = node->prev;
	node->prev = newNode;
	newNode->next = node;

	prev->next = newNode;
	newNode->prev = prev;
}

//������λ��ɾ��
void listErase(ListNode* node)
{
	struct ListNode* prev = node->prev;
	struct ListNode* next = node->next;
	free(node);
	prev->next = next;
	next->prev = prev;
}

//����
void listDestroy(List* lst)
{
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		struct ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(lst->head);
	lst->head = NULL;
}

void test()
{
	//struct List lst;
	//initList(&lst);
	//listPushBack(&lst, 1);
	//listPushBack(&lst, 2);
	//listPushBack(&lst, 3);
	//listPushBack(&lst, 4);
	//listPushBack(&lst, 5);
	//printList(&lst);

	//listPopBack(&lst);
	//listPopBack(&lst);
	//printList(&lst);
	//listPopBack(&lst);
	//listPopBack(&lst);
	//listPopBack(&lst);

	List lst;
	initList(&lst);
	listPushFront(&lst, 1);
	listPushFront(&lst, 2);
	listPushFront(&lst, 3);
	printList(&lst);
	listPopFront(&lst);
	listPopFront(&lst);
	printList(&lst);
}

int main()
{
	test();
	return 0;
}

