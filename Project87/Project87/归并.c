//#include<stdio.h>
//#include<stdlib.h>
//void Merg(int arr[], int tmp[], int left, int mid, int right){
//	//int* tmp = (int*)malloc(sizeof(int)*(right - left + 1));
//	int i = left;
//	int j = mid + 1;
//	int k = left;
//	while (i <= mid&&j <= right){
//		if (arr[i]>arr[j]){
//			tmp[k++] = arr[j++];
//		}
//		else{
//			tmp[k++] = arr[i++];
//		}
//	}
//	while (i <= mid){
//		tmp[k++] = arr[i++];
//	}
//	while (j <= right){
//		tmp[k++] = arr[j++];
//	}
//	for (int x = left; x <= right; ++x){
//		arr[x] = tmp[x];
//	}
//	//free(tmp);
//}
////void MergSort(int arr[], int left, int right){
////	if (left >= right){
////		return;
////	}
////	int mid = (left + right) / 2;
////	mergsort(arr, left, mid);
////	mergsort(arr, mid + 1, right);
////	merg(arr, left, mid, right);
////}
////int main(){
////	int arr[] = { 1, 2, 31, 2, 56, 230, 87, 3, 0, 2, 2 ,4,5,2,2323,2};
////	int size = sizeof(arr) / sizeof(int);
////	MergSort(arr, 0, size - 1);
////	for (int i = 0; i < size; ++i){
////		printf("%d ", arr[i]);
////	}
////	system("pause");
////	return 0;
////}
//#include<stdio.h>
//#include<stdlib.h>
//void MergSort(int arr[], int size){
//	int* extra = (int*)malloc(sizeof(int)*(size+1));
//	//这里的 i 表示的是有序数组的长度
//	for (int i = 1; i <= size; i = i * 2){
//		//这里的j表示两个有序数组中的左边界
//		for (int j = 0; j <= size; j = j + 2 * i){
//			//left 表示两个有序数组中的左边界
//			int left = j;
//			//我们假设两个有序数组中第一个有序数组的左边下标———mid是排好序的区间
//			int mid = j + i-1;
//			//根据上一个注释可以说明，如果mid大于数组长度则 这个区间已经排好序
//			if (mid>size){
//				continue;
//			}
//			//两个有序数组中第二个有序数组中最右边的下标
//			int right = mid + i;
//			if (right>size){
//				//这里为什么要判断呢？
//				//可以想象如果要排序的数组个数并非相等，那么最后排序数组元素就会变少，所以就要让最右边的元素和数组最大元素下标相等
//				//保证正常合并排序
//				right = size;
//			}
//			Merg(arr, extra, left, mid, right);
//		}
//	}
//	free(extra);
//}
//int main(){
//	int arr[] = { 1, 2, 31, 2, 56, 230, 87, 3, 0, 2, 2, 4, 5, 2, 2323, 2 };
//	int size = sizeof(arr) / sizeof(int);
//	MergSort(arr, size-1);
//	for (int i = 0; i < size; ++i){
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//二分查找

#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int arr[], int left, int right, int v){
	while (left<=right){
		int mid = (left + right) / 2;
		if (v<arr[mid]){
			right = mid - 1;
		}
		if (v>arr[mid]){
			left = mid + 1;
		}
		if (v = arr[mid]){
			return mid;
		}
	}
	return -1;
}
int main(){
	int arr[] = { 1, 2, 4, 6, 7, 8, 9, 12, 23, 34, 45, 666 };
	int size = sizeof(arr) / sizeof(int);
	int a = BinarySearch(arr, 0, size - 1, 6);
	printf("%d", a);
	system("pause");
	return 0;
}