//class Solution {
//public:
//	/**
//	 *  奇数位上都是奇数或者偶数位上都是偶数
//	 *  输入：数组arr，长度大于2
//	 *  len：arr的长度
//	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
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