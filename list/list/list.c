#include"list.h"

//�����½ڵ�
listNode* creatListNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->data = val;
	node->next = NULL;
	return node;
}

//��ʼ������
void listInit(list* lst)
{
	//��ʼ��������
	if (lst == NULL)
		return;
	lst->head = NULL;
}

//β�壺0��n��
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->head == NULL)
	{
		//�����һ���ڵ�
		//�����ڵ�
		lst->head = creatListNode(val);
	}
	else
	{
		//�ӵ�һ���ڵ㿪ʼ�������ҵ����һ���ڵ�
		listNode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail= tail->next;
		}
		tail->next = creatListNode(val);
	}
}

//βɾ��0��n��
void listPopBack(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	//�������ҵ����һ���ڵ�
	struct listNode* prev = NULL;
	struct listNode* tail = lst->head;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}

	//�ͷ����һ���ڵ�
	free(tail);
	//����next
	if (prev == NULL)  //ֻ��һ���ڵ㣬����head�ڵ�
		//if(lst->head->next==NULL)
		lst->head = NULL;
	else
		prev->next = NULL;
}

//ͷ�壺0��1��
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//�����ڵ�
	struct listNode* node = creatListNode(val);

	node->next = lst->head;
	lst->head = node;
}

//ͷɾ��o��1��
void listPopFront(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* next = lst -> head->next;
	free(lst->head);
	lst->head = next;
}

//��ĳ��Ԫ��֮�����
void listInsertAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;

	struct listNode* newNode = creatListNode(val);

	struct listNode* next = node->next;
	node->next = newNode;
	newNode->next = next;
}

//��ĳ��Ԫ��λ��֮��ɾ��
void listEraseAfter(listNode* node)
{
	if (node == NULL || node->next == NULL)
		return;
	struct listNode* next = node->next;
	struct listNode* nextnext = next->next;

	//�ͷ�next
	free(next);
	node->next = nextnext;
}

//����
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

//�ݻ�
void listDestroy(list* lst)
{
	if (lst == NULL)
		return;
	listNode* cur = lst->head;
	while (cur)
	{
		//������һ���ڵ��λ��
		listNode* next = cur->next;
		//�ͷŵ�ǰ�ڵ�
		free(cur);
		//���µ���һ���ڵ��λ��
		cur = next;
	}
	lst->head = NULL;
}


//��ӡ
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

