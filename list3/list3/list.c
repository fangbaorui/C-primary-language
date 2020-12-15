#define _CRT_SECURE_NO_WARNINGS
// Note:Your choice is C++ IDE
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
//�궨��
#define L sizeof(struct Node)
//�ṹ����
struct Node
{
	long int number;
	struct Node* next;
};

//����������
struct Node* create(int a)
{
	int n;
	struct Node* p1, * p2, * head;
	head = NULL;
	n = 0;
	//��̬�ڴ濪��
	p2 = p1 = (struct Node*)malloc(L);
	scanf("%ld", &p1->number);
	//¼��������Ϣ
	while (a)   //a��������
	{
		n = n + 1;
		if (n == 1)  //p1����ͷ���
			head = p1;
		else
			p2->next = p1;  //������δ���
		p2 = p1;
		//��̬�ڴ濪��
		p1 = (struct Node*)malloc(L);
		if (a != 1)
			scanf("%ld", &p1->number);  //�������������ֵ
		a--; //��������ĸ���
	}
	p2->next = NULL;   //���һ���ڵ�ָ���
	return (head);   //����ͷ���
}//��������������

//��ӡ����
void print(struct Node* head)
{
	struct Node* p;
	p = head;
	printf("����:\n");
	if (head != NULL)  //ͷ��㲻Ϊ�գ���ֵ�������
		//ѭ��ʵ�����
		do
		{
			printf("%ld", p->number);
			printf("     ");
			p = p->next;
		} while (p != NULL);  //���δ�ӡ�������Ա
		printf("\n");
}

//����Ľ���ϲ��㷨
struct Node* inter_link(struct Node* chain1, int a, struct Node* chain2, int b)//����1������a������2,����b
{
	int temp;
	struct Node* head, * p1, * p2, * pos;
	/*�ж�a��b��С���ϲ� */
	if (a >= b) {   //���ֵ��������1��С��ֵ��������2
		head = p1 = chain1;
		p2 = chain2;
	}
	else/*b>a*/ {
		head = p1 = chain2;
		p2 = chain1;
		temp = a, a = b, b = temp; /*����a��b*/
	}

	/*�����p1��ÿ��Ԫ�ز���p2��ӦԪ��֮ǰ��p1��a,p2��b*/
	pos = head; /*��ʱposָ��p1�еĵ�һ��Ԫ��*/
	while (p2 != NULL) {//p2��p1��
		p1 = p1->next;  //p1ָ��p1��һ��
		pos->next = p2;  //p2������һ���ڵ�
		pos = p2;      //posָ��p2
		pos = p2;
		p2 = p2->next;   //p2ָ��p2��һ��
		pos->next = p1;   //p1����pos��һ�����
		pos = p1;         //p1����pos
	}
	return head;   //����ͷ���
}
//�Ժϲ��õ������������ð������
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
//������
int main()//main����
{
	struct Node* p1, * p2;
	int a;
	int b;
	int h;
	printf("�������һ������:\n");
	printf("\n��������ĳ���a:\n");
	scanf("%d", &a);
	printf("�������������ݣ�");
	p1 = create(a);
	printf("\n��ղ�����ĵ�һ��������Ϣ:\n ");
	print(p1);
	printf("\n ������ڶ�������:\n");
	printf("\n��������ĳ���b:\n");
	scanf("%d", &b);
	printf("�������������ݣ�");
	p2 = create(b);
	printf("\n��ղ�����ĵڶ����������Ϣ:\n");
	print(p2);
	p1 = inter_link(p1, a, p2, b);
	h = a + b;
	printf("\n�ϲ��������\n��");
	print(p1);
	InsertSort(p1, h);
	printf("\n����������:\n");
	print(p1);
	return 0;
}