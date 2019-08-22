#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode;

void Init(ListNode** ppFirst){
	*ppFirst = NULL;
}
void SList(ListNode** ppFirst ,int v){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = *ppFirst;
	*ppFirst = node;
}
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
int main() {
	ListNode* first;
	Init(&first);
	Slist(&first,4);
	Slist(&first, 2);
	Slist(&first, 1);
	ListNode* two;
	Init(&two);
	Slist(&two, 4);
	Slist(&two, 3);
	Slist(&two, 1);
	ListNode* p = mergeTwoLists(&first,&two);

}