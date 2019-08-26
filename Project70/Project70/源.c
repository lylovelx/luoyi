#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode;

void Init(ListNode** ppFirst){
	*ppFirst = NULL;
}

void SlistNode(ListNode** ppFirst, int v){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = v;
	node->next = *ppFirst;
	*ppFirst = node;
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
ListNode* partition(ListNode* pHead, int x) {
	if (pHead == NULL){
		return NULL;
	}
	ListNode* small = NULL;
	ListNode* smallast = NULL;
	ListNode* big = NULL;
	ListNode* biglast = NULL;
	ListNode* cur = pHead;
	while (cur != NULL){
		if (cur->val<x){
			ListNode* next = cur->next;
			cur->next = NULL;
			if (small == NULL){
				small = cur;
				smallast = cur;
			}
			else{
				smallast->next = cur;
				smallast = cur;
			}
			cur = next;
		}
		else{
			break;
		}

	}
	while (cur != NULL){
		if (cur->val >= x){
			ListNode* next = cur->next;
			cur->next = NULL;
			if (big == NULL){
				big = cur;
				biglast = cur;
			}
			else{
				biglast->next = cur;
				biglast = cur;
			}
			cur = next;
		}
		else{
			break;
		}
	}
	if (small == NULL){
		return big;
	}
	if (big == NULL){
		return small;
	}
	smallast->next = big;
	return small;
}
ListNode* deleteDuplication(ListNode* pHead)
{
	//创建虚拟节点
	ListNode*  task = (ListNode*)malloc(sizeof(ListNode));
	if (pHead == NULL){
		return NULL;
	}
	task->next = pHead;
	ListNode* pre = task;
	ListNode* p1 = pHead;
	ListNode* p2 = pHead->next;
	while (p2 != NULL){
		if (p1->val != p2->val){

			pre = pre->next;
			p1 = p1->next;
			p2 = p2->next;

		}
		else{
			while (p1->val == p2->val){
				p2 = p2->next;
				if (p2->next == NULL){
					break;
				}
			}
			pre->next = p2;
			p1 = p2;
			p2 = p2->next;
		}
	}
	return task->next;
}
bool chkPalindrome(ListNode* A) {
	//先求出链表得长度
	if (A == NULL){
		return false;
	}
	int len = 0;
	for (ListNode* cur = A; cur != NULL; cur = cur->next){
		len++;
	}
	ListNode* middle = A;
	for (int i = 0; i<len / 2; ++i){
		middle = middle->next;
	}
	ListNode* pre = NULL;
	while (middle != NULL){
		ListNode* next = middle->next;
		middle->next = pre;
		pre = middle;
		middle = next;
	}
	while (A != NULL&&pre != NULL){
		if (A->val != pre->val){
			return false;
		}
		A = A->next;
		pre = pre->next;
	}
	return true;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	//求出它们得长度差
	int lenA = 0;
	int lenB = 0;
	ListNode* A = headA;
	ListNode* B = headB;
	ListNode* longer = headA;
	ListNode* Short = headB;
	for (A = headA; A != NULL; A = A->next){
		lenA++;
	}
	for (B = headB; B != NULL; B = B->next){
		lenB++;
	}
	int diff = lenA - lenB;
	if (lenB>lenA){
		longer = headB;
		Short = headA;
		diff = lenB - lenA;
	}
	for (int i = 0; i<diff; ++i){
		longer = longer->next;
	}
	while (Short != longer){
		Short = Short->next;
		longer = longer->next;
	}
	return longer;
}
bool hasCycle(ListNode *head) {
	if (head == NULL){
		return false;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	do{
		fast = fast->next;
		if (fast == NULL){ return false; }
		fast = fast->next;
		if (fast == NULL){ return false; }
		slow = slow->next;
	} while (fast != slow);
	return true;
}
int main(){
	ListNode* first;
	Init(&first);
	SlistNode(&first, 4);
	SlistNode(&first, 3);
	SlistNode(&first, 3);
	SlistNode(&first, 3);
	SlistNode(&first, 2);
	SlistNode(&first, 1);
	//SlistNode(&first, 2);
	//SlistNode(&first, 1);
	/*ListNode* two;
	Init(&two);
	SlistNode(&two, 4);
	SlistNode(&two, 3);
	SlistNode(&two, 1);
	ListNode* p = mergeTwoLists(first, two);*/
	//ListNode* p = FindKthToTail(first, 6);
	ListNode* p = deleteDuplication(first);

	return 0;
}