//#include<iostream>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		int count = 0;
//		for (int i = 0; i < 32; ++i) {
//			if ((n >> i) % 2 != 0) {
//				count++;
//			}
//		}
//		cout << count << endl;
//		system("pause");
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		int count = 0;
//		while (n) {
//			if ((n & 1) == 1) {
//				count++;
//			}
//			n >>= 1;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main() {
//	const int a = 10;
//	int* p = (int*)&a;
//	*p = 20;
//	cout << a << *p << endl;
//	system("pause");
//	return 0;
//
//
//}
#include<iostream>
#include<string>
using namespace std;
#define Prints1 {cout << s1 << endl;}
#define Prints2 {cout << s2 << endl;}
int Count(const string& s) {
	int n = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			n++;
		}
	}
	return ++n;
}
int main() {
	string s;
	string s1, s2;
	getline(cin, s);
	//分割字符串
	s1 = s.substr(0, s.find('-'));
	s2 = s.substr(s.find('-') + 1);
	//记录不同字符串扑克牌的数量
	int n1 = Count(s1);
	int n2 = Count(s2);

	string POKER = "345678910JQKA2";
	string MAX = "joker JOKER";
	if (s1 == MAX) {
		Prints1;
	}
	else if (s2 == MAX) {
		Prints2;
	}
	else if (n1==1&&n2==1) {
		if ((s1 == "joker")&&(s2 == "JOKER")) {
			Prints2;
		}
		else if ((s1 == "JOKER")&&(s2 == "joker")) {
			Prints1;
		}
	
	}else if (n1 == n2) {
		string f1, f2;
		f1 = s1.substr(0, s1.find(' '));
		f2 = s2.substr(0, s2.find(' '));
		if (POKER.find(f1) > POKER.find(f2)) {
			Prints1;
		}
		else {
			Prints2;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
	system("pause");
	return 0;
}