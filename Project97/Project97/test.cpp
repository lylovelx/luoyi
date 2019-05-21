//#include<iostream>
//#include<vector>
//using namespace std;
//int main(){
//	vector<int> v;
//	v.resize(10);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	vector<int>::iterator it;
//	it = find(v.begin(), v.end(), 4);
//	
//	cout << *it << endl;
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
//int main(){
//	int n, count = 0;
//	cin >> n;
//	vector<long long> v(n);
//	for (int i = 0; i < n; ++i){
//		cin >> v[i];
//	}
//	for (int i = 1; i < n; ++i){
//		if (v[i - 1] <= v[i]){
//			while (i < n && v[i - 1] <= v[i]){
//				++i;
//			}
//			count++;
//		}
//		else{
//			while (i < n && v[i - 1] > v[i]){
//				++i;
//			}
//			count++;
//		}
//	}
//	if (n == 1){
//		cout << v[n - 1] << endl;
//	}
//	else{
//		cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}
//int main(){
//	string str("hello word");
//	cout << str << endl;
//	reverse(str.begin(),str.end());
//	cout << str << endl;
//	system("pause");
//	return 0;
//
//}
int main(){

	string str;
	while (getline(cin, str)){
		reverse(str.begin(), str.end());
		int cur = 0,left,right;
		for (int i = 0; i<str.size(); ++i){
			if (str[i] == ' '){
				left = cur;
				right = i - 1;
				while (left<right){
					swap(str[left], str[right]);
					left++;
					right--;
				}
				cur = i + 1;
			}
			else if (i==str.size()-1){
				left = cur;
				right = i;
				while (left<=right){
					swap(str[left], str[right]);
					left++;
					right--;
				}
			}

		}
		cout << str << endl;
	}
	//system("pause");
	return 0;
}