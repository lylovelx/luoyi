#include<stdio.h>
#include<stdlib.h>
//不要在过程的具体实现
int Min(int a, int b){
	return a > b ? b : a;
}
int MinMoneyNumble(int* arr, int i, int rest, int length){
	//递归终止条件
	if (length == i){
		return rest == 0 ? 0 : -1;
	}
	//初始为 -1
	int res = -1;

	for (int k = 0; k*arr[i] <= rest; ++k){
		//将剩下的钱交给递归处理
		int next = MinMoneyNumble(arr, i + 1, rest - k*arr[i], length);
		if (next != -1){
			//每次求出递归中的最优解
			res = res == -1 ? next + k : Min(res, k + next);
		}
	}
	return res;
}

int main(){
	//用递归解决纸币数量最少问题
	int arr[] = { 1, 2, 3, 4, 5, 3, 6, 8, 23, 45, 2 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("%d", MinMoneyNumble(arr, 0, 40,length));
	system("pause");
	return 0;

}