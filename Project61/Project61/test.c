#include<stdio.h>
#include<stdlib.h>
//��Ҫ�ڹ��̵ľ���ʵ��
int Min(int a, int b){
	return a > b ? b : a;
}
int MinMoneyNumble(int* arr, int i, int rest, int length){
	//�ݹ���ֹ����
	if (length == i){
		return rest == 0 ? 0 : -1;
	}
	//��ʼΪ -1
	int res = -1;

	for (int k = 0; k*arr[i] <= rest; ++k){
		//��ʣ�µ�Ǯ�����ݹ鴦��
		int next = MinMoneyNumble(arr, i + 1, rest - k*arr[i], length);
		if (next != -1){
			//ÿ������ݹ��е����Ž�
			res = res == -1 ? next + k : Min(res, k + next);
		}
	}
	return res;
}

int main(){
	//�õݹ���ֽ��������������
	int arr[] = { 1, 2, 3, 4, 5, 3, 6, 8, 23, 45, 2 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("%d", MinMoneyNumble(arr, 0, 40,length));
	system("pause");
	return 0;

}