#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int LDataType;
//定义节点：数据+指针
typedef struct listNode
{
	LDataType data;
	struct listNode* next;
}listNode;

//链表
typedef struct list
{
	//保存第一个节点的地址
	listNode* head;
}list;


//初始化链表
void listInit(list* lst);

//创建新节点
listNode* creatListNode(LDataType val);

//尾插：0（n）
void listPushBack(list* lst, LDataType val);

//尾删：0（n）
void listPopBack(list* lst);

//头插：0（1）
void listPushFront(list* lst, LDataType val);

//头删：o（1）
void listPopFront(list* lst);

//在某个元素之后插入
void listInsertAfter(listNode* node, LDataType val);

//在某个元素位置之后删除
void listEraseAfter(listNode* node);

//查找
struct listNode* listFind(list* lst, LDataType val);

//摧毁
void listDestroy(list* lst);

//打印
void listPrint(list* lst);
