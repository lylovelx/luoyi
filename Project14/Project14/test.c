#include<stdio.h>
#include<stdlib.h>
int main(){
	int i=1;
	int arr[5] = {10,2,3,4,5};
	int min = arr[0];
	while (i<5){
		if (min>arr[i]){
			min = arr[i];
		}
		i++;
	}
	for (int i = 0; i < 5;++i){
		if (min==arr[i]){
			switch (i){
			case 1:
				printf("¶«");
			}
		}
	}
	printf("%d",min);
	system("pause");
	return 0;
}