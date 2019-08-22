#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//创建结构体，为了方便起见，我用整形元素描述数据类型
typedef struct Node{
	int value;
	struct Node* next;
}Node;
//结构体初始化,链表中一个元素都没有，所以让头指针指向 NULL即可
//因为要修改头指针的值，所以要用二级指针接收
void SListInit(Node** ppFrist){
	*ppFrist = NULL;
}
//销毁一个链表就需要将链表中所有节点的内存全部释放，所以需要遍历整个链表，复杂度位o(n)
void SListDestroy(Node* frist){
	//判空
	Node* tmp;
	for (Node* cur = frist; cur != NULL; cur = tmp){
		//为了删除每一个节点必须要引入额外变量
		tmp = cur->next;
		free(cur);
	}
}
//链表的头插
//因为要修改头指针，所以要用到二级指针，o(1)
void SListPushFront(Node** ppFrist, int v){
	//因为涉及到元素的插入，所以我们要动态申请内存
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = *ppFrist;
	*ppFrist = node;
}
//删除头节点 o(1)
void SListPopFront(Node** ppFrist){
	//首先删除头结点的前提是链表不能为空,故
	assert(*ppFrist != NULL);
	Node* tmp = *ppFrist;
	*ppFrist = (*ppFrist)->next;
	free(tmp);
}
//尾插
void SListPushBack(Node** ppFrist, int v){
	//如果说链表是空链表，那么仍然需要改变头指针的值，所以要用二级指针
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
//尾删
void SListPopBack(Node** ppFrist){
	//保证链表不为空，故
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
	//首先如果要查找元素就需要保证链表不为空
	assert(frist != NULL);
	Node* cur;
	for (cur = frist; cur->next != NULL; cur = cur->next){
		if (cur->value == v){
			return cur;
		}
	}
	return NULL;
}
//在链表的指定位置插入元素
//在指定元素的后面插入
//pos肯定是链表中的点
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