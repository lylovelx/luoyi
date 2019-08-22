////#include<iostream>
////#include<vector>
////#include<string>
////#include<stack>
////
////using namespace std;
////int main() {
////	int a, b, n;
////	while (cin >> n) {
////		if (n == 0) continue;
////		vector<string> s(n);
////		stack<int> st;
////		for (int i = 0; i < n; ++i) {
////			cin >> s[i];
////		}
////		for (int i = 0; i < n; ++i) {
////			if (s[i][0] >= '0' && s[i][0] <= '9') {
////				st.push(atoi(s[i].c_str()));
////			}
////			else {
////
////				a = st.top();
////				st.pop();
////				b = st.top();
////				st.pop();
////				switch (s[i][0]) {
////				case '+': st.push(a + b); break;
////				case '-': st.push(a - b); break;
////				case '/':
////					if (b == 0) {
////						return 0;
////					}
////					else {
////						st.push(a / b);
////					}
////				case '*': st.push(a*b); break;
////				}
////			}
////		}
////		cout << st.top() << endl;
////	}
////	return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		//数组初始化
//		vector<long long> dp(n+1);
//		dp[1] = 0;
//		dp[2] = 1;
//		for (int i = 3; i <= n; ++i) {
//			dp[i] = (i - 1)*(dp[i - 2] + dp[i - 1]);
//		}
//		printf("%lld\n", dp[n]);
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		vector<int> v(n);
//		for (int i = 0; i < n; ++i) {
//			cin >> v[i];
//		}
//		vector<int> dp(n, 1);
//		int Max = 1;
//		for (int j = 1; j < n; ++j) {
//			for (int k = 0; k < j; ++k) {
//				if (v[k] < v[j]) {
//					dp[j] = max(dp[j], dp[k] + 1);
//				}
//			}
//			Max = max(Max, dp[j]);
//		}
//		cout << Max << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		//利用插入排序的思想
		for (int i = 1; i < array.size(); ++i) {
			int temp = array[i];
			int j;
			for (j = i - 1; j >= 0 && array[i] % 2 != 0 && array[j] % 2 == 0) {
				array[j + 1] = array[j];
			}
			array[j + 1] = array[i];
		}
	}
};

int main() {
	Solution s;
	vector<int> v = { 1,2,31,13,45223,565,6 };
	s.reOrderArray(v);
	for (auto e : v) {
		cout << e << " ";
	}
	return 0;
}