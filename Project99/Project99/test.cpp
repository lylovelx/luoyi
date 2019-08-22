#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
//#pragma pack(8)
//struct Tow{
//	char c;
//	double d;
//	int i;
//};
int main(){
	//int M, N;
	//cin >> M >> N;
	//string s;
	//string table = "0123456789ABCDEF";
	//while (M / N != 0){
	//	s += table[M%N];
	//	M /= N;
	//}
	//s += table[M%N];
	//reverse(s.begin(), s.end());
	//cout << s.c_str() << endl;
	//cout << sizeof(struct Tow) << endl;
	/*int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << (*p)[5] << endl;	*/
	
	
	/*string a("asasas");
	string b("hello");
	a.insert(1,b);
	cout << a << endl;*/

	system("pause");
	return 0;
}
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	string A;
	string B;
	cin >> A >> B;
	int count = 0;
	for (int i = 0; i<A.size(); ++i){
		A.insert(i, B);
		string tmp(A);
		reverse(A.begin(), A.end());
		if (A == tmp){
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n);
	for (int i = 0; i<n; ++i){
		cin >> v[i];
	}
	dp[0] = v[0];
	int Max = v[0];
	for (int i = 1; i<n; ++i){
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		if (Max<dp[i]){
			Max = dp[i];
		}
	}
	cout << Max << endl;
	system("pause");
	return 0;
}