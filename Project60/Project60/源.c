#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

////��̬����
//typedef struct SepList{
//	int array[100];
//	int size;
//}SeqList;

//��̬����,����ֻ���Ƕ�̬���ݡ�
typedef struct SepList{
	int* array;
	int size;
	int capcity;
}SeqList;
//�˺���ֻ�����ڲ��������ԣ��������ⲿ��������
static void CheckCapcity(SeqList* ps){
	if (ps->size<ps->capcity){
		return;
	}
	int newcapcity = 2 * ps->capcity;
	int* newarray = (int*)malloc(sizeof(int)*newcapcity);
	assert(newarray != NULL);
	for (int i = 0; i < ps->size; ++i){
		newarray[i] = ps->array[i];
	}
	//�ͷ��Ͽռ� �����¿ռ�
	free(ps->array);
	ps->array = newarray;
	ps->capcity = newcapcity;

}
//˳���ĳ�ʼ��
void SeqListInit(SeqList* ps, int capcity){
	//ps�����Ǳ����ĵ�ַ
	assert(ps != NULL);
	ps->array = (int*)malloc(sizeof(int)*capcity);
	assert(ps->array != NULL);
	ps->size = 0;
	ps->capcity = capcity;

}
//˳��������
void SeqlistDestroy(SeqList* ps){
	assert(ps != NULL);
	assert(ps->array != NULL);
	//�ͷſռ�
	free(ps->array);
	//������
	ps->array = NULL;
	ps->capcity = 0;
	ps->size = 0;
}
//o(1)
//˳����β��
void SeqListPushBack(SeqList* ps, int v){
	CheckCapcity(ps);
	ps->array[ps->size] = v;
	ps->size++;
}
//o(n)
//˳����ͷ��
void SeqListPushFront(SeqList* ps, int v){
	CheckCapcity(ps);
	for (int i = ps->size - 1; i >= 0; --i){
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[0] = v;
	ps->size++;
}
//˳������pos�±��µĲ���
void SeqListInsert(SeqList* ps, int pos, int v){
	assert(pos >= 0 && pos <= ps->size);
	//�����������ְ취
	//1���ÿռ��±��ʾ�����±�
	//2�����������±��ʾ�ռ��±�
	for (int i = ps->size - 1; i >= pos; ++i){
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos] = v;
	ps->size++;
}
//βɾ
SeqListPopBack(SeqList* ps){
	assert(ps->size>0);
	ps->size--;
}
//ͷɾ
SeqListPopFront(SeqList* ps){
	assert(ps->size>0);
	for (int i = 1; i <= ps->size - 1; ++i){
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}
//����
int SeqListFind(SeqList* ps, int v){
	for (int i = 0; i < ps->size; ++i){
		if (ps->array[i] == v){
			return i;
		}
	}
	return -1;
}
//����
void SeqListErase(SeqList *ps, int pos) {
	// [0, size - 1]
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos + 1; i < ps->size; i++) {
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}
//�޸�
void SeqListModify(SeqList* ps, int v, int pos){
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = v;
}
//ɾ����һ������ v��
void SeqListRemove(SeqList* ps, int v){
	int pos = SeqListFind(ps, v);
	if (pos == -1){
		return;
	}
	SeqListErase(ps,pos);
}
//ɾ�����г��ֵ� v 
void SeqListRemoveAll(SeqList* ps, int v){
	int i, j;
	for (i = 0, j = 0; i < ps->size; ++i){
		if (ps->array[i] != v){
			ps->array[j] = ps->array[i];
			j++;
		}
	}
	ps->size = j;
}
//����
void SeqListTraverse(SeqList* ps){
	assert(ps!=NULL);
	for (int i = 0; i < ps->size;++i){
		printf("%d ",ps->array[i]);
	}
}
int main(){
	SeqList SeqList;
	SeqListInit(&SeqList, 100);
	//β��
	SeqListPushBack(&SeqList, 1);
	SeqListPushBack(&SeqList, 2);
	SeqListPushBack(&SeqList, 3);
	SeqListPushBack(&SeqList, 4);
	SeqListPushBack(&SeqList, 3);
    //ͷ��
	SeqListPushFront(&SeqList, 10);
	SeqListPushFront(&SeqList, 20);
	SeqListPushFront(&SeqList, 30);
	SeqListPushFront(&SeqList, 40);
	//ͷɾ
	SeqListPopBack(&SeqList);
	//βɾ
	SeqListPopFront(&SeqList);
	//���� 2
	printf("%d\n",SeqListFind(&SeqList,2));
	//ɾ�����г��� 3����
	SeqListRemoveAll(&SeqList,3);
	//����
	SeqListTraverse(&SeqList);
	system("pause ");
	return 0;
}