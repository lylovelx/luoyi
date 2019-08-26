//#include<iostream>
//#include<string>
//#include<set>
//#include<algorithm>
//using namespace std;
//int main() {
//	int N;
//	while (cin >> N) {
//		set<string> pool;
//		int maxNum = 0;
//		for (int i = 0; i < N; ++i) {
//			string id, con;
//			cin >> id >> con;
//			if (con == "connect") {
//				pool.insert(id);
//			}
//			else {
//				pool.erase(id);
//			}
//			int size = pool.size();
//			maxNum = max(maxNum, size);
//		}
//		cout << maxNum << endl;
//	}
//
//}











#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main() {
	int N;
	while (cin >> N) {
		set<string> s;
		vector<string> v(N);
		for (int i = 0; i < N; ++i) {
			string str;
			cin >> str;
			s.insert(str);
		}
		int j = 0;
		for (auto& e : s) {
			v[j++] = e;
		}
		for (int i = 0; i < N - 1;++i) {
			if ((v[i+1].size()>v[i].size()) && (v[i]==v[i+1].substr(0,v[i].size())) && (v[i + 1][v[i].size()] == '/')){
				continue;
			}
			else {
				cout << "mkdir -p " << v[i] << endl;
			}
		}
		cout << "mkdir -p " << v[N - 1] << endl << endl;
	}
	return 0;
}