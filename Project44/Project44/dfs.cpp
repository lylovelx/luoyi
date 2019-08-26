#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		char arr[] = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
//		set<string> s;
//		string tmp;
//		vector<string> str(n);
//		for (int i = 0; i < n; ++i) {
//			cin >> str[i];
//		}
//		for (int i = 0; i < n; ++i) {
//			int count = 0;
//			for (int j = 0; j < str[i].size(); ++j) {
//				if (count == 3) {
//					tmp.push_back('-');
//					count++;
//				}
//				if (str[i][j] >= '0'&&str[i][j] <= '9') {
//					tmp.push_back(str[i][j]);
//					count++;
//				}
//				if (str[i][j] >= 'A'&&str[i][j] <= 'Z') {
//					tmp.push_back(arr[str[i][j] - 'A']);
//					count++;
//				}
//				else {
//					continue;
//				}
//			}
//			s.insert(tmp);
//			tmp.clear();
//		}
//		for (auto& e : s) {
//			cout << e << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}
//int Sum(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n;++i) {
//		sum += i;
//	}
//	return sum;
//}
void Help(int n, int m, vector<int>& v, int begin) {
	if (m == 0) {
		for (int i = 0; i < v.size(); ++i) {
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}

}
int main() {

	int n, m;
	while (cin >> n >> m) {
		vector<int> v;
		Help(n, m, v, 1);
	}

}