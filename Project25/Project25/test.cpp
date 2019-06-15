#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> s;
//		for (int i = 0; i < tokens.size(); ++i) {
//			string& str = tokens[i];
//			if (!(str == "-" || str == "+" || str == "/" || str == "*")) {
//				s.push(atoi(str.c_str()));
//			}
//			else {
//				int right = s.top();
//				s.pop();
//				int left = s.top();
//				s.pop();
//				switch (str[0]) {
//				case '+':
//					s.push(right + left);
//					break;
//				case '-':
//					s.push(left - right);
//					break;
//				case '/':
//					s.push(left / right);
//					break;
//				case '*':
//					s.push(left*right);
//					break;
//				}
//			}
//		}
//		return s.top();
//	}
//};

	int getValue(vector<int> gifts, int n) {
		//用记录的算法是实现
		int count = 0, i = 0;
		int tmp = gifts[0];
		while (i < n) {
			if (count == 0) {
				tmp = gifts[i];
				count = 1;
			}
			else if (tmp != gifts[i]) {
				count--;
			}
			else {
				count++;
			}
			i++;
		}
		if (count == 0) {
			return 0;
		}
		else {
			return tmp;
		}
	}
	int main() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n;++i) {
			cin >> v[i];
		}
		cout << getValue(v, n) << endl;
		system("pause");
		return 0;
	}