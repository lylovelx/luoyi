//////#include<iostream>
//////using namespace std;
//////int main() {
//////	int month;
//////	while (cin >> month) {
//////		int dp[month] = { 0 };
//////		dp[0] = 1;
//////		dp[1] = 1;
//////		for (int i = 3; i <= month; ++i) {
//////			dp[i] = dp[i - 1] + dp[i - 2];
//////		}
//////		cout << dp[month] << endl;
//////	}
//////	return 0;
//////}
//
//#include <iostream>
//#include <string>
//using namespace std;
//bool match(const char* pattern, const char *str)
//{
//	// ��ǰ�ַ����������� true
//	if (*pattern == '\0' && *str == '\0')
//		return true;
//	// �����ַ�����һ���Ƚ������򷵻� false
//	if (*pattern == '\0' || *str == '\0')
//		return false;
//	if (*pattern == '?')
//	{
//		// ���� ? �ţ�ƥ��һ���ַ�������һ��λ��
//		return match(pattern + 1, str + 1);
//	}
//	else if (*pattern == '*')
//	{
//		// ���� * �ţ�ƥ�� 0 �� (str ��Ų�� ) �� 1 �������߶���ǰŲ��һ���ַ������� (str ��ǰŲ��һ���ַ� )
//		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
//	}
//	else if (*pattern == *str)
//	{
//		// �����ǰ�ַ���ȣ�ƥ����һ���ַ�
//		return match(pattern + 1, str + 1);
//	}
//	return false;
//}
//int main()
//{
//	string pattern, str;
//	while (cin >> pattern >> str)
//	{
//		bool ret = match(pattern.c_str(), str.c_str());
//		if (ret)
//			cout << "true" << endl;
//		else
//	}
//	cout << "false" << endl;
//	return 0;
//}
////�ݹ���
//#include<iostream>
//using namespace std;
//int GetNum(int n) {
//	if (n == 2) {
//		return 1;
//	}
//	else if (n > 2) {
//		return 1 + GetNum(n - 2);
//	}
//	else {
//		return 0;
//	}
//}
//int main() {
//	int n;
//	while (cin >> n) {
//		int res = GetNum(n);
//		cout << res << endl;
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		if (n > 3) {
			while (n > 3) {
				n -= 3;
				if (n>0) {
					n += 1;
				}
				count++;
				if (n/3==0&&n%3==2) {
					count++;
				}
			}
			cout << count << endl;
		}
		else {
			if (n == 0 || n == 1) {
				cout << count << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
	}
	return 0;
}










