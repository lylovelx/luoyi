//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main() {
//	int T;
//	cin >> T;
//	while (T) {
//		int n, k;
//		cin >> n >> k;
//		vector<int> v(2 * n);
//
//		//将牌输入到vector中
//		for (int i = 0; i < 2 * n; ++i) {
//			cin >> v[i];
//		}
//		//洗牌的次数
//		for (int j = 0; j < k; ++j) {
//			vector<int> vleft(n), vright(n);
//			for (int left = 0; left < n; ++left) {
//				vleft[left] = v[left];
//			}
//			for (int right = 0; right < n; ++right) {
//				vright[right] = v[right + n];
//			}
//			v.clear();
//			while (v.size() < 2 * n) {
//				v.push_back(vright[vright.size() - 1]);
//				vright.pop_back();
//				v.push_back(vleft[vleft.size() - 1]);
//				vleft.pop_back();
//			}
//			reverse(v.begin(), v.end());
//		}
//		for (int i = 0; i < 2 * n; ++i) {
//			if (i == 2 * n - 1) {
//				cout << v[i] << endl;
//			}
//			else {
//				cout << v[i] << " ";
//			}
//		}
//		T--;
//	}
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	int num;
	string s;
	while (cin >> num >> s) {
		vector<int> v(num);
		//初始化窗口区间
		int i = 0, j = 0;
		int x = 0, y = 0;
		for (int n = 0; n < num; ++n) {
			v[n] = n + 1;
		}
		while (i < s.size()) {
			if (s[i] == 'U'&&j == 0) {
				i++;
				j = j + num - 1;
				y = num - 1;
				x = num - 4;
			}
			else if (s[i] == 'D'&&j == num - 1) {
				i++;
				j = 0;
				x = 0;
				y = 3;
			}
			else {
				if (s[i] == 'U') {
					j--;
				}
				else {
					j++;
				}

				if (s[i] == 'D'&&j >= x && j <= y) {
					i++;
				}
				else if (s[i] == 'D'&&j > y) {
					i++;
					x += 1;
					y += 1;
				}
				else if (s[i] == 'U'&&j >= x && j <= y) {
					i++;
				}
				else if (s[i] == 'U'&&j < x) {
					i++;
					x -= 1;
					y -= 1;
				}
			}
		}
		for (int index = x; x <= y; ++index) {
			if (index == y) {
				cout << v[index] << endl;
				break;
			}
			cout << v[index] << " ";
		}
		cout << v[j] << endl;
	}
	return 0;
}