//#include<iostream>
//#include<string>
//#include<vector>
//#include<stack>
//using namespace std;
//int main(){
//	int n;
//	cin >> n;
//	string str[n];
//	vector<int> v(n);
//	for (int i = 0; i < n; ++i){
//		cin >> str[i];
//	}
//	// «∑ÒŒ™◊÷µ‰–Ú≈≈¡–
//	int flag1 = 1;
//	int flag2 = 1;
//	for (int i = 0; i < n; ++i){
//		if (str[i]>str[i + 1]){
//			flag1 = 0;
//		}
//	}
//	for (int i = 0; i < n; ++i){
//		v[i] = str[i].size();
//	}
//	for (int i = 0; i < n; ++i){
//		if (v[i]>v[i + 1]){
//			flag2 = 0;
//		}
//	}
//	if (flag1 == 1 && flag2 != 1){
//		cout << "lexicographically" << endl;
//	}
//	else if (flag1 == 1 && flag2 == 1){
//		cout << "both" << endl;
//	}
//	else if (flag1 != 1 && flag2 == 1){
//		cout << "lengths" << endl;
//	}
//	else{
//		cout << "none" << endl;
//	}
//
//	system("pause");
//	return 0;
//	
//}
//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		stack<char> s;
//		for (auto e : A){
//			switch (e){
//			case '(':
//			{
//						s.push(e);
//						break;
//			}
//			case ')':
//			{
//
//						if (s.empty() || s.top() != '('){
//							return false;
//						}
//						else{
//							s.pop();
//						}
//						break;
//			}
//			default:
//				return false;
//			}
//		}
//		return true;
//	}
//};
//#include<iostream>
#include<stdio.h>
//#include<algorithm>
//using namespace std;
int main(){
	int a[1] = {1};
	printf("%d",a[2]);
	
	/*int n, f, f0 = 0, f1 = 1, l = 0, r = 0;
	cin >> n;
	while (1){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f<n){
			l = n - f;
		}
		else{
			r = f - n;
			break;
		}
	}
	cout << min(l, r) << endl;*/
	system("pause");
	return 0;
}