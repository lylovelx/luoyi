#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int first,int mid,int last){
	int length = last - first + 1;
	int* temp = (int*)malloc(sizeof(int)*length);
	int i = first;
	int j = mid + 1;
	int k = 0;
	int *p = (int*)malloc(sizeof(int)*length);
	while (i<=mid&&j<=last){
		if (arr[i]<arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while (i<=mid){
		temp[k++] = arr[i++];
	}
	while (j<=last){
		temp[k++] = arr[j++];
	}
	for (int i = 0; i < k;++i){
		arr[first + i] = temp[i];
	
	}
	free(temp);

}

void mergeSort(int arr[],int first,int last){
	
	if (first<last){
		int mid = (first + last) / 2;
		mergeSort(arr,first,mid);
		mergeSort(arr,mid+1,last);
		merge(arr, first, mid,last);
	}

}
int main(){
	int arr[] = {1,3,6,7,8,94,32,12};
	int length = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr,0,length );
	system("pause");
	return 0;

}



