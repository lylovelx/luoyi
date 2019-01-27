#include<stdio.h>
#include<stdlib.h>
int int_cmp(const void* p1, const void* p2){
	return(*((int*)p1) - *((int*)p2));
}
void Bubble(void* base, int count, int size, int(*cmp)(void*, void*)){
	for (int i = 0; i < count - 1; ++i){
		for (int j = i; j < count - 1 - i; ++j){
			if (cmp((char*)base + j*size, ((char*)base) + (j + 1)*size)>0){
				int temp = *((char*)base + j*size);
				*((char*)base + j*size) = *((((char*)base) + (j + 1)*size));
				*((((char*)base) + (j + 1)*size)) = temp;
			}
		}
	}
}
int main(){
	//int arr[] = { 1, 2, 6, 3, 7, 3, 5, 8, 9 };
	char* arr[] = { "aaaa", "bbbb", "cccc", "dddd" };
	Bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char*), int_cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
		printf("%s\n", arr[i]);
	}
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	char*  arr[] = {"aaaa","xxxx","vvvvv"};
//	printf("%d",sizeof(arr)/sizeof(arr[0]));
//	system("pause");
//	return 0;
//
//}
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int Strncmp(const char* a, const char* b, int size){
	assert(a != NULL);
	assert(a != NULL);
	int i = 0;
	int count = size;
	while ((*(a + i) != 0 || *(b + i) != 0) && count){
		if (*(a + i)>*(b + i)){
			return 1;
		}
		else if (*(a + i)<*(b + i)){
			return -1;

		}
		else{
			++i;
		}
		count--;
	}
	return 0;
}
int main(){
	int i = 0;
	int size = 2;
	char* str1 = "abaaa";
	char* str2 = "aaaaab";
	int h = Strncmp(str1, str2, size);
	if (h>0){
		printf("str1>str2");
	}
	else if (h<0){
		printf("str1<str2");
	}
	else{
		printf("str1==str2");
	}
	system("pause");
	return 0;
}
//1.模拟实现strncpy
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void strncpy(char*dest, const char* source, int size){
	assert(dest != NULL);
	assert(source != NULL);
	int i = 0;
	int count = size;
	while (*(source + i) != 0 && count){
		*(dest + i) = *(source + i);
		i++;
		count--;
	}
	*(dest + i) = 0;
}
int main(){
	char source[] = "asasaasasasasas";
	char* dest = (char*)malloc(sizeof(char)* 1024);
	strncpy(dest, source, 5);
	printf("%s", dest);
	system("pause");
	return 0;
}
//1.模拟实现strncpy
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void Strncat(char* dest, const char* source, int size){
	assert(dest != NULL);
	assert(source != NULL);
	int i = 0;
	int j = 0;
	int count = size;
	while (*(dest + i) != 0){
		i++;
	}
	while (*(source + j) != 0 && count){
		*(dest + i + j) = *(source + j);
		++j;
		--count;
	}
	*(dest + i + j) = 0;
}
int main(){
	int size = 4;
	char*  source = "abcdef";
	char  dest[100] = "aaaaaa";
	Strncat(dest, source, size);
	printf("%s", dest);
	system("pause");
	return 0;
}
