#ifndef __MERGESORTLIST_H__
#define __MERGESORTLIST_H__
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//定义m n 为全局变量
int m, n;

struct Node
{
	int data;
	struct Node* next;
}*A, * B, * C, * D;

void printList(struct Node* AList)
{
	int count = 0;
	scanf_s("%d", &count);
	struct Node* post;
	post = AList->next;
	switch (count)
	{
	case 1:
	{
		printf("\n");
		printf("ListA: ");
		break;
	}
	case 2:
	{
		printf("\n");
		printf("ListB: ");
		break;
	}
	case 3:
	{
		printf("\n");
		printf("ListC: ");
		break;
	}
	case 4:
	{
		printf("\n");
		printf("ListD: ");
		break;
	}
	default:
	{
		printf("\n");
		printf("List: ");
		break;
	}
	}
	while (post)
	{
		printf("%d ", post->data);
		post = post->next;
	}
	count++;
}

//链表的初始化
void InitListAB()
{
	A = malloc(sizeof(struct Node));
	if (A == NULL)
		return;
	A->data = 0;
	A->next = NULL;
	B = malloc(sizeof(struct Node));
	if (B == NULL)
		return;
	B->data = 0;
	B->next = NULL;
	C = malloc(sizeof(struct Node));
	if (C == NULL)
		return;
	C->data = 0;
	C->next = NULL;
	D = malloc(sizeof(struct Node));
	if (D == NULL)
		return;
	D->data = 0;
	D->next = NULL;
	int i;
	struct Node* post;
	struct Node* pre;
	printf("m=");
	scanf_s("%d", &m);
	printf("n=");
	scanf_s("%d", &n);
	pre = A;
	for (i = 1; i <= m; i++)
	{
		post = malloc(sizeof(struct Node));
		if (post == NULL)
			return;
		printf("A%d=", i);
		scanf_s("%d", &(post->data));
		post->next = NULL;
		pre->next = post;
		pre = post;
	}
	pre = B;
	for (i = 1; i <= n; i++)
	{
		post = malloc(sizeof(struct Node));
		if (post == NULL)
			return;
		printf("B%d=", i);
		scanf_s("%d", &(post->data));
		post->next = NULL;
		pre->next = post;
		pre = post;
	}
}

//合并链表
void MergeABToC()
{
	int i;
	struct Node* pre, * postA, * postB, * postC;
	pre = C;
	postA = A->next;
	postB = B->next;
	if (m >= n)
	{
		for (i = 1; i <= n; i++)
		{
			postC = malloc(sizeof(struct Node));
			if (postC == NULL)
				return;
			postC->data = postA->data;
			postC->next = 0;
			pre->next = postC;
			pre = postC;
			postC = malloc(sizeof(struct Node));
			if (postC == NULL)
				return;
			postC->data = postB->data;
			postC->next = 0;
			pre->next = postC;
			pre = postC;
			postA = postA->next;
			postB = postB->next;
		}
		for (i = n + 1; i <= m; i++)
		{
			postC = malloc(sizeof(struct Node));
			if (postC == NULL)
				return;
			postC->data = postA->data;
			postC->next = 0;
			pre->next = postC;
			pre = postC;
			postA = postA->next;
		}
	}
	else
	{
		for (i = 1; i <= m; i++)
		{
			postC = malloc(sizeof(struct Node));
			if (postC == NULL)
				return;
			postC->data = postB->data;
			postC->next = 0;
			pre->next = postC;
			pre = postC;
			postC = malloc(sizeof(struct Node));
			if (postC == NULL)
				return;
			postC->data = postA->data;
			postC->next = 0;
			pre->next = postC;
			pre = postC;
			postA = postA->next;
			postB = postB->next;
		}
		for (i = m + 1; i <= n; i++)
		{
			postC = malloc(sizeof(struct Node));
			if (postC == NULL)
				return;
			postC->data = postB->data;
			postC->next = 0;
			pre->next = postC;
			pre = postC;
			postB = postB->next;
		}
	}
}

//对合并后的链表进行排序
void SortCToD()
{
	struct Node* pre, * postC, * postD, * lopD;
	int len;     //表示总的长度
	len = m + n;
	pre = D;       //指向D有序数列的尾指针
	postC = C->next;
	postD = malloc(sizeof(struct Node));    // 列表D第一个节点加入 ，分配一个新的节点
	if (postD == NULL)
		return;
	postD->data = postC->data;
	postD->next = 0;
	pre->next = postD;
	pre = postD;
	postC = postC->next;
	while (postC)
	{                 //pre为指向插入的前一个节点，lopD是指向插入的后一个节点
		pre = D;
		lopD = D->next;
		while (lopD)
		{
			if (lopD->data > postC->data)      //判断条件
				break;
			else
			{
				pre = lopD;        //pre指向D
				lopD = lopD->next;      //指向下一个节点
			}
		}
		postD = malloc(sizeof(struct Node));
		if (postD == NULL)
			return;
		postD->data = postC->data;      //将D的值赋给C
		postD->next = 0;
		pre->next = postD;
		postD->next = lopD;
		postC = postC->next;       //指向下一个节点
	}
}
#endif // !__MERGESORTLIST_H__


int main()
{
	printf("********************************************************\n");
	printf("****                  欢迎使用本系统                ****\n");
	printf("********************************************************\n");
	printf("------请输入链表A的长度m，链表B的程度n：>\n");
	InitListAB();       //初始化A、B链表
	MergeABToC();       //合并A、B链表
	SortCToD();         //对C进行直接插入排序得到D
	printf("-------    分别输入1 2 3 4对应链表A B C D         -------\n");
	printf("输出链表A为：>");
	printList(A);
	printf("\n");
	printf("输出链表B为：>");
	printList(B);
	printf("\n");
	printf("合并后的链表C为：>");
	printList(C);
	printf("\n");
	printf("C按升序排列后的链表D为：>");
	printf("\n");
	printList(D);
	system("pause");
	return 0;
}