#include"list.h"

//创建新节点
listNode* creatListNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->data = val;
	node->next = NULL;
	return node;
}

//初始化链表
void listInit(list* lst)
{
	//初始化空链表
	if (lst == NULL)
		return;
	lst->head = NULL;
}

//尾插：0（n）
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->head == NULL)
	{
		//插入第一个节点
		//创建节点
		lst->head = creatListNode(val);
	}
	else
	{
		//从第一个节点开始遍历，找到最后一个节点
		listNode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail= tail->next;
		}
		tail->next = creatListNode(val);
	}
}

//尾删：0（n）
void listPopBack(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	//遍历，找到最后一个节点
	struct listNode* prev = NULL;
	struct listNode* tail = lst->head;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}

	//释放最后一个节点
	free(tail);
	//更新next
	if (prev == NULL)  //只有一个节点，更新head节点
		//if(lst->head->next==NULL)
		lst->head = NULL;
	else
		prev->next = NULL;
}

//头插：0（1）
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//创建节点
	struct listNode* node = creatListNode(val);

	node->next = lst->head;
	lst->head = node;
}

//头删：o（1）
void listPopFront(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* next = lst -> head->next;
	free(lst->head);
	lst->head = next;
}

//在某个元素之后插入
void listInsertAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;

	struct listNode* newNode = creatListNode(val);

	struct listNode* next = node->next;
	node->next = newNode;
	newNode->next = next;
}

//在某个元素位置之后删除
void listEraseAfter(listNode* node)
{
	if (node == NULL || node->next == NULL)
		return;
	struct listNode* next = node->next;
	struct listNode* nextnext = next->next;

	//释放next
	free(next);
	node->next = nextnext;
}

//查找
struct listNode* listFind(list* lst, LDataType val)
{
	if (lst == NULL || lst->head == NULL)
		return NULL;
	struct listNode* cur = lst->head;
	while (cur)
	{
		if (cur->data == val)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

//摧毁
void listDestroy(list* lst)
{
	if (lst == NULL)
		return;
	listNode* cur = lst->head;
	while (cur)
	{
		//保存下一个节点的位置
		listNode* next = cur->next;
		//释放当前节点
		free(cur);
		//更新到下一个节点的位置
		cur = next;
	}
	lst->head = NULL;
}


//打印
void listPrint(list* lst)
{
	struct listNode* cur = lst->head;
	if (lst == NULL || lst->head == NULL)
		return;
	while (cur)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
}

//void test()
//{
//	list lst;
//	listInit(&lst);
//	listPushFront(&lst, 5);
//	listPushFront(&lst, 4);
//	listPushFront(&lst, 3);
//	listPushFront(&lst, 2);
//	listPushFront(&lst, 1);
//	//listPrint(&lst);//1 2 3 4 5  
//
//	//listPushBack(&lst, 1);
//	//listPushBack(&lst, 2);
//	//listPushBack(&lst, 3);
//	//listPushBack(&lst, 4);
//	//listPushBack(&lst, 5);
//	//listPrint(&lst);//1 2 3 4 5 1 2 3 4 5
//
//	listNode* cur = listFind(&lst, 3);
//	listEraseAfter(cur);
//	listPrint(&lst);//1 2 3 5
//	listInsertAfter(cur, 4);
//	listPrint(&lst);//1 2 3 4 5
//}


void test()
{
	list lst;
	listInit(&lst);
	listPushBack(&lst, 5);
	listPushBack(&lst, 4);
	listPushBack(&lst, 3);
	listPushBack(&lst, 2);
	listPushBack(&lst, 1);
	listPrint(&lst);//5 4 3 2 1

	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPrint(&lst);// 5

}

int main()
{
	test();
		return 0;
}

