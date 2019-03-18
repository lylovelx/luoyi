#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//�����ṹ�壬Ϊ�˷����������������Ԫ��������������
typedef struct Node{
	int value;
	struct Node* next;
}Node;
//�ṹ���ʼ��,������һ��Ԫ�ض�û�У�������ͷָ��ָ�� NULL����
//��ΪҪ�޸�ͷָ���ֵ������Ҫ�ö���ָ�����
void SListInit(Node** ppFrist){
	*ppFrist = NULL;
}
//����һ���������Ҫ�����������нڵ���ڴ�ȫ���ͷţ�������Ҫ���������������Ӷ�λo(n)
void SListDestroy(Node* frist){
	//�п�
	Node* tmp;
	for (Node* cur = frist; cur != NULL; cur = tmp){
		//Ϊ��ɾ��ÿһ���ڵ����Ҫ����������
		tmp = cur->next;
		free(cur);
	}
}
//�����ͷ��
//��ΪҪ�޸�ͷָ�룬����Ҫ�õ�����ָ�룬o(1)
void SListPushFront(Node** ppFrist, int v){
	//��Ϊ�漰��Ԫ�صĲ��룬��������Ҫ��̬�����ڴ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = *ppFrist;
	*ppFrist = node;
}
//ɾ��ͷ�ڵ� o(1)
void SListPopFront(Node** ppFrist){
	//����ɾ��ͷ����ǰ����������Ϊ��,��
	assert(*ppFrist != NULL);
	Node* tmp = *ppFrist;
	*ppFrist = (*ppFrist)->next;
	free(tmp);
}
//β��
void SListPushBack(Node** ppFrist, int v){
	//���˵�����ǿ�������ô��Ȼ��Ҫ�ı�ͷָ���ֵ������Ҫ�ö���ָ��
	if (*ppFrist == NULL){
		Node* node = (Node*)malloc(sizeof(Node));
		node->value = v;

		*ppFrist = node;
		node->next = NULL;
		return;
	}


	Node* cur;
	for (cur = *ppFrist; cur->next != NULL; cur = cur->next){
	}
	Node* node = (Node*)malloc(sizeof(Node));
	cur->next = node;
	node->next = NULL;
}
//βɾ
void SListPopBack(Node** ppFrist){
	//��֤����Ϊ�գ���
	assert(*ppFrist != NULL);
	if ((*ppFrist)->next == NULL){
		free(*ppFrist);
		*ppFrist = NULL;
		return;
	}

	Node* cur;
	for (cur = *ppFrist; cur->next->next != NULL; cur = cur->next){
	}

	free(cur->next);
	cur->next = NULL;
}
Node* SListFind(const Node* frist, int v){
	//�������Ҫ����Ԫ�ؾ���Ҫ��֤����Ϊ��
	assert(frist != NULL);
	Node* cur;
	for (cur = frist; cur->next != NULL; cur = cur->next){
		if (cur->value == v){
			return cur;
		}
	}
	return NULL;
}
//�������ָ��λ�ò���Ԫ��
//��ָ��Ԫ�صĺ������
//pos�϶��������еĵ�
void SListInsertAfter(Node* pos, int v){

	Node* node = (Node*)malloc(sizeof(Node));
	node->next = pos->next;
	pos->next = node;
	node->value = v;
}
void SListEraseAfert(Node* pos){

	Node* next = pos->next;
	pos->next = pos->next->next;
	free(next);

}

int main(){
	Node* frist;
	SListInit(&frist);
}