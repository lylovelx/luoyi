//class Solution {
//public:
//	int Add(int num1, int num2)
//	{
//		while (num2 != 0) {
//			int sum = num1 ^ num2;
//			int carray = (num1&num2) << 1;
//			num1 = sum;
//			num2 = carray;
//		}
//		return num1;
//
//	}
//};
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	//用string接收数据
	while (cin >> str) {
		//遍历所有i字符
		if (str.size() == 1) {
			cout << str[0] - '0' << endl;
		}
		else {
			while (str.size() != 1) {
				char buf[100];
				int sum = 0;
				for (int i = 0; i < str.size(); ++i) {
					sum += str[i] - '0';
				}
				string temp = _itoa(sum, buf, 10);
				str = temp;
			}
			cout << atoi(str.c_str()) << endl;
		}
	}
}