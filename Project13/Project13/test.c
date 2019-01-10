#include<stdio.h>
#include<stdlib.h>
void sort(int arr[], int size){
	for (int i = 0; i <size - 1; i++){
		for (int j = 0; j < size - 1 - i; j++){
			if (arr[j]<arr[j + 1]){
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}

	}
}
int main(){
	int arr[] = { 5, 8, 9, 9, 6, 5, 2, 5, 5, 5, 8, 8, 8, 5, 5, 5, 555, 54, 4, 2222 };
	//求出数组的长度
	int size = sizeof(arr) / sizeof(arr[0]);
	sort(arr, size);
	//对交换后的数组进行遍历
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
