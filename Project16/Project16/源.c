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
	PersonInfo*  person_infos;//接受动态扩容的指针
	int capacity;//需要申请的容量
	int  size;//元素的有效个数
}AddressBook;
AddressBook g_addr_book;//声明全局变量
int Menu(){
	printf("===============\n");
	printf("1.增加联系人\n");
	printf("2.删除联系人\n");
	printf("3.修改联系人\n");
	printf("4.查找联系人\n");
	printf("5.排序联系人\n");
	printf("6.打印全部  \n");
	printf("7.清空全部  \n");
	printf("0.退出      \n");
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
	//memset(addr_book, 0, sizeof(AddressBook));
	addr_book->size = 0;
	addr_book->capacity = 10;
	addr_book->person_infos = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);

}//动态扩容函数的实现
void Realloc(AddressBook* addr_book){
	assert(addr_book!=NULL);
	addr_book->capacity *= 2;
	PersonInfo* old_infos = addr_book->person_infos;//为了防止原来的指针被覆盖，定义一个新的指针来存放旧的指针
	addr_book->person_infos = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	for (int i = 0; i < addr_book->size;++i){
		addr_book->person_infos[i] = old_infos[i];//将旧的空间中的元素依此赋值给新的空间当中
	}
	free(old_infos);//释放旧的指针
}
void AddPersonInfo(AddressBook* addr_book){
	assert(addr_book!=NULL);
	printf("新增联系人\n");
	if (addr_book->size>=addr_book->capacity){
		printf("联系人已经满了！进行扩容\n");
		Realloc(addr_book);
	}
	PersonInfo* p = &addr_book->person_infos[addr_book->size];
	printf("请输入联系人姓名:");
	scanf("%s", p->name);
	printf("请输入联系人电话：");
	scanf("%s", p->phone);
	printf("请输入联系人公司：");
	scanf("%s", p->company);
	printf("请输入联系人地址：");
	scanf("%s", p->address);
	++addr_book->size;
	printf("添加联系人成功!\n");
}
void DelPersonInfo(AddressBook* addr_book){
	assert(addr_book != NULL);
	printf("选择你要删除的序号\n");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>addr_book->size - 1){
		printf("您输入有误,请重新输入");
		return;
	}
	printf("你确定要删除[id]吗？输入x表示确定:");
	char a[1024] = { 0 };
	scanf("%s", a);
	if (strcmp(a, "x") != 0){
		printf("删除取消\n");
		return;
	}
	//如果要删除一个元素可以用最后一个元素将要删除的元素覆盖即可
	PersonInfo* from = &addr_book->person_infos[addr_book->size - 1];//最后元素的位置
	PersonInfo* to = &addr_book->person_infos[id];//当前需要删除的元素的位置
	*to = *from;//直接替换就可以
	--addr_book->size;
	printf("删除成功\n");
}
void ModifyPersonInfo(AddressBook* addr_book){
	assert(addr_book != NULL);
	//判断是否存在此联系人
	printf("选择你要修改的联系人序号: ");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>addr_book->size - 1){
		printf("您输入有误！请重新输入\n");
		return;
	}
	PersonInfo* p = &addr_book->person_infos[id];
	printf("选择你要修改的序号[%d],如果确定请输入x: ", id);
	char a[1024] = { 0 };
	scanf("%s", a);
	if (strcmp(a, "x") != 0){
		printf("修改取消!\n");
		return;
	}
	printf("输入你要修改的姓名(输入空字符串表示跳过): ");
	char  input[1024] = {0};
	scanf("%s",input);
	if (strcmp(input,"")!=0){
		strcpy(p->name,input);
	}
	printf("输入你要修改的电话(输入空字符串表示跳过): ");
	scanf("%s", input);
	if (strcmp(input, "") != 0){
		strcpy(p->phone, input);
	}
	printf("输入你要修改的公司(输入空字符串表示跳过): ");

	scanf("%s", input);
	if (strcmp(input, "") != 0){
		strcpy(p->company, input);
	}
	printf("输入你要修改的地址(输入空字符串表示跳过): ");
	scanf("%s", input);
	if (strcmp(input, "") != 0){
		strcpy(p->address, input);
	}
	printf("修改成功\n");
}
void FindPersonInfo(AddressBook* addr_book){
	assert(addr_book != NULL);
	printf("请输入你要查找的序号：");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>addr_book->size - 1){
	printf("您输入的有误！请重新输入");
	return;
	}
	PersonInfo* p = &addr_book->person_infos[id];
	printf("%s %s %s %s\n",p->name,p->phone,p->company,p->address);
}

void SortPersonInfo(AddressBook* addr_book){
	assert(addr_book != NULL);
	//将联系人的名字由排序
	//冒泡排序法
	//那么如果不按名字排序那么我们应该怎么做了呢？
	//所以我们可以利用回调函数的特定条件功能对函数进行快捷的修改。
	for (int i = 0; i < addr_book->size - 1; ++i){
		for (int j = i; j < addr_book->size - 1 - i; ++j){
			if (addr_book->person_infos[i].name>addr_book->person_infos[i + 1].name){
				PersonInfo temp;
				temp = addr_book->person_infos[i];
				addr_book->person_infos[i] = addr_book->person_infos[i + 1];
				addr_book->person_infos[i + 1] = temp;
			}
		}
	}
	printf("排序成功\n");
}
void PrintfPersonInfo(AddressBook* addr_book){
	assert(addr_book != NULL);
	PersonInfo*  p = addr_book->person_infos;
	for (int i = 0; i < addr_book->size;++i){
		printf("%s %s %s %s\n", p[i].name, p[i].phone, p[i].company, p[i].address);
	}
}
void ClearAllPersonInfo(AddressBook* addr_book){
	assert(addr_book!=NULL);
	printf("你将清空联系人(输入x表示确定):");
	char str[1024] = {0};
	scanf("%s",str);
	if (strcmp(str,"x")==0){
		addr_book->size = 0;
	}
	
}
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
		if (choice<0 || choice > sizeof(func_table) / sizeof(func_table[0])){
			printf("您输入错误！请重新输入");
			continue;
		}
		if (choice == 0){
			printf("再见");
		}
		func_table[choice - 1](&g_addr_book);
	}
	system("pause");
	return 0;
}
#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	return a / b;
}
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //转移表
	while (input)
	{
		printf("*************************\n");
		printf(" 1:add           2:sub \n");
		printf(" 3:mul           4:div \n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1))
		{
			printf("输入操作数：");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
			printf("输入有误\n");
		printf("ret = %d\n", ret);
	}
	return 0;
}
