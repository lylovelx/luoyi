//#include<iostream>
//#include<string>
//using namespace std;
//int main(){
//	string str;
//	cin >> str;
//	int count = 0;
//	int index;
//	for (int i = 0; i<str.size(); ++i){
//		int sum = 0;
//		int j = i;
//		while (j<str.size() && str[j] >= '0' && str[j] <= '9'){
//			sum++;
//			j++;
//		}
//		if (count<sum){
//			count = sum;
//			index = i;
//		}
//		i = j;
//	}
//	string src = str.substr(index, count);
//	cout << src << endl;
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<int> v(n);
		for (int i = 0; i<n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int sum = -1, max = 0;
		for (int i = 1; i<n; ++i){
			int count = 1;
			if (v[i] == v[i - 1]){
				while (i<n&&v[i] == v[i - 1]){
					i++;
					count++;
				}
				if (sum<count){
					sum = count;
					max = v[i - 1];
				}
			}
		}
		if (n == 1){
			cout << v[0] << endl;
		}
		cout << max << endl;
	}
	return 0;
}
