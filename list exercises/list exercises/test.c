//移除链表元素
//删除链表中等于给定值 val 的所有节点。
//示例 :
//输入: 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5
//用cur和prev分别记录某个数据和这个数据的上一个数据，再用next记录要删除数据cur的下一个数据.
//如果第一个数据要删除，把next赋给head，如果不是再prev的下一个指向next连接起来，最后释放掉
//cur，然后更新cur.   如果不删除prev指向cur，cur=cur->next
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)  //如果头为空就返回了
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			//连接
			if (cur == head)//if(prev==NULL),如果第一个数据要删除，把第二个数据连接到头结点
				head = next;
			else
				prev->next = next;
			//移除
			free(cur);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)  //如果头为空就返回了
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			//移除
			free(cur);
			//连接
			if (cur == head)//if(prev==NULL),如果第一个数据要删除，把第二个数据连接到头结点
				head = next;
			else
				prev->next = next;
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}




//反转链表,反转一个单链表。
//示例 :
//输入: 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//原地头插，建立新的头NewHead==NULL,用cur指向1，用next保存在一个数据2，
//将1插在NewHead后面，更新NewHead,cur，next，均指向下一个数据，一直插到cur==NULL
//每次都将数据插入到下一个数据后面NULL<-1<-2<-3<-4<-5<-NULL,只改变箭头的位置
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)  //如果头为空，或者头的下一个元素为空，直接返回
		return head;
	struct ListNode* cur, * NewHead,* next;
	cur = head;
	NewHead = NULL;
	while (cur)
	{
		//记录下一个位置
		next = cur->next;
		//头插
		cur->next = NewHead; 
		NewHead = cur;
		//更新结点
		cur = next;
	}
	return NewHead;
}


//去三个结点，n1为空，n2=head，n3=n2->next，利用n3来保存下一个数据的位置，
//将n2->next指向n3改成n2->next指向n1，依次把链表的指向该变，直到n2==NULL，返回n1，n1指向最后一个数据
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* n1, * n2, * n3;
	n1 = NULL;
	n2 = head;
	if(n2)
		n3 = n2->next;
	while (n2)
	{
		//改变n2的指向
		n2->next = n1;
		//n1，n2都更新到下一个位置
		n1 = n2;
		n2 = n3;
		//n3更新到下一个位置，当n3==NULL时，不能解引用，不用更新，n2指向最后一个元素，再循环一个n2==NULL
		if(n3)
			n3 = n3->next;
	}
	//n1指向最后一个元素，返回
	return n1;
}



//给定一个头结点为 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//示例 1：
//输入：[1, 2, 3, 4, 5]
//输出：此列表中的结点 3 (序列化形式：[3, 4, 5])
//返回的结点值为 3 。(测评系统对该结点序列化表述是[3, 4, 5])。
//创建两个结点，fast每次走两边，slow每次走一步，这样的话，fast==NULL时，slow就是中间结点
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast, * slow;
	fast = slow = head;
	//当fsat==NULL，或者fast->next==NULL都返回，奇偶链表都可以
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	//返回之间结点
	return slow;
}



//输入一个链表，输出该链表中倒数第k个结点
//先让fast走k步，然后fast再走到NULL的位置，fast走了k+n-k步，slow走了n-k步，正好是倒数第k个结点
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	// write code here
	struct ListNode* fast, * slow;
	fast = slow = pListHead;
	while (k--)
	{
		//如果fast==NULL，就不能再解引用
		if (fast)
			fast = fast->next;
		else
			return NULL;  //k大于链表长度
	}
	while (fast)
	{
		//fast，slow都走一步，直到fsat走完
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}



