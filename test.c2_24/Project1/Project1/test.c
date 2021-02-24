#define _CRT_SECURE_NO_WARNINGS
///*
// * ����
//
// һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
//
// ʾ�� 1��
// ���룺nums = [4,1,4,6]
// �����[1,6] �� [6,1]
// ʾ�� 2��
// ���룺nums = [1,2,10,4,1,4,3,3]
// �����[2,10] �� [10,2]
//
//
// ���ƣ�
// 2 <= nums <= 10000
//
// gcc singleNumbers-I.c -g -o a.exe -DDEBUG
// */
//
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//
//#ifdef DEBUG
//#define LOG(fmt, args...) fprintf(stdout, fmt, ##args)
//#else
//#define LOG(fmt,...)
//#endif
//
//#define TRUE        1
//#define FALSE       0
//
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//#define MIN(a, b) ((a) > (b) ? (b) : (a))
//
//
//
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* singleNumbers(int* nums, int numsSize, int* returnSize) {
//
//	if (NULL == nums || 0 == numsSize) {
//		*returnSize = 0;
//		return NULL;
//	}
//
//	int* retp = NULL;
//	int featureCode = 0, seperator = 0, i = 0, x = 0, y = 0;
//
//	retp = (int*)malloc(2 * sizeof(int));
//	if (NULL == retp) {
//		*returnSize = 0;
//		return NULL;
//	}
//	memset(retp, 0, 2 * sizeof(int));
//	*returnSize = 2;
//
//	/*ȡ��2����������ֵ���������ε�����ͨ��^�ų�������������ֵ����ֻ��2������һ�ε�����*/
//	for (i = 0; i < numsSize; i++) {
//		featureCode = featureCode ^ nums[i];
//	}
//
//	/*ȡ�����Ҳ��1������ֵ��ֻ�Ậ��һ�����֣���ͬΪ1������Ϊ1��������ֵ*/
//	seperator = featureCode & (-featureCode);
//
//	/*��ȡ��һ������*/
//	for (i = 0; i < numsSize; i++) {
//		/*����2�ε����ֱ�^ȥ����*/
//		if (0 != (nums[i] & seperator)) {
//			x = x ^ nums[i];
//		}
//	}
//
//	/*ͨ��^����X��featureCode����ȥ������ʣ��y*/
//	y = featureCode ^ x;
//
//	retp[0] = x;
//	retp[1] = y;
//
//
//	return retp;
//
//}
//
//
//void testsingleNumbers(void) {
//
//	printf("\n************  testsingleNumbers ************ \n");
//	int* retp = NULL;
//	int returnSize = 0;
//
//	int nums1[4] = { 4,1,4,6 };
//	retp = singleNumbers(nums1, 4, &returnSize);
//	printf("returnSize = %d, retp[0] = %d, retp[1] = %d\n", returnSize, retp[0], retp[1]);
//	if (NULL != retp) {
//		free(retp);
//		retp = NULL;
//	}
//
//	int nums2[8] = { 1,2,10,4,1,4,3,3 };
//	retp = singleNumbers(nums2, 8, &returnSize);
//	printf("returnSize = %d, retp[0] = %d, retp[1] = %d\n", returnSize, retp[0], retp[1]);
//	if (NULL != retp) {
//		free(retp);
//		retp = NULL;
//	}
//
//	return;
//
//}
//
//
//int main(int argc, char** argv) {
//	testsingleNumbers();
//}




struct node
{
	char data;
	node* lchild;
	node* rchild;
};

//����һ������һ������ڵ��createNode������������Ĳ�����Ϊ�����������䣬������������, createNode��Xb, Xe, Zb, Ze��; ����ֵ����Ϊָ�� node�͵�ָ�롣
//
//1.�ж��Ƿ񵽴�ݹ�߽磬����߽��˾ͷ���һ�� NULL, ������������Ҷ�ӵ��ӽڵ㣨Ҷ�ӽڵ��ǲ������ӽڵ�ģ��Ҿ������ʾ�ýڵ㲻���ڣ�����Ҫ���죬Ҫ������һ�㣬���ص�Ҷ�ӽڵ㣩
//
//���ж��������䳤���Ƿ�С�ڵ���0����Xb�Ƿ�С�ڵ���Xe
//
//2.û����߽�͹���ڵ�

//node * Node = new node;
//
//node->data = data;
//
//3.�������������ҵ����������з�Ϊ���������������Ľڵ�λ��k
//for (int i = Zb; i < Ze + 1; i++)
//{
//	if (xianxu[Xb] == zhongxu[i])
//	{
//		k = i;
//		break;
//	}
//}

//4.�ݹ�

//Node->lchild = create(Xb��Xe��Zb��Ze)��
//
//Node->rchild = create(Xb��Xe��Zb��Ze)


//�����������򣬹������
#include <iostream>
#include <string>
using namespace std;
struct node
{
	char data;
	node* lchild;
	node* rchild;
};
node* createNode(int Xb, int Xe, int Zb, int Ze, string xianxu, string zhongxu);
void houxu(node * Node);
int main()
{
	string xianxu;
	string zhongxu;
	while (cin >> xianxu) 
	{

		cin >> zhongxu;
		int Xb, Xe, Zb, Ze;//Xb��ʾ����ʼ�ַ�λ��Xe��ʾ��������ַ�λ�� Zb��ʾ����ʼ�ַ�λ��,Ze��ʾ��������ַ�λ��
		Xb = Zb = 0;
		Xe = xianxu.length() - 1;
		Ze = zhongxu.length() - 1;
		node* Node = new node;
		Node = createNode(Xb, Xe, Zb, Ze, xianxu, zhongxu);
		houxu(Node);
		}
		system("pause");
		return 0;
	}
	node* createNode(int Xb, int Xe, int Zb, int Ze, string xianxu, string zhongxu)
	{
		if (Xb > Xe)
			return NULL;
		node* Node = new node;
		Node->data = xianxu[Xb];
		int k = 0;
		for (int i = Zb; i < Ze + 1; i++)
		{
			if (xianxu[Xb] == zhongxu[i])
			{
				k = i;
				break;
			}
		}
		Node->lchild = createNode(Xb + 1, Xb + k - Zb, Zb, k - 1, xianxu, zhongxu);
		Node->rchild = createNode(Xb + k - Zb + 1, Xe, k + 1, Ze, xianxu, zhongxu);

		return Node;
	}
	void houxu(node* Node)
	{
		if (Node == NULL)
			return;
		houxu(Node->lchild);
		houxu(Node->rchild);
		cout << Node->data;
	}
