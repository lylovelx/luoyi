#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int val;
	struct Node *next;
	struct Node *random;
}	Node;

Node * CreateNode(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = node->random = NULL;
	return node;
}

void Print(Node *head) {
	for (Node *cur = head; cur != NULL; cur = cur->next) {
		printf("0x%p(%d, random: 0x%p)  -->  ", cur, cur->val, cur->random);
	}
	printf("NULL\n");
}

Node * copyRandomList(Node *head) {
	if (head == NULL) {
		return NULL;
	}

	// �����½�㣬���뵽�ɽ��ĺ��
	Node *cur = head;
	while (cur != NULL) {
		Node * newNode = (Node *)malloc(sizeof(Node));
		newNode->val = cur->val;
		newNode->random = NULL;

		// ���½����뵽 cur �ɽ����
		newNode->next = cur->next;
		cur->next = newNode;

		cur = newNode->next;	// cur ����һ���ɽ��
	}

	// ���ݾɽ���random�������½���random
	cur = head;
	while (cur != NULL) {
		if (cur->random != NULL) {
			cur->next->random = cur->random->next;
		}

		cur = cur->next->next;
	}

	// ��������ɵĺ��µ�
	cur = head;
	Node *newHead = head->next;
	while (cur != NULL) {
		Node *newNode = cur->next;
		cur->next = newNode->next;
		if (newNode->next != NULL) {
			newNode->next = newNode->next->next;
		}

		cur = cur->next;
	}

	// ����������ĵ�һ�����
	return newHead;
}

void Test() {
	Node *n1 = CreateNode(1);
	Node *n2 = CreateNode(2);
	Node *n3 = CreateNode(3);
	Node *n4 = CreateNode(4);

	n1->next = n2; n2->next = n3; n3->next = n4;
	n1->random = n3; n2->random = n1; n3->random = n3;

	Print(n1);
	Node * rn1 = copyRandomList(n1);
	Print(rn1);
}