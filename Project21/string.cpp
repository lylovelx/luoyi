//¶þÎ¬¾ØÕó
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int Short = s1.size();
		int Length = s2.size();
		if (Short > Length) {
			s1.swap(s2);
			swap(Short, Length);
		}
		int array[s1.size()][s2.size()];
		int max = 0;
		int maxlen = 0;
		for (int i = 0; i < s1.size(); ++i) {
			for (int j = 0; j < s2.size(); ++j) {
				if (s1[i] == s2[j]) {
					if (i == 0 || j == 0) {
						array[i][j] = 1;
					}
					else {
						array[i][j] = array[i - 1][j - 1] + 1;
					}
				}
				else {
					array[i][j] = 0;
				}
				if (array[i][j] > max) {
					max = array[i][j];
					maxlen = i;
				}
			}
		}
		string str = s1.substr(maxlen - max + 1, max);
		cout << str << endl;
	}
	return 0;
}