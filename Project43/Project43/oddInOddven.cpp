//class Solution {
//public:
//	/**
//	 *  ����λ�϶�����������ż��λ�϶���ż��
//	 *  ���룺����arr�����ȴ���2
//	 *  len��arr�ĳ���
//	 *  ��arr����������λ�϶�����������ż��λ�϶���ż��
//	 */
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		long i = 0, j = 1;
//		while (i < len&&j < len) {
//			if (arr[i] % 2 == 0) {
//				i += 2;
//				continue;
//			}
//			if (arr[j] % 2 != 0) {
//				j += 2;
//				continue;
//			}
//			swap(arr[i], arr[j]);
//		}
//		return;
//	}
//};
//
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		cout << (long long)pow(5, n) - 4 << " " << (long long)pow(4, n) + n - 4 << endl;
	}
	system("pause");
	return 0;
}