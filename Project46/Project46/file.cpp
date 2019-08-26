//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		//利用标记算法实现
//		if (!numbers.size()) return 0;
//		int i = 1;
//		int count = 1;
//		int res = numbers[0];
//		while (i < numbers.size()) {
//
//			if (res != numbers[i]) {
//				count--;
//			}
//			else {
//				count++;
//			}
//			if (count == 0) {
//				res = numbers[i];
//				count = 1;
//			}
//			i++;
//		}
//		int cnt = 0;
//		for (int i = 0; i < numbers.size(); ++i) {
//			if (numbers[i] == res) {
//				cnt++;
//			}
//		}
//		return cnt > numbers.size() / 2 ? res : 0;
//	}
//};
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
string GetFileName(string& path) {
	int pos = path.rfind('\\');
	string file_name = path.substr(pos + 1);
	if (file_name.size() > 16) {
		string file_name = path.substr(file_name.size() - 16);
	}
	return file_name;
}
struct Record {
	string _file;
	int _line;
	int cnt;
	Record(string file, int line) :_file(file), _line(line), cnt(1) {}
	bool operator==(const Record& a) {
		return (a._file == _file) && (a._line == _line);
	}
};

int main() {
	int line;
	string file;
	vector<Record> vr;
	cin >> file >> line; //{
		Record re(GetFileName(file), line);
		auto res = find(vr.begin(), vr.end(), re);
		if (res == vr.end()) {
			vr.push_back(re);
		}
		else {
			res->cnt++;
		}
	//}
	for (auto& e : vr) {
		cout << e._file << " " << e._line << " " << e.cnt << endl;
	}
	return 0;
}