#define _CRT_SECURE_NO_WARNINGS
//编写一个程序，找到两个单链表相交的起始节点。两个链表不一定一样长
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	if (headA == NULL || headB == NULL)
		return NULL;
	//先计算两条链表的长度
	struct ListNode* curA, *curB;
	curA = headA;
	curB = headB;
	int a = 0;
	int b = 0;
	while (curA)
	{
		curA = curA->next;
		a++;
	}
	while (curB)
	{
		curB = curB->next;
		b++;
	}
	//让长的链表先走相差的步数
	curA = headA;
	curB = headB;
	int c = abs(a - b);
	if (a > b)
	{
		while (c)
		{
			curA = curA->next;
			c--;
		}
	}
	else
	{
		while (c)
		{
			curB = curB->next;
			c--;
		}
	}
	//两个链表一起走
	while (curA)
	{
		if (curA == curB)
			return curA;
		curA = curA->next;
		curB = curB->next;
	}
	return NULL;
}


//给定一个链表，判断链表中是否有环。
bool hasCycle(struct ListNode* head) {
	struct ListNode* fast, * slow;
	fast = slow = head;
	//让快的走两步，慢的走一步，如果两个相遇则有环，否则没有
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return slow;
	}
	return NULL;
}



//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* fast, * slow, * cur;
	cur = fast = slow = head;
	//让快的走两步，慢的走一步，如果两个相遇则有环，否则没有
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  //成立的话说明有环,则必会相遇
		{
			while (cur != slow)  //当cur==slow的时候，就是第一环的入口结点
			{
				cur = cur->next;
				slow = slow->next;
			}
			return cur;
		}	
	}
	return NULL;
}



//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的 深拷贝。
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
		return head;
	struct Node* cur = head;
	//拷贝数据
	while (cur)
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->val = cur->val;      //拷贝值
		newNode->next = cur->next;       //先连接后面
		cur->next = newNode;        //再连接前面
		cur = newNode->next;         //更新结点
	}
	//拷贝随机指针
	cur = head;      //更新到头结点开始
	while (cur)
	{
		struct Node* copy = cur->next;
		if (cur->random)     //如果存在就拷贝
			copy->random = cur->random->next;
		else            //如果不存在就为空
			copy->random = NULL;
		cur = copy->next;        //更新结点
	}
    //拆链
	cur = head;               //更新到头结点开始
	struct Node* newHead = NULL;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		if (newHead == NULL)
			newHead = copy;     //第一个copy就是新的头
		if (next)           //如果copy->next存在，说明后面还有cur
			copy->next = next->next;      //copy->next连接到下一个cur->next,即copy->next->next
		cur = next;                //更新结点
	}
	return newHead;
}



//对链表进行插入排序。
struct ListNode* insertionSortList(struct ListNode* head) {
	//为空或者只有一个数据就不用排序了
	if (head == NULL || head->next == NULL)
		return head;
	//创建有序数组的尾结点
	struct ListNode* tail = head;
	struct ListNode* prev;
	struct ListNode* cur;
	//从第二个数据开始排
	struct ListNode* node = head->next;
	while (node)
	{
		//待排序的数据小于有序链表的尾结点
		//需要在有序链表中第一个大于待排序数据的数据之前插入待排序数据
		if (node->val < tail->val)
		{
			//置两个指针从有序数据的起始位置找
			prev = NULL;
			cur = head;
			while (cur->val < node->val)
			{
				prev = cur;
				cur = cur->next;
			}
			//跳出循环说明找到第一个大于等于待排序数据的数据了
			//将tail的next连接到待排序数据node的下一个，避免node插入的时候链表断了
			tail->next = node->next;
			//如果在有序数据的前面插入，地址赋给头
			//将node插入到prev与cur之间
			if (prev)
				prev->next = node;
			else
				head = node;
			node->next = cur;
			//更新下一个结点
			node = tail->next;
		}
		//如果node->val >= tail->val,直接进行更新，不用插入
		else 
		{
			tail = tail->next;
			node = tail->next;
		}
	}
	return head;
}



//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点只保留一个
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->3->4->5
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		struct ListNode* next, * cur;
		cur = pHead;
		next = pHead->next;
		while (cur)
		{
			//cur和next相等的时候让next走到和cur不相等的时候，或者走完
			while(cur->val == next->val && next != NULL)
			{
				//每次走一步
				next = next->next;
			}
			//如果next走完，就返回头结点
			if (next == NULL)
				return pHead;
			//不相等的时候，cur走，next走
			cur->next = next;
			cur = cur->next;
			next = next->next;
		}
		return pHead;
	}
};



//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//错误代码
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		struct ListNode* next, * cur, * prev;
		prev = NULL;
		cur = pHead;
		next = pHead->next;
		while (cur)
		{
			if (cur->val != next->val)
			{
				if (prev == NULL)
					pHead = prev = cur;
				else
				{
					prev->next = cur;
					prev = cur;
				}	
				//更新cur到next，next在走一步
				cur->next = next;
				cur = next;
				if (next)
					next = next->next;
				if (next == NULL)
				{
					prev->next = cur;
					prev = cur;
				}
			}
			//直到cur！=next
			while (cur->val == next->val&&next)
			{
				next = next->next;
			}
		}
		if(prev)
			prev->next = NULL;
		return pHead;
	}
};

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	struct ListNode* cur, * prev;
	prev = NULL;
	cur = pHead;
	while (cur)
	{
		if (cur->next && cur->val == cur->next->val)
		{
			cur = cur->next;
			while (cur->next && cur->val == cur->next->val)
			{
				cur = cur->next;
			}
			cur = cur->next;
			prev->next = cur;
		}
		else
		{
			if(prev==NULL)
				pHead = prev = cur;
			prev = cur;
			cur = cur->next;
		}
	}
	return pHead;
}


class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* cur, * prev;
		prev = NULL;
		cur = pHead;
		while (cur)
		{
			if (cur->next && cur->val == cur->next->val)
			{
				cur = cur->next;
				while (cur->next && cur->val == cur->next->val)
				{
					cur = cur->next;
				}
				cur = cur->next;
				prev->next = cur;
			}
			else
			{
				if (prev == NULL)
					pHead = prev = cur;
				prev = cur;
				cur = cur->next;
			}
		}
		return pHead;
	}
};



