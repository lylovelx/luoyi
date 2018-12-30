#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[10][10] = { 0 };
	for (int i = 0; i < 10; ++i){
		a[i][0] = 1;
		a[i][9] = 1;
	}
	for (int i = 2; i < 10; ++i){
		for (int j = 1; j < i; ++j){
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
		for (int i = 0; i < 10; ++i){
			for (int j = 0; j < 10; ++j){
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}