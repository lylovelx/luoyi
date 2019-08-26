
//#include<iostream>
//#include<vector>
//using namespace std;
//int sum = 0;
//int GetYueShu(int a, int b) {
//	for (int i = a; i > 0; --i) {
//		if (a%i == 0 && b%i == 0) {
//			return i;
//		}
//	}
//	return 0;
//}
//int main() {
//	int a, n, sum;
//	while (cin >> n >> a) {
//		vector<int> v(n);
//		for (int i = 0; i < n; ++i) {
//			cin >> v[i];
//		}
//		sum = a;
//		for (int i = 0; i < v.size(); ++i) {
//			if (sum > v[i]) {
//				sum += v[i];
//			}
//			else {
//				sum += GetYueShu(sum, v[i]);
//			}
//		}
//		cout << sum << endl;
//		system("pause");
//	}
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		char str[256] = { 0 };
		for (int i = 0; i < s.size(); ++i) {
			str[s[i]]++;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (str[s[i]] == 1) {
				cout << s[i] << endl;
				break;
			}
		}

	}
	return 0;
}







