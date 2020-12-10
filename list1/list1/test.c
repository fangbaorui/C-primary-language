#ifndef __MERGESORTLIST_H__
#define __MERGESORTLIST_H__
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//����m n Ϊȫ�ֱ���
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

//����ĳ�ʼ��
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

//�ϲ�����
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

//�Ժϲ���������������
void SortCToD()
{
	struct Node* pre, * postC, * postD, * lopD;
	int len;     //��ʾ�ܵĳ���
	len = m + n;
	pre = D;       //ָ��D�������е�βָ��
	postC = C->next;
	postD = malloc(sizeof(struct Node));    // �б�D��һ���ڵ���� ������һ���µĽڵ�
	if (postD == NULL)
		return;
	postD->data = postC->data;
	postD->next = 0;
	pre->next = postD;
	pre = postD;
	postC = postC->next;
	while (postC)
	{                 //preΪָ������ǰһ���ڵ㣬lopD��ָ�����ĺ�һ���ڵ�
		pre = D;
		lopD = D->next;
		while (lopD)
		{
			if (lopD->data > postC->data)      //�ж�����
				break;
			else
			{
				pre = lopD;        //preָ��D
				lopD = lopD->next;      //ָ����һ���ڵ�
			}
		}
		postD = malloc(sizeof(struct Node));
		if (postD == NULL)
			return;
		postD->data = postC->data;      //��D��ֵ����C
		postD->next = 0;
		pre->next = postD;
		postD->next = lopD;
		postC = postC->next;       //ָ����һ���ڵ�
	}
}
#endif // !__MERGESORTLIST_H__


int main()
{
	printf("********************************************************\n");
	printf("****                  ��ӭʹ�ñ�ϵͳ                ****\n");
	printf("********************************************************\n");
	printf("------����������A�ĳ���m������B�ĳ̶�n��>\n");
	InitListAB();       //��ʼ��A��B����
	MergeABToC();       //�ϲ�A��B����
	SortCToD();         //��C����ֱ�Ӳ�������õ�D
	printf("-------    �ֱ�����1 2 3 4��Ӧ����A B C D         -------\n");
	printf("�������AΪ��>");
	printList(A);
	printf("\n");
	printf("�������BΪ��>");
	printList(B);
	printf("\n");
	printf("�ϲ��������CΪ��>");
	printList(C);
	printf("\n");
	printf("C���������к������DΪ��>");
	printf("\n");
	printList(D);
	system("pause");
	return 0;
}