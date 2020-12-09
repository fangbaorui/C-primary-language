#pragma once
#define N 100
typedef int SLDataType;
////静态顺序表
//struct seqlist2
//{
//	SLDataType data[N];//定长数组
//	int size;          //有效数据个数
//};                     //sizeof(seqlist2)=404


//动态顺序表
typedef struct seqList
{
	SLDataType* data; //数组指针
	int size;            //有效元素个数
	int capacity;//数组的空间
}seqList;       //sizeof(seqlist)=12


//初始化顺序表
void initseqList(seqList* sl);

//尾插
void seqListPushBack(seqList* sl, SLDataType val);

//尾删
void seqListpopBack(seqList* sl);

//检查容量
void seqListCheckCapacity(seqList* sl);

//打印
void seqListPrint(seqList* sl);

//访问任意位置的元素
SLDataType seqListAt(seqList* sl, int pos);

//判空
void seqListEmpty(seqList* sl);

//有效元素个数
int seqListSize(seqList* sl);

//头插
void seqListPushFront(seqList* sl, SLDataType val);

//头删
void seqListPopFront(seqList* sl);

//任意位置插入
void seqListInsert(seqList* sl, int pos, SLDataType val);

//任意位置删除
void seqListErase(seqList* sl, int pos);

//销毁
void seqListDestroy(seqList* sl);

//查找
int seqListFind(seqList* sl, SLDataType val);