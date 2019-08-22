#include<stdio.h>
#include<stdlib.h>
int main(){
	int count = 0;
	int a[] = { 1,2,1,2,3,4 };
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size; ++i){
		for (int j = i + 1; j < size; ++j){
			if ((a[i]) ^ (a[j]) == 0){
				break;
			}
			if (j = size - 1){
				printf("%d", a[i]);
			}
		}
	}
	system("pause");
	return 0;
}