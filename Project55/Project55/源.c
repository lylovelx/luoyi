#include<stdio.h>
#include<stdlib.h>
最大子数组
int find_max_string(int* a,int low,int high){

	int length = high - low + 1,temp=-10000;
	for (int i = 0; i < length;++i){
		int sum = a[i];
		for (int j = i;j<length;++j){
			sum = sum + a[j];
			if (temp<sum){
				temp = sum;
			}
		}
	}
	return temp;
}

int find_max_crossing_string(int* a, int low, int mid, int high){

	int temp1 = -10000, temp2 = -10000;
	int sum = 0;
	for (int i = mid; i >= low; --i){
		sum += a[i];
		if (sum>temp1){
			temp1 = sum;
		}
	}
	sum = 0;
	for (int i = mid + 1; i < high; ++i){
		sum += a[i];
		if (sum>temp2){
			temp2 = sum;
		}
	}
	return (temp1 + temp2);
}

int find_max_string(int* a, int low, int high){

	if (low == high){
		return a[low];
	}
	int mid = (low + high) / 2;
	int max_left = find_max_string(a, low, mid);
	int max_right = find_max_string(a, mid+1, high);
	int cross = find_max_crossing_string(a, low, mid, high);
	if (max_left >= max_right&&max_left >= cross){
		return max_left;
	}
	else if (max_right >= max_left&&max_right >= cross){
		return max_right;
	}
	else{
		return cross;
	}
}
int get_max(int a,int b){

	return a > b ? a : b;

}

int main(){
	暴力法
	int a[] = { 1,2,3};
	int length = sizeof(a) / sizeof(a[0]);
	int sumsubring = -10000;
	int low;//记录位置
	int high;//记录位置
	for (int i = 0; i < length;++i){
		for (int j = i; j < length;++j){
			int sum = 0;
			for (int k = i; k <= j;++k){
				sum += a[k];
			}
			if (sum>sumsubring){
				sumsubring = sum;
				low = i;
				high = j;
			}
		}
	}
	printf("%d %d %d",low,high,sumsubring);

	//分治法
	/*int a[] = { 1,-2,3,4,-4};
	int length = sizeof(a) / sizeof(a[0]);
	int low = 0;
	int high = length;
	printf("%d", find_max_string(a, low, high));*/

	//动态规划求解
	int a[] = {8,2,3,4,5,-3};
	int length = sizeof(a) / sizeof(a[0]);
	int sum = a[0];
	int max = a[0];
	for (int i = 1; i < length; ++i){
		sum = get_max(sum+a[i],a[i]);
		if (sum>=max){
			max = sum;
		}
	}

	printf("%d",max);
	system("pause");
	return 0;
}