//删除节点
ListNode* removeElements(ListNode* head, int val) {
	//首先为了避免头节点的问题，我们需要创建一个新的节点
	ListNode*  NewHead = (ListNode*)malloc(sizeof(ListNode));
	NewHead->next = head;
	ListNode* p1 = NewHead;
	ListNode* p2 = head;
	while (p2 != NULL){
		if (p2->val != val){
			p1 = p1->next;
			p2 = p2->next;
		}
		else{
			p1->next = p2->next;
			p2 = p2->next;
		}
	}
	return NewHead->next;
}
ListNode* removeElements(ListNode* head, int val) {
	//黄金法则：head不要直接动
	//用一个新的结果链表来存储所得到的链表
	ListNode* result = NULL;
	//创建一个用来保存末尾指针的指针以便于下次插入
	ListNode* last = NULL;
	ListNode* cur = head;
	while (cur != NULL){
		if (cur->val != val){
			if (result == NULL){
				result = cur;
				last = cur;
			}
			else{
				last->next = cur;
				last = cur;
			}
		}
		cur = cur->next;
	}
	if (last != NULL){
		last->next = NULL;
	}
	return result;
}
//反转链表
ListNode* reverseList(ListNode* head) {
	if (head == NULL){
		return NULL;
	}
	//迭代法
	ListNode* cur = head;
	ListNode* pre = NULL;
	while (cur != NULL){
		//反向思维
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
//反转链表
ListNode* reverseList(ListNode* head) {
	//采用头插的办法
	if (head == NULL){
		return head;
	}
	ListNode* result = NULL;
	ListNode* cur = head;
	while (cur != NULL){
		ListNode* node = cur->next;
		cur->next = result;
		result = cur;
		cur = node;
	}
	return result;
}
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//先处理普通情况
	ListNode* back = pListHead;
	ListNode* front = pListHead;
	for (int i = 0; i<k - 1; ++i){
		if (front == NULL){
			return NULL;
		}
		front = front->next;

	}
	while (front != NULL){
		front = front->next;
		if (front == NULL){
			break;
		}
		back = back->next;
	}
	return back;
}
////////////////////
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	//创建新的链表
	ListNode* result = NULL;
	//记录尾指针
	ListNode* last = NULL;
	ListNode* cur1 = l1;
	ListNode* cur2 = l2;
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}
	while (cur1 != NULL&&cur2 != NULL){
		if (cur1->val <= cur2->val){

			if (result == NULL){
				result = cur1;
				last = cur1;
			}
			else{
				last->next = cur1;
				last = cur1;
			}
			cur1 = cur1->next;

		}
		else{

			if (result = NULL){
				result = cur2;
				last = cur2;
			}
			else{
				last->next = cur2;
				last = cur2;
			}
			cur2 = cur2->next;
		}
	}
	if (cur1 != NULL){
		last->next = cur1;
	}
	if (cur2 != NULL){
		last->next = cur2;
	}
	return result;
}