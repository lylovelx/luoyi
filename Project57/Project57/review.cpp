//#include<iostream>
//#include<vector>
//#include<string>
//#include<stack>
//
//using namespace std;
//int main() {
//	int a, b, n;
//	while (cin >> n) {
//		if (n == 0) continue;
//		vector<string> s(n);
//		stack<int> st;
//		for (int i = 0; i < n; ++i) {
//			cin >> s[i];
//		}
//		for (int i = 0; i < n; ++i) {
//			if (s[i][0] >= '0' && s[i][0] <= '9') {
//				st.push(atoi(s[i].c_str()));
//			}
//			else {
//
//				a = st.top();
//				st.pop();
//				b = st.top();
//				st.pop();
//				switch (s[i][0]) {
//				case '+': st.push(a + b); break;
//				case '-': st.push(a - b); break;
//				case '/':
//					if (b == 0) {
//						return 0;
//					}
//					else {
//						st.push(a / b);
//					}
//				case '*': st.push(a*b); break;
//				}
//			}
//		}
//		cout << st.top() << endl;
//	}
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		//数组初始化
		vector<long long> dp(n+1);
		dp[1] = 0;
		dp[2] = 1;
		for (int i = 3; i <= n; ++i) {
			dp[i] = (i - 1)*(dp[i - 2] + dp[i - 1]);
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}