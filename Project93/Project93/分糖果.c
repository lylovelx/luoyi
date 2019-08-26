#include<stdio.h>
#include<stdlib.h>
//class Solution {
//public:
//	void setZeroes(vector<vector<int>>& matrix) {
//		const int m = matrix.size();
//		const int n = matrix[0].size();
//		vector<bool> row(m, false);
//		vector<bool> col(n, false);
//		for (int i = 0; i<m; ++i){
//			for (int j = 0; j<n; ++j){
//				if (matrix[i][j] == 0){
//					row[i] = col[j] = true;
//				}
//			}
//		}
//		for (int i = 0; i<m; ++i){
//			if (row[i]){
//				fill(&matrix[i][0], &matrix[i][0] + n, 0);
//			}
//		}
//		for (int j = 0; j<n; ++j){
//			if (col[j]){
//				for (int i = 0; i<m; ++i){
//					matrix[i][j] = 0;
//				}
//			}
//		}
//	}
//};


//int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
//	const int m = gasSize;
//	const int n = costSize;
//	int ret = -1;
//	for (int i = 0; i<m; ++i){
//		//首先将所有加油站全部实验一下
//		int gas_plus = 0;
//		int count = 0;
//		for (int j = i; j<n; ++j){
//			gas_plus = gas_plus + gas[j] - cost[j];
//			if (gas_plus<0){
//				break;
//			}
//			count++;
//			if (count / m != 0){
//				return i;
//			}
//			if (j == n - 1){
//				j = -1;
//			}
//		}
//	}
//	return ret;
//}
//int main(){
//	int a[] = { 5, 1, 2, 3, 4 };
//	int b[] = { 4, 4, 1, 5, 1 };
//	int h = canCompleteCircuit(a, 5, b, 5);
//	printf("%d ", h);
//	system("pause");
//	return 0;
//}
//class Solution {
//public:
//	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//		int total = 0;
//		int j = -1;
//		for (int i = 0, sum = 0; i<gas.size(); ++i){
//			sum += gas[i] - cost[i];
//			total += gas[i] - cost[i];
//			if (sum<0){
//				j = i;
//				sum = 0;
//			}
//		}
//		return total >= 0 ? j + 1 : -1;
//	}
//};
int candy(int* ratings, int size) {
	//先求有多少孩子
	int num = size;
	//糖果的初始化
	int count = 1, i = 1, sum = 1;
	while (i<num){

		while (i == 1){
			if (ratings[1]<ratings[0]){
				count = 2;
				sum = 2;
			}
			break;
		}

		if (ratings[i]>ratings[i - 1]){
			count++;
			sum += count;
		}
		else if (ratings[i] == ratings[i - 1]){
			sum += count;
		}
		else{
			//因为题目要求的是至少需要多少糖果，所以
			count = 1;
			sum += count;
		}

		i++;

	}
	return sum;
}
int main(){
	int arr[] = { 1, 3, 2, 2, 1 };
	int g = candy(arr, 5);
	printf("%d", g);
	system("pause");
	return 0;
}