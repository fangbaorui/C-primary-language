#define _CRT_SECURE_NO_WARNINGS
// Note:Your choice is C++ IDE
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
//宏定义
#define L sizeof(struct Node)
//结构体结点
struct Node
{
	long int number;
	struct Node* next;
};

//链表创建函数
struct Node* create(int a)
{
	int n;
	struct Node* p1, * p2, * head;
	head = NULL;
	n = 0;
	//动态内存开辟
	p2 = p1 = (struct Node*)malloc(L);
	scanf("%ld", &p1->number);
	//录入链表信息
	while (a)   //a是链表长度
	{
		n = n + 1;
		if (n == 1)  //p1赋给头结点
			head = p1;
		else
			p2->next = p1;  //结点依次创建
		p2 = p1;
		//动态内存开辟
		p1 = (struct Node*)malloc(L);
		if (a != 1)
			scanf("%ld", &p1->number);  //依次输入链表的值
		a--; //控制输入的个数
	}
	p2->next = NULL;   //最后一个节点指向空
	return (head);   //返回头结点
}//链表创建函数结束

//打印函数
void print(struct Node* head)
{
	struct Node* p;
	p = head;
	printf("数字:\n");
	if (head != NULL)  //头结点不为空，有值可以输出
		//循环实现输出
		do
		{
			printf("%ld", p->number);
			printf("     ");
			p = p->next;
		} while (p != NULL);  //依次打印出链表成员
		printf("\n");
}

//链表的交叉合并算法
struct Node* inter_link(struct Node* chain1, int a, struct Node* chain2, int b)//链表1，长度a，链表2,长度b
{
	int temp;
	struct Node* head, * p1, * p2, * pos;
	/*判断a，b大小并合并 */
	if (a >= b) {   //大的值赋给链表1，小的值赋给链表2
		head = p1 = chain1;
		p2 = chain2;
	}
	else/*b>a*/ {
		head = p1 = chain2;
		p2 = chain1;
		temp = a, a = b, b = temp; /*交换a和b*/
	}

	/*下面把p1的每个元素插在p2相应元素之前，p1长a,p2长b*/
	pos = head; /*此时pos指向p1中的第一个元素*/
	while (p2 != NULL) {//p2比p1长
		p1 = p1->next;  //p1指向p1下一个
		pos->next = p2;  //p2赋给第一个节点
		pos = p2;      //pos指向p2
		pos = p2;
		p2 = p2->next;   //p2指向p2下一个
		pos->next = p1;   //p1赋给pos下一个结点
		pos = p1;         //p1赋给pos
	}
	return head;   //返回头结点
}
//对合并好的链表进行排序，冒泡排序
void InsertSort(struct Node* p, int m)
{
	int i, j, t;
	struct Node* k;
	k = p;
	for (i = 0; i < m - 1; i++) {
		for (j = 0; j < m - i - 1; j++) {
			if (p->number > (p->next)->number) {
				t = p->number;
				p->number = (p->next)->number;
				(p->next)->number = t;
			}
			p = p->next;
		}
		p = k;
	}
}
//主函数
int main()//main函数
{
	struct Node* p1, * p2;
	int a;
	int b;
	int h;
	printf("请输入第一个链表:\n");
	printf("\n输入链表的长度a:\n");
	scanf("%d", &a);
	printf("请输入链表数据：");
	p1 = create(a);
	printf("\n你刚才输入的第一个链表信息:\n ");
	print(p1);
	printf("\n 请输入第二个链表:\n");
	printf("\n输入链表的长度b:\n");
	scanf("%d", &b);
	printf("请输入链表数据：");
	p2 = create(b);
	printf("\n你刚才输入的第二个链表的信息:\n");
	print(p2);
	p1 = inter_link(p1, a, p2, b);
	h = a + b;
	printf("\n合并后的链表\n：");
	print(p1);
	InsertSort(p1, h);
	printf("\n排序后的链表:\n");
	print(p1);
	return 0;
}