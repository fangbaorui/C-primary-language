#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//空的带头双向循环链表

typedef int LDataType;
//双向结点
typedef struct ListNode
{
	LDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//双向带头循环链表
typedef struct List
{
	struct ListNode* head;
}List;

//初始化链表
void initList(List* lst);

//创建结点
struct ListNode* creatNode(LDataType val);

//尾插
void listPushBack(List* lst, LDataType val);

//尾删
void listPopBack(List* lst);

//打印
void printList(List* lst);

//头插
void listPushFront(List* lst, LDataType val);

//头删
void listPopFront(List* lst);

//在任意位置的前面插入
void listInsert(ListNode* node, LDataType val);

//在任意位置删除
void listErase(ListNode* node);

//销毁
void listDestroy(List* lst);


//初始化链表
void initList(List* lst)
{
	//空的带头双向循环链表
	//构建循环结构
	//创建头结点
	lst->head = (struct ListNode*)malloc(sizeof(struct ListNode));
	lst->head->prev = lst->head->next = lst->head;
}

//创建结点
struct ListNode* creatNode(LDataType val)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = val;
	node->next = node->prev = NULL;
	return node;
}

//尾插
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

//尾删
void listPopBack(List* lst)
{
	//if (lst->head->prev == lst->head)//lst->head->next==lst->head;
	//	return; //空链表
	//struct ListNode* tail = lst->head->prev;
	//struct ListNode* prev = tail->prev;
	//free(tail);

	//prev->next = lst->head;
	//lst->head->prev = prev;

	if (lst->head->prev == lst->head)//lst->head->next==lst->head;
		return; //空链表
	listErase(lst->head->prev);
}

//打印
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

//头插
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

//头删
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

//在任意位置的前面插入
void listInsert(ListNode* node, LDataType val) 
{
	struct ListNode* newNode = creatNode(val);
	struct ListNode* prev = node->prev;
	node->prev = newNode;
	newNode->next = node;

	prev->next = newNode;
	newNode->prev = prev;
}

//在任意位置删除
void listErase(ListNode* node)
{
	struct ListNode* prev = node->prev;
	struct ListNode* next = node->next;
	free(node);
	prev->next = next;
	next->prev = prev;
}

//销毁
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

