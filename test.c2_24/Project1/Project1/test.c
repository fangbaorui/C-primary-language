#define _CRT_SECURE_NO_WARNINGS
///*
// * 需求
//
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
//
// 示例 1：
// 输入：nums = [4,1,4,6]
// 输出：[1,6] 或 [6,1]
// 示例 2：
// 输入：nums = [1,2,10,4,1,4,3,3]
// 输出：[2,10] 或 [10,2]
//
//
// 限制：
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
//	/*取得2个数得特征值，出现两次的数字通过^排除掉，所以特征值里面只有2个出现一次的数字*/
//	for (i = 0; i < numsSize; i++) {
//		featureCode = featureCode ^ nums[i];
//	}
//
//	/*取得最右侧的1的特征值，只会含有一个数字（不同为1），作为1个的特征值*/
//	seperator = featureCode & (-featureCode);
//
//	/*提取第一个数字*/
//	for (i = 0; i < numsSize; i++) {
//		/*出现2次的数字被^去掉了*/
//		if (0 != (nums[i] & seperator)) {
//			x = x ^ nums[i];
//		}
//	}
//
//	/*通过^，把X从featureCode里面去掉，这剩下y*/
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

//步骤一：构造一个创造节点的createNode函数，函数里的参数即为先序序列区间，中序序列区间, createNode（Xb, Xe, Zb, Ze）; 返回值类型为指向 node型的指针。
//
//1.判断是否到达递归边界，到达边界了就返回一个 NULL, 即二叉树到达叶子的子节点（叶子节点是不存在子节点的，我就是想表示该节点不存在，不需要构造，要返回上一层，返回到叶子节点）
//
//即判断先序区间长度是否小于等于0，即Xb是否小于等于Xe
//
//2.没到达边界就构造节点

//node * Node = new node;
//
//node->data = data;
//
//3.在中序序列中找到将中序序列分为左子树和右子树的节点位置k
//for (int i = Zb; i < Ze + 1; i++)
//{
//	if (xianxu[Xb] == zhongxu[i])
//	{
//		k = i;
//		break;
//	}
//}

//4.递归

//Node->lchild = create(Xb，Xe，Zb，Ze)；
//
//Node->rchild = create(Xb，Xe，Zb，Ze)


//根据先序中序，构造后序
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
		int Xb, Xe, Zb, Ze;//Xb表示先序开始字符位置Xe表示先序结束字符位置 Zb表示中序开始字符位置,Ze表示中序结束字符位置
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
