#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int a[33], b[4] = { 0 }, n = 0, j = 0, k = 0;
	for (int i = 1; i <= 32; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 32; i >= 1; --i){
		b[j] = b[j] + a[i] * pow(2, k);
		n++;
		k++;
		while (n % 8 == 0){
			j++;
			break;
		}
		while (k % 8 == 0){
			k = 0;
			break;
		}
	}
	for (int j = 3; j >= 0; --j){
		if (j == 0){
			printf("%d", b[j]);
			break;
		}
		printf("%d .", b[j]);
	}
	system("pause");
	return 0;
}