//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//创建一个新结点，将s1与s2中较小的值传与，那个传值了那个就更新，最后
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL|| l2 == NULL)
		return l1 == NULL ? l2 : l1;
	struct ListNode* cur1, * cur2, * newHead, * newTail;
	cur1 = l1;
	cur2 = l2;
	newHead = newTail = NULL;
	//同时遍历
	while (cur1 && cur2)
	{
		if (cur1->val <= cur2->val)
		{
			if (newTail==NULL)
			{
				newHead = newTail = cur1;
			}
			else
			{
				newTail->next = cur1;
				newTail = newTail->next;
			}
			cur1 = cur1->next;
		}
		else
		{
			if (newTail == NULL)
			{
				newHead = newTail = cur2;
			}
			else
			{
				newTail->next = cur2;
				newTail = newTail->next;
			}
			cur2 = cur2->next;
		}
	}
    if(cur1)
        newTail->next = cur1;
	if(cur2)
		newTail->next = cur2;
	return newHead;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL || l2 == NULL)
		return l1 == NULL ? l2 : l1;
	struct ListNode* cur1, * cur2, * newHead, * newTail;
	newHead = newTail = NULL;
	//先确定头结点
	if (l1->val <= l2->val)
	{
		newHead = newTail = l1;
		l1 = l1->next;
	}
	else
	{
		newHead = newTail = l2;
		l2 = l2->next;
	}
	cur1 = l1;
	cur2 = l2;
	//同时遍历
	while (cur1 && cur2)
	{
		if (cur1->val <= cur2->val)
		{			
		newTail->next = cur1;
		newTail = newTail->next;
		cur1 = cur1->next;
		}
		else
		{
		newTail->next = cur2;
		newTail = newTail->next;		
		cur2 = cur2->next;
		}
	}
	if (cur1)
		newTail->next = cur1;
	if (cur2)
		newTail->next = cur2;
	return newHead;
}


//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		//如果pHead为空，返回
		if (pHead == NULL)
			return pHead;
		struct ListNode* lessTail, * greaterTail, * cur, * lessHead, * greaterHead;
		//动态创建头结点
		lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur = pHead;
		//同时遍历
		while (cur)
		{
			if (cur->val < x)
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
				cur = cur->next;
			}
			else
			{
				greaterTail->next = cur;
				greaterTail = greaterTail->next;
				cur = cur->next;
			}
		}
		//大链表尾置空
		if (greaterTail)
			greaterTail->next = NULL;
		lessTail->next = greaterHead->next;
		//创建新的头指向小链表头lessHead的下一个
		struct ListNode* newHead = lessHead->next;
		//释放
		free(greaterHead);
		free(lessHead);
		return newHead;
	}
};

//建立五个结点lessHead ， lessTail ，greaterHead ，greaterTail ，NULL，cur
//将值小于x的链表存入lessTail中并更新，将大于等于x的值存入greaterTail中并更新，
//最后将两个链表连接起来,让链表的尾为空，返回链表的头结点
ListNode* partition(ListNode* pHead, int x) {
	//如果pHead为空，返回
	if (pHead == NULL)
		return pHead;
	struct ListNode* lessTail, * greaterTail, * cur, * lessHead, * greaterHead;
	lessHead = lessTail = greaterHead = greaterTail = NULL;
	cur = pHead;
	//同时遍历
	while (cur)
	{
		//存入小链表
		if (cur->val < x)
		{
			if (lessTail == NULL)  //第一个数据
				lessHead = lessTail = cur;
			else
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}
			cur = cur->next;
		}
		//存入大链表
		else
		{
			if (greaterTail == NULL)   //第一个数据
				greaterHead = greaterTail = cur;
			else
			{
				greaterTail->next = cur;
				greaterTail = greaterTail->next;
			}
			cur = cur->next;
		}
	}
	//如果大链表尾存在，将尾的下一个置空
	if (greaterTail)
		greaterTail->next = NULL;
	//如果小链表头为空，返回大链表头
	if (lessHead==NULL)
		return greaterHead;
	//如果大链表头为空，如果小链表尾存在，将尾的下一个置空，返回小链表头
	if (greaterHead == NULL)
	{
		if (lessTail)
			lessTail->next = NULL;
		return lessHead;
	}
	//两个链表都不为空,连接两个链表
	lessTail->next = greaterHead;
	return lessHead;
}



//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：
//1->2->2->1
//返回：true
//1.找到中间结点，2.逆转后半部分，3.遍历两部分链表（前半部分，逆转之后的后半部分）
//
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL || A->next == NULL)
			return true;
		struct ListNode* fast, * slow;
		fast = slow = A;
		//找到中间结点
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		//逆转后半部分
		struct ListNode* cur = slow;
		struct ListNode* NewHead = NULL;
		while (cur)
		{
			struct ListNode*  next;
			//记录下一个位置
			next = cur->next;
			//头插
			cur->next = NewHead;
			NewHead = cur;
			//更新结点
			cur = next;
		}

		//遍历两部分链表（前半部分，逆转之后的后半部分）
		while (A && NewHead)
		{
			if (A->val != NewHead->val)
			{
				return false;
			}
			A = A->next;
			NewHead = NewHead->next;
		}
		return true;
	}
};