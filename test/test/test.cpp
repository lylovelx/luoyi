//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>> vv(n);
//	for (int i = 0; i < n; ++i) {
//		vv[i].resize(2*i + 1, 0);
//	}
//	for (int i = 0; i < n; ++i) {
//		vv[i][0] = 1;
//		vv[i][vv[i].size()-1] = 1;
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < vv[i].size(); ++j) {
//			if (i==1&&j==1&&vv[i][j]==0) {
//				vv[i][j] = 1;
//			}else if (vv[i][j] == 0 && j == 1) {
//				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//			}
//			else if (vv[i][j] == 0 && j == vv[i].size() - 2) {
//				vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1];
//			}
//			else if (vv[i][j] == 0) {
//				vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
//			}
//
//		}
//	}
//	for (int i = 0; i < n;++i) {
//		for (int j = 0; j < vv[i].size();++j) {
//			cout << vv[i][j];
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < vv[n - 1].size(); ++i) {
//		if (vv[n - 1][i] % 2 == 0) {
//			cout << i+1 << endl;
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string str1, str2;
	cin >> str1>>str2;
	int Length = str1.size();
	int Short = str2.size();
	if (Length < Short) {
		str1.swap(str2);
		swap(Length, Short);
	}
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int flag = 0, res;
	for (int i = 0; i < Length; ++i) {
		res = i;
		if (i == str2.size())  break;
		if (str1[i] - '0' + str2[i] - '0' + flag > 9) {
			str1[i] = (str1[i] - '0' + str2[i] - '0' + flag) % 10 + '0';
			flag = 1;
		}
		else {
			str1[i] = str1[i] - '0' + str2[i] - '0' + flag + '0';
			flag = 0;
		}
	}
	while (flag == 1 && str1[res] != 0) {
		if (str1[res] - '0' + flag > 9) {
			str1[res] = (str1[res] - '0' + flag) % 10 + '0';
			flag = 1;
		}
		else {
			str1[res] = str1[res] - '0' + flag + '0';
			flag = 0;
		}
		res++;
	}
	if (flag == 1 && str1[res] == 0) {
		str1.push_back('1');
	}
	reverse(str1.begin(), str1.end());
	cout << str1 << endl;
	system("pause");
	return 0;
}
