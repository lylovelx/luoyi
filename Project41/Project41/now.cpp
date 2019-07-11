//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		getchar();
//		vector<string> str(n);
//		for (int i = 0; i < n; ++i) {
//			getline(cin,str[i]);
//			str.push_back(str[i]);
//		}
//		for (int j = 0; j < n; ++j) {
//			if ((str[j].find(',') != string::npos) || (str[j].find(' ') != string::npos)) {
//				str[j].insert(str[j].begin(), '"');
//				str[j].insert(str[j].end(), '"');
//			}
//		}
//		for (int k = 0; k < n; ++k) {
//			if (k != n - 1) {
//				cout << str[k] << ", ";
//			}
//			else {
//				cout << str[k] << endl;
//			}
//		}
//	}
//	return 0;
//}
#include<iostream>
#include<cmath>
using namespace std;

int GetNum(int day) {
	return pow(2, day - 1);
}
int main() {
	int n;
	while (cin >> n) {
		cout << GetNum(n) << endl;;
	}
	return 0;
}