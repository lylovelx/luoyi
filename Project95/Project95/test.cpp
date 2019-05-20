#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
//string DeleteString(string& str1, string& str2) {
//	if (str1.c_str() == NULL) return NULL;
//	if (str2.c_str() == NULL) return str1;
//	string str;
//	int HashTable[256] = { 0 };
//	for (int i = 0; i < str1.size(); ++i){
//		HashTable[str1[i]]++;
//	}
//	
//	for (int i = 0; i < str1.size(); ++i){
//		if (HashTable[str1[i]==0]){
//			str += str1[i];
//		}
//	}
//	return str;
//}
//int main(){
//
//	string str1, str2;
//	cin >> str1;
//	cin >> str2;
//	cout << DeleteString(str1, str2) << endl;
//	return 0;
//
//}
template <class T>
void Swap(T& a,T& b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int a = 10;
	int b = 2;
	Swap(1,2);

}