#include<iostream>
using namespace std;
class Solution {
public:
	int  NumberOf1(int n) {
		int i = 0, count = 0;
		while (n >> i) {
			if ((n >> i) & 1) {
				count++;
			}
			i++;
		}
		return count;
	}
};
int main() {
	Solution s;
	cout << s.NumberOf1(-1) << endl;
	system("pause");
}