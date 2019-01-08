#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void sort(int a[], int size){
	int num = 0;
	int num1 = 0;
	int num2 = 0;
	int flag = 0;
	for (int i = 0; i < size; ++i){
		num = num^a[i];
	}
	for (int i = 0; i < 32; i++){
		if (((num >> i) & 1) != 1){
			flag++;
		}
		else{
			break;
		}
	}
	for (int i = 0; i < size; i++){
		if ((((a[i]) >> flag) & 1) == 1){
			num1 ^= a[i];
		}
		else{

			num2 ^= a[i];
		}
	}
	printf("%d %d", num1, num2);
}

int change(int pop, int number){
	int num1 = number / pop;
	int num2 = num1 / 2;
	return num1 + num2;
}
char* strcpy(char b[], const char a[]){
	assert(a != NULL);
	assert(b != NULL);
	int i = 0;
	while (*(a + i) != 0){
		*(b + i) = *(a + i);
		i++;
	}
	*(b + i) = 0;
	return b;
}
char* strcat(char* a, const char* b){
	assert(a != NULL);
	assert(b != NULL);
	int i = 0;
	int j = 0;
	while (*(a + i) != 0){
		i++;
	}
	while (*(b + j) != 0){
		*(a + i + j) = *(b + j);
		j++;
	}
	*(a + i + j) = 0;
	return a;
}
int main(){
	int a[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6 };
	int size = sizeof(a) / sizeof(a[0]);
	sort(a, size);
	int pop = 1;
	int number = 0;

	scanf("%d", &number);
	printf("%d", change(pop, number));
	char a[] = "asdfg";
	char b[100];
	strcpy(b, a);
	printf("%s", b);
	char a[100] = "aaa";
	char b[100] = "aaab";
	strcat(a, b);
	printf("%s", a);
	system("pause");
	return 0;
}