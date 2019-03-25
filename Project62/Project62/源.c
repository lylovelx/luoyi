//ɾ���ڵ�
ListNode* removeElements(ListNode* head, int val) {
	//����Ϊ�˱���ͷ�ڵ�����⣬������Ҫ����һ���µĽڵ�
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
	//�ƽ���head��Ҫֱ�Ӷ�
	//��һ���µĽ���������洢���õ�������
	ListNode* result = NULL;
	//����һ����������ĩβָ���ָ���Ա����´β���
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
//��ת����
ListNode* reverseList(ListNode* head) {
	if (head == NULL){
		return NULL;
	}
	//������
	ListNode* cur = head;
	ListNode* pre = NULL;
	while (cur != NULL){
		//����˼ά
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
//��ת����
ListNode* reverseList(ListNode* head) {
	//����ͷ��İ취
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
	//�ȴ�����ͨ���
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
	//�����µ�����
	ListNode* result = NULL;
	//��¼βָ��
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