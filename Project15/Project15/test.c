//ͨѶ¼

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct PersonInfo{
	char name[1024];
	char phone[1024];
	char company[1024];
	char address[1024];
}PersonInfo;
typedef struct AddressBook{
	PersonInfo person_infos[200];
	int  size;
}AddressBook;
AddressBook g_addr_book;
int Menu(){
	printf("===============\n");
	printf("1.������ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.�޸���ϵ��\n");
	printf("4.������ϵ��\n");
	printf("5.������ϵ��\n");
	printf("6.��ӡȫ��  \n");
	printf("7.���ȫ��  \n");
	printf("0.�˳�      \n");
	printf("===============\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
void Init(AddressBook*  addr_book){
	assert(addr_book != NULL);
	//addr_book->size = 0;
	//int Max = sizeof(addr_book->person_infos) / sizeof(addr_book->person_infos[0]);
	//for (int i = 0; i < Max;++i){
	//	memset(addr_book->person_infos[i].name, 0, 1024);
	//	memset(addr_book->person_infos[i].phone, 0, 1024);
	//	memset(addr_book->person_infos[i].company, 0, 1024);
	//	memset(addr_book->person_infos[i].address, 0, 1024);
	//}
	memset(addr_book, 0, sizeof(AddressBook));
}
void AddPersonInfo(AddressBook* addr_book){
	PersonInfo* p = &addr_book->person_infos[addr_book->size-1];
	printf("��������ϵ������:");
	scanf("%s", p->name);
	printf("��������ϵ�˵绰��");
	scanf("%s", p->phone);
	printf("��������ϵ�˹�˾��");
	scanf("%s", p->company);
	printf("��������ϵ�˹�˾��");
	scanf("%s", p->address);
	++addr_book->size;
	printf("�����ϵ�˳ɹ�!\n");
}
void DelPersonInfo(AddressBook* addr_book){
	assert(addr_book != NULL);
	printf("ѡ����Ҫɾ�������\n");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>addr_book->size-1){
		printf("����������,����������");
		return;
	}
	printf("��ȷ��Ҫɾ��[id]������x��ʾȷ��:");
	char a[1024] = {0};
	scanf("%s", a);
	if (strcmp(a,"x")!=0){
		printf("ɾ��ȡ��\n");
		return;
	}
	PersonInfo* from = &addr_book->person_infos[addr_book->size - 1];
	PersonInfo* to = &addr_book->person_infos[id];
	*to = *from;
	--addr_book->size;
	printf("ɾ���ɹ�\n");
}
void ModifyPersonInfo(AddressBook* addr_book){}
void FindPersonInfo(AddressBook* addr_book){}
void SortPersonInfo(AddressBook* addr_book){}
void PrintfPersonInfo(AddressBook* addr_book){
	assert(addr_book!=NULL);
	printf("ѡ����Ҫ��ӡ����ϵ�˵����\n");
	int id = 0;
	scanf("%d",&id);
	if(id<0||id>addr_book->size-1){
		printf("���������������������");
		return;
	}
	PersonInfo*  p = &addr_book->person_infos[id];
	printf("[%d] %s %s %s\n",p->name,p->phone,p->company,p->address);
}
void ClearAllPersonInfo(AddressBook* addr_book){}
int main(){
	typedef void(*pfunc_t)(AddressBook*);
	pfunc_t  func_table[] = {
		AddPersonInfo,
		DelPersonInfo,
		ModifyPersonInfo,
		FindPersonInfo,
		SortPersonInfo,
		PrintfPersonInfo,
		ClearAllPersonInfo
	};
	Init(&g_addr_book);
	while (1){
		int choice = Menu();
		if (choice<0 || choice>=sizeof(func_table) / sizeof(func_table[0])){
			printf("�������������������");
			continue;
		}
		if (choice == 0){
			printf("�ټ�");
		}
		func_table[choice - 1](&g_addr_book);
	}
	system("pause");
	return 0;
}

