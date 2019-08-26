//#include<iostream>
//#include<string>
//using namespace std;
//int main() {
//	string src, des;
//	while (getline(cin, src)) {
//
//		getline(cin, des);
//		//刚开始的下标位置
//		size_t index = 0, cnt = 0, pos;
//		while ((pos = src.find(des.c_str(), index)) != string::npos) {
//			index = pos + des.size();
//			cnt++;
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int GetNum(int day) {
	if (day == 1) return 1;
	if (day == 2) return 1;
	int first = 1, second = 1, third;
	for (int i = 3; i <= day; ++i) {
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}
int main() {
	int from, to;
	while (cin >> from >> to) {
		int sum = 0;
		for (int i = from; i <= to; ++i) {
			sum += GetNum(i);
		}
		cout << sum << endl;
	}
}