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
//	//����� i ��ʾ������������ĳ���
//	for (int i = 1; i <= size; i = i * 2){
//		//�����j��ʾ�������������е���߽�
//		for (int j = 0; j <= size; j = j + 2 * i){
//			//left ��ʾ�������������е���߽�
//			int left = j;
//			//���Ǽ����������������е�һ���������������±ꡪ����mid���ź��������
//			int mid = j + i-1;
//			//������һ��ע�Ϳ���˵�������mid�������鳤���� ��������Ѿ��ź���
//			if (mid>size){
//				continue;
//			}
//			//�������������еڶ����������������ұߵ��±�
//			int right = mid + i;
//			if (right>size){
//				//����ΪʲôҪ�ж��أ�
//				//�����������Ҫ������������������ȣ���ô�����������Ԫ�ؾͻ���٣����Ծ�Ҫ�����ұߵ�Ԫ�غ��������Ԫ���±����
//				//��֤�����ϲ�����
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
//���ֲ���

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