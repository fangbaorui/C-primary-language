#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int LDataType;
//����ڵ㣺����+ָ��
typedef struct listNode
{
	LDataType data;
	struct listNode* next;
}listNode;

//����
typedef struct list
{
	//�����һ���ڵ�ĵ�ַ
	listNode* head;
}list;


//��ʼ������
void listInit(list* lst);

//�����½ڵ�
listNode* creatListNode(LDataType val);

//β�壺0��n��
void listPushBack(list* lst, LDataType val);

//βɾ��0��n��
void listPopBack(list* lst);

//ͷ�壺0��1��
void listPushFront(list* lst, LDataType val);

//ͷɾ��o��1��
void listPopFront(list* lst);

//��ĳ��Ԫ��֮�����
void listInsertAfter(listNode* node, LDataType val);

//��ĳ��Ԫ��λ��֮��ɾ��
void listEraseAfter(listNode* node);

//����
struct listNode* listFind(list* lst, LDataType val);

//�ݻ�
void listDestroy(list* lst);

//��ӡ
void listPrint(list* lst);
