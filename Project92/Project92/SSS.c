//
//int maxArea(int* height, int heightSize) {
//	int left = 0;
//	int right = heightSize - 1;
//	int maxlen = 0;
//	while (left <= right){
//		int min_height = fmin(height[left], height[right]);
//		int res = min_height*(right - left);
//		if (maxlen<res){
//			maxlen = res;
//
//		}
//		if (height[left]<height[right]){
//			left++;
//		}
//		else{
//			right--;
//		}
//
//	}
//	return maxlen;
//}
//class Solution {
//public:
//	void rotate(vector<vector<int>>& matrix) {
//		const int n = matrix.size();
//		//关于副对角线交换元素
//		for (int i = 0; i<n; ++i){
//			for (int j = 0; j<n - i; ++j){
//				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
//			}
//		}
//		//将新的举证上限反转
//		for (int i = 0; i<n / 2; ++i){
//			for (int j = 0; j<n; ++j){
//				swap(matrix[i][j], matrix[n - 1 - i][j]);
//			}
//		}
//	}
//};
#include<stdio.h>
#include<stdlib.h>
//int* plusOne(int* digits, int digitsSize, int* returnSize){
//	int n = digitsSize - 1;
//	int k = digitsSize;
//	if (digits[n] + 1>9){
//		while (digits[n] + 1>9 && n >= 0){
//			digits[n] = 10 - digits[n] - 1;
//			n--;
//		}
//		if (n >= 0){
//			digits[n] = digits[n] + 1;
//		}
//	}
//	else{
//		digits[n] = digits[n] + 1;
//	}
//	if (n<0){
//		int* array = (int*)malloc(sizeof(int)*(k + 1));
//		array[0] = 1;
//		for (int i = 1; i< k + 1; ++i){
//			array[i] = digits[i - 1];
//		}
//		/*printf("%d %d", array[0], array[1]);
//		system("pause");*/
//		*returnSize = k + 1;
//		return array;
//	}
//	*returnSize = k;
//	return digits;
//}
void SetZeroes(int** matrix, int matrixSize, int* matrixColSize){
	//先求出行数
	if (!matrix&&matrixSize == 0) return;
	int row = matrixSize / (*matrixColSize);
	int col = *matrixColSize;
	int res[100][100];
	//int** res=(int**)malloc(4*matrixSize);
	memset(res, 0, matrixSize * 4);
	for (int i = 0; i<row; ++i){
		for (int j = 0; j<col; ++j){
			if (matrix[i][j] == 0){
				res[i][j] = 1;
			}
		}
	}
	for (int i = 0; i<row; ++i){
		for (int j = 0; j<col; ++j){
			if (res[i][j] == 1){
				memset(matrix[i], 0, row * 4);
				int k = 0;
				while (k<row){
					matrix[k++][j] = 0;
				}
			}
		}
	}
}

int main(){
	/*int digits[] = { 9,7,9,9 };
	int n;
	int* arr = plusOne(digits, 4, &n);
	for (int i = 0; i < n; ++i){
	printf("%d", arr[i]);
	}*/
	int arr[3][3] = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
	int col = 3;
	SetZeroes(arr, 9, &col);
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}