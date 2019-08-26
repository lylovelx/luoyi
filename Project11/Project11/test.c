#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
const char* Strstr(const char* str1, const char* str2){
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(*str1 != 0);
	assert(*str2 != 0);
	char* black = str1;
	while (*black != 0){
		char* sub = str2;
		char* red = black;
		while (*str1 != 0 && *str2 != 0 && *red == *sub){
			++red;
			++sub;
		}
		if (*sub == 0){
			return black;
		}
		++black;
	}
	return NULL;


}
int main(){
	char* str1 = "abdsdffs";
	char* str2 = "sds";
	char* p = Strstr(str1, str2);
	printf("%p", p);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//实现strchr
char* Strchr(const char* str, int ch){
	assert(str != NULL);
	while (*str != 0){
		if (*str == ch){
			return str;
		}
		++str;
	}
	return NULL;
}

int main(){
	char* str = "abcdefg";
	char ch = getchar();
	char* p = Strchr(str, ch);
	printf("%p", p);
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//实现strcmp
int Strcmp(const char* str1, const char* str2){
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(*str1 != 0);
	assert(*str2 != 0);
	while (*str1 != 0 || *str2 != 0){
		if (*str1>*str2){
			return 1;
		}
		else if (*str1<*str2){
			return -1;
		}
		else{
			++str1;
			++str2;
		}
	}
	return 0;
}
int main(){
	char* str1 = "aaaabc";
	char* str2 = "aaaab";
	int cmp = Strcmp(str1, str2);
	if (cmp == 0){
		printf("str1==str2");
	}
	else if (cmp>0){
		printf("str1>str2");

	}
	else{
		printf("str1<str2");
	}
	system("pause");
	return 0;
}

#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//6.实现memcpy
char* Memcpy(void* dest, const void* src, unsigned int size){
	assert(dest != NULL);
	assert(src != NULL);
	char* str2 = (char*)src;
	char* str1 = (char*)dest;
	while (size&&*str2 != 0){
		*str1 = *str2;
		--size;
		++str1;
		++str2;

	}
	*str1 = 0;
	return str2;
}
int main(){
	char* str1 = "abcdefg";
	char str2[100];
	unsigned int size = 0;
	scanf("%d", &size);
	Memcpy(str2, str1, size);
	printf("%s", str2);
	system("pause");
	return 0;
}
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//memmove
char* Memmove(void* dest, const void* src, unsigned int size){
	assert(dest != NULL);
	assert(src != NULL);
	char* str2 = (char*)src;
	char* str1 = (char*)dest;
	if (str2<str1&&str1 < str2 + size){
		while (size&&*(str2 + size) != 0){
			*(str1 + size) = *(str2 + size);
			size--;
		}
		*(str1 + size) = 0;
		return str1;
	}
	else{
		while (size&&*str2 != 0){
			*str1 = *str2;
			--size;
			++str1;
			++str2;
		}
		*str1 = 0;
		return str2;
	}
}
int main(){
	char* str1 = "abcdefg";
	char str2[100];
	unsigned int size = 0;
	scanf("%d", &size);
	Memmove(str2, str1, size);
	printf("%s", str2);
	system("pause");
	return 0;
}