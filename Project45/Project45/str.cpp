//#include<string>
//#include<iostream>
//using namespace std;
//int main() {
//	string str;
//	while (cin >> str) {
//		string tmp;
//		for (int i = 0; i < str.size(); ++i) {
//			
//			if (str[i] != '_') {
//				tmp.push_back(str[i]);
//			}
//			else {
//				++i;
//				tmp.push_back(str[i] - 32);
//			}
//		}
//		cout << tmp << endl;
//	}
//	return 0;
//}
/////////////////////////////////////////////////////////////////
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//int main() {
//	string str;
//	while (getline(cin,str)) {
//		reverse(str.begin(), str.end());
//		string::iterator index=str.begin();
//		while (index<str.end()) {
//			string::iterator pos = index;
//			while ((pos != str.end())&&((*pos>='A'&&*pos<='Z')||(*pos>='a'&&*pos<='z'))) {
//				pos++;
//			}
//			reverse(index,pos);
//			if (pos == str.end()) break;
//			while ((*pos < 'A'||*pos > 'Z') && (*pos < 'a'||*pos > 'z')) {
//				str.erase(pos);
//			}
//			str.insert(pos,' ');
//			if (++pos!=str.end()) {
//				index = pos;
//			}
//			else {
//				break;
//			}
//		}
//		cout << str << endl;
//	}
//}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string A, B;
	char str_a[256] = { 0 };
	char str_b[256] = { 0 };
	while (cin >> A >> B) {
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (int i = 0; i < A.size(); ++i) {
			str_a[A[i]]++;
		}
		for (int i = 0; i < B.size(); ++i) {
			str_a[B[i]]++;
		}
		int i = 0, j = 0;
		while (i < A.size() && j < B.size()) {

		}
	}
}