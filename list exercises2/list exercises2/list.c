#define _CRT_SECURE_NO_WARNINGS
//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣��������һ��һ����
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	if (headA == NULL || headB == NULL)
		return NULL;
	//�ȼ�����������ĳ���
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
	//�ó��������������Ĳ���
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
	//��������һ����
	while (curA)
	{
		if (curA == curB)
			return curA;
		curA = curA->next;
		curB = curB->next;
	}
	return NULL;
}


//����һ�������ж��������Ƿ��л���
bool hasCycle(struct ListNode* head) {
	struct ListNode* fast, * slow;
	fast = slow = head;
	//�ÿ����������������һ������������������л�������û��
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return slow;
	}
	return NULL;
}



//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL
struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* fast, * slow, * cur;
	cur = fast = slow = head;
	//�ÿ����������������һ������������������л�������û��
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  //�����Ļ�˵���л�,��ػ�����
		{
			while (cur != slow)  //��cur==slow��ʱ�򣬾��ǵ�һ������ڽ��
			{
				cur = cur->next;
				slow = slow->next;
			}
			return cur;
		}	
	}
	return NULL;
}



//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻��������� �����
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
		return head;
	struct Node* cur = head;
	//��������
	while (cur)
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->val = cur->val;      //����ֵ
		newNode->next = cur->next;       //�����Ӻ���
		cur->next = newNode;        //������ǰ��
		cur = newNode->next;         //���½��
	}
	//�������ָ��
	cur = head;      //���µ�ͷ��㿪ʼ
	while (cur)
	{
		struct Node* copy = cur->next;
		if (cur->random)     //������ھͿ���
			copy->random = cur->random->next;
		else            //��������ھ�Ϊ��
			copy->random = NULL;
		cur = copy->next;        //���½��
	}
    //����
	cur = head;               //���µ�ͷ��㿪ʼ
	struct Node* newHead = NULL;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		if (newHead == NULL)
			newHead = copy;     //��һ��copy�����µ�ͷ
		if (next)           //���copy->next���ڣ�˵�����滹��cur
			copy->next = next->next;      //copy->next���ӵ���һ��cur->next,��copy->next->next
		cur = next;                //���½��
	}
	return newHead;
}



//��������в�������
struct ListNode* insertionSortList(struct ListNode* head) {
	//Ϊ�ջ���ֻ��һ�����ݾͲ���������
	if (head == NULL || head->next == NULL)
		return head;
	//�������������β���
	struct ListNode* tail = head;
	struct ListNode* prev;
	struct ListNode* cur;
	//�ӵڶ������ݿ�ʼ��
	struct ListNode* node = head->next;
	while (node)
	{
		//�����������С�����������β���
		//��Ҫ�����������е�һ�����ڴ��������ݵ�����֮ǰ�������������
		if (node->val < tail->val)
		{
			//������ָ����������ݵ���ʼλ����
			prev = NULL;
			cur = head;
			while (cur->val < node->val)
			{
				prev = cur;
				cur = cur->next;
			}
			//����ѭ��˵���ҵ���һ�����ڵ��ڴ��������ݵ�������
			//��tail��next���ӵ�����������node����һ��������node�����ʱ���������
			tail->next = node->next;
			//������������ݵ�ǰ����룬��ַ����ͷ
			//��node���뵽prev��cur֮��
			if (prev)
				prev->next = node;
			else
				head = node;
			node->next = cur;
			//������һ�����
			node = tail->next;
		}
		//���node->val >= tail->val,ֱ�ӽ��и��£����ò���
		else 
		{
			tail = tail->next;
			node = tail->next;
		}
	}
	return head;
}



//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ��ֻ����һ��
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->3->4->5
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
			//cur��next��ȵ�ʱ����next�ߵ���cur����ȵ�ʱ�򣬻�������
			while(cur->val == next->val && next != NULL)
			{
				//ÿ����һ��
				next = next->next;
			}
			//���next���꣬�ͷ���ͷ���
			if (next == NULL)
				return pHead;
			//����ȵ�ʱ��cur�ߣ�next��
			cur->next = next;
			cur = cur->next;
			next = next->next;
		}
		return pHead;
	}
};



//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
//�������
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
				//����cur��next��next����һ��
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
			//ֱ��cur��=next
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



