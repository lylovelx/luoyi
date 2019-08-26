#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

//class Solution {
//public:
//	string ReverseSentence(string str) {
//		//整体反转再逐个单词反转
//		if (str.empty()) return str;
//		reverse(str.begin(), str.end());
//		int i = 0, j = 0;
//		while (j < str.size()) {
//			while (j < str.size() && str[j] != ' ') {
//				j++;
//			}
//			reverse(str.begin() + i, str.begin() + j);
//			i = j + 1;
//			j = j + 1;
//		}
//		return str;
//	}
//};
//class Solution {
//public:
//	
//	bool IsContinuous(vector<int> numbers) {
//		if (numbers.empty()) return false;
//		sort(numbers.begin(), numbers.end());
//		map<int, int> m;
//		for (auto& e : numbers) {
//			m[e]++;
//		}
//		int i = 0;
//		while (i < numbers.size() - 1) {
//			if (numbers[i] == 0) {
//				i++;
//				continue;
//			}
//			if ((numbers[i + 1] - numbers[i]) == 1) {
//				i++;
//				continue;
//			}
//			if ((numbers[i + 1] - numbers[i]) == 0) {
//				return false;
//			}
//			if ((numbers[i + 1] - numbers[i]) > 1) {
//				if (m[0] > 0) {
//					numbers.insert(numbers.begin() + i + 1, numbers[i] + 1);
//					m[0]--;
//				}
//				else {
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//};

//class Solution {
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		vector<int> v;
//		if (n == 0) return n;
//		for (int i = 0; i < n; ++i) {
//			v.push_back(i);
//		}
//		int i = 0;
//		while (v.size() != 1) {
//			int res = m;
//			while (res - 1) {
//				i++;
//				res--;
//				if (i == v.size()) {
//					i = 0;
//				}
//			}
//			v.erase(v.begin() + i);
//			if (i == v.size()) {
//				i = 0;
//			}
//		}
//		return v[0];
//	}
//};


class Solution {
public:
	int StrToInt(string str) {
		if (str.empty()) return 0;
		int sum = 0;
		int flag = 1;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '-' && i == 0) {
				flag = -1;
				continue;
			}
			if (str[i] == '+' && i == 0) {
				continue;
			}
			if (str[i] >= '0' && str[i] <= '9') {
				sum += (str[i] - '0')*pow(10, str.size() - i - 1);
			}
			else {
				return 0;
			}
		}
		return flag * sum;
	}
};


int main() {
	
	Solution s;
	cout << s.StrToInt("+2345");
	system("pause");
}