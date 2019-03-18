#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

////静态扩容
//typedef struct SepList{
//	int array[100];
//	int size;
//}SeqList;

//动态扩容,我们只考虑动态扩容。
typedef struct SepList{
	int* array;
	int size;
	int capcity;
}SeqList;
//此函数只存在内部链接属性，不存在外部链接属性
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
	//释放老空间 ，绑定新空间
	free(ps->array);
	ps->array = newarray;
	ps->capcity = newcapcity;

}
//顺序表的初始化
void SeqListInit(SeqList* ps, int capcity){
	//ps期望是变量的地址
	assert(ps != NULL);
	ps->array = (int*)malloc(sizeof(int)*capcity);
	assert(ps->array != NULL);
	ps->size = 0;
	ps->capcity = capcity;

}
//顺序表的销毁
void SeqlistDestroy(SeqList* ps){
	assert(ps != NULL);
	assert(ps->array != NULL);
	//释放空间
	free(ps->array);
	//锦上添花
	ps->array = NULL;
	ps->capcity = 0;
	ps->size = 0;
}
//o(1)
//顺序表的尾插
void SeqListPushBack(SeqList* ps, int v){
	CheckCapcity(ps);
	ps->array[ps->size] = v;
	ps->size++;
}
//o(n)
//顺序表的头插
void SeqListPushFront(SeqList* ps, int v){
	CheckCapcity(ps);
	for (int i = ps->size - 1; i >= 0; --i){
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[0] = v;
	ps->size++;
}
//顺序表的在pos下表下的插入
void SeqListInsert(SeqList* ps, int pos, int v){
	assert(pos >= 0 && pos <= ps->size);
	//在这里有两种办法
	//1，用空间下表表示数据下表
	//2，或用数据下表表示空间下表
	for (int i = ps->size - 1; i >= pos; ++i){
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos] = v;
	ps->size++;
}
//尾删
SeqListPopBack(SeqList* ps){
	assert(ps->size>0);
	ps->size--;
}
//头删
SeqListPopFront(SeqList* ps){
	assert(ps->size>0);
	for (int i = 1; i <= ps->size - 1; ++i){
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}
//查找
int SeqListFind(SeqList* ps, int v){
	for (int i = 0; i < ps->size; ++i){
		if (ps->array[i] == v){
			return i;
		}
	}
	return -1;
}
//更新
void SeqListErase(SeqList *ps, int pos) {
	// [0, size - 1]
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos + 1; i < ps->size; i++) {
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}
//修改
void SeqListModify(SeqList* ps, int v, int pos){
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = v;
}
//删除第一个遇到 v的
void SeqListRemove(SeqList* ps, int v){
	int pos = SeqListFind(ps, v);
	if (pos == -1){
		return;
	}
	SeqListErase(ps,pos);
}
//删除所有出现的 v 
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
//遍历
void SeqListTraverse(SeqList* ps){
	assert(ps!=NULL);
	for (int i = 0; i < ps->size;++i){
		printf("%d ",ps->array[i]);
	}
}
int main(){
	SeqList SeqList;
	SeqListInit(&SeqList, 100);
	//尾插
	SeqListPushBack(&SeqList, 1);
	SeqListPushBack(&SeqList, 2);
	SeqListPushBack(&SeqList, 3);
	SeqListPushBack(&SeqList, 4);
	SeqListPushBack(&SeqList, 3);
    //头插
	SeqListPushFront(&SeqList, 10);
	SeqListPushFront(&SeqList, 20);
	SeqListPushFront(&SeqList, 30);
	SeqListPushFront(&SeqList, 40);
	//头删
	SeqListPopBack(&SeqList);
	//尾删
	SeqListPopFront(&SeqList);
	//查找 2
	printf("%d\n",SeqListFind(&SeqList,2));
	//删除所有出现 3的数
	SeqListRemoveAll(&SeqList,3);
	//遍历
	SeqListTraverse(&SeqList);
	system("pause ");
	return 0;
}