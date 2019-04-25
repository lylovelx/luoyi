//#include<stdio.h>
//#include<stdlib.h>
//typedef struct ListNode{
//	int val;
//	struct ListNode* next;
//}ListNode;
//ListNode* CreatNode(int val){
//	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
//	Node->val = val;
//	Node->next = NULL;
//	return Node;
//
//}
//void reorderList(struct ListNode* head) {
//
//	//要插入元素需要知道什么时候停止才行
//	if (!head || !head->next || !head->next->next) return head;
//	struct ListNode* cur = head;
//	int count = 0;
//	//计算节点个数
//	while (cur != NULL){
//		cur = cur->next;
//		count++;
//	}
//	//进行链表分割
//	if (count % 2 == 0){
//		int k = count / 2 - 1;
//		struct ListNode* p1 = head;
//		struct ListNode* p2 = head;
//		struct ListNode* p3 = head;
//		struct ListNode* pre = NULL;
//		struct ListNode* front = NULL;
//		for (int i = 0; i<k - 1; ++i){
//			p2 = p2->next;
//		}
//		//确定分割链表的位置
//		while (p2->next != NULL){
//			front = p1;
//			p1 = p1->next;
//			p2 = p2->next;
//		}
//		front->next = NULL;
//		//将分割后的链表逆置
//		while (p1 != NULL){
//			struct ListNode* next = p1->next;
//			p1->next = pre;
//			pre = p1;
//			p1 = next;
//		}
//		//链表插入
//		while (pre != NULL&&p3 != NULL){
//			struct ListNode* res1 = p3->next;
//			struct ListNode* res2 = pre->next;
//			p3->next = pre;
//			pre->next = res1;
//			p3 = res1;
//			pre = res2;
//		}
//
//	}
//	else{
//		int k = count / 2;
//		struct ListNode* p1 = head;
//		struct ListNode* p2 = head;
//		struct ListNode* p3 = head;
//		struct ListNode* pre = NULL;
//		struct ListNode* front = NULL;
//		for (int i = 0; i<k - 1; ++i){
//			p2 = p2->next;
//		}
//		//确定分割链表的位置
//		while (p2->next != NULL){
//			front = p1;
//			p1 = p1->next;
//			p2 = p2->next;
//		}
//		front->next = NULL;
//		//将分割后的链表逆置
//		while (p1 != NULL){
//			struct ListNode* next = p1->next;
//			p1->next = pre;
//			pre = p1;
//			p1 = next;
//		}
//		//链表插入
//		while (p3 != NULL&&pre != NULL){
//			struct ListNode* res1 = p3->next;
//			struct ListNode* res2 = pre->next;
//			p3->next = pre;
//			pre->next = res1;
//			p3 = res1;
//			pre = res2;
//		}
//	}
//	return head;
//}
//ListNode* List(){
//	ListNode* n1 = CreatNode(1);
//	ListNode* n2 = CreatNode(2);
//	ListNode* n3 = CreatNode(3);
//	ListNode* n4 = CreatNode(4);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = NULL;
//	return n1;
//}
//int main(){
//	ListNode* head = List();
//	reorderList(head);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main(){

	int a = (2 == 2);
	printf("%d",a);
	system("pause");
	return 0;

}