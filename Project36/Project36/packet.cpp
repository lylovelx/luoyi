//class Solution {
//public:
//	/**
//	 *	正数数组中的最小不可组成和
//	 *	输入：正数数组arr
//	 *	返回：正数数组中的最小不可组成和
//	 */
//	int getFirstUnFormedNum(vector<int> arr, int len) {
//		//求出区间上的最大值和最小值
//		int min = arr[0], max = 0;
//		for (int i = 0; i < len; ++i)
//		{
//			min = min > arr[i] ? arr[i] : min;
//			max += arr[i];
//		}
//		vector<int> dp(max + 1, 0);
//		for (int i = 0; i < len; ++i)
//		{
//			for (int j = max; j >= arr[i]; j--)
//			{
//				if (dp[j] < dp[j - arr[i]] + arr[i])
//					dp[j] = dp[j - arr[i]] + arr[i];
//				else
//					dp[j] = dp[j];
//			}
//		}
//		for (int k = min; k <= max; ++k)
//		{
//			if (k != dp[k])
//				return k;
//		}
//		return max + 1;
//	}
//};
//#include<string>
//#include<iostream>
//using namespace std;
//int main() {
//	string str;
//	while (getline(cin, str)) {
//		if (str.size() < 6) {
//			continue;
//		}
//		string tmp;
//		for (int j = 0; j < 5; ++j) {
//			tmp.push_back(str[j]);
//		}
//		int i;
//		for (i = 5; i < str.size(); ++i) {
//			str[i - 5] = str[i];
//		}
//		for (int k = i - 5, i = 0; k < str.size() && i < 5; ++k, ++i) {
//			str[k] = tmp[i];
//		}
//		cout << str << endl;
//	}
//
//}
#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int cnt=1;
		while (n != 1) {
			int i;
			for (i = 2; i <= sqrt(n); ++i) {
				if (n%i == 0) {
					cout << i << " ";
					cnt++;
					break;
				}
			}
			n = n / i;
		}
		cout << endl;
	}

}