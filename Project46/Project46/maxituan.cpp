//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//struct player {
//	int w;
//	int h;
//};
//bool com_w(player p1, player p2) {
//	if (p1.w != p2.w) {
//		return p1.w <= p2.w;
//	}
//	else {	
//		return p1.h > p2.h;
//	}
//}
//
//
//int main() {
//	int N;
//	int h;
//	int w;
//	int index;
//	vector<player> vp;
//	while (cin >> N) {
//		vp.clear();
//		for (int i = 0; i < N; ++i) {
//			player pt;
//			cin >> index >> w >> h;
//			pt.w = w;
//			pt.h = h;
//			vp.push_back(pt);
//		}
//		sort(vp.begin(), vp.end(), com_w);
//
//		int dp2[N];
//		int max = 0;
//		dp2[0] = 1;
//		for (int i = 1; i < N; ++i) {
//			dp2[i] = 1;
//			for (int j = 0; j < i; ++j) {
//				if (vp[j].h <= vp[i].h && dp2[i] < dp2[j] + 1) {
//					dp2[i] = dp2[j] + 1;
//				}
//			}
//		}
//		for (int i = 0; i < N; ++i) {
//			if (max < dp2[i]) {
//				max = dp2[i];
//			}
//		}
//		cout << max << endl;
//	}
//	return 0;
//}



#include<vector>
#include<climits>
#include<iostream>
using namespace std;
//
//class MaxGap {
//public:
//	int MaxMum(int n, vector<int>&A) {
//		int max = INT_MIN;
//			for (int i = 0; i < n; ++i) {
//				if (A[i] > max) {
//					max = A[i];
//				}
//			}
//		return max;
//	}
//	int findMaxGap(vector<int> A, int n) {
//		int Max = INT_MIN;
//			for (int i = 0; i < n; ++i) {
//				int max_j = INT_MIN;
//					for (int j = i + 1; j < n; ++j) {
//						if (A[j] > max_j) {
//							max_j = A[j];
//						}
//					}
//				if (abs(MaxNum(i, A) - max_j) > Max) {
//					Max = abs(MaxNum(i, A) - max_j);
//				}
//			}
//		return Max;
//	}
//};
class Printer {
public:
	void Printf(vector<vector<int>>& mat, vector<int> res, int start_row, int start_col, int row, int col) {
		if (row <= 0 && col <= 0) {
			return;
		}
		//遍历最上面的行
		for (int up = start_col; up < col; ++up) {
			res.push_back(mat[start_row][up]);
		}
		//遍历最左边的列
		for (int right = start_row + 1; right < row; ++right) {
			res.push_back(mat[right][col - 1]);
		}
		//遍历最下面的行
		for (int down = col - 2; down >= start_col; --down) {
			res.push_back(mat[row - 1][down]);
		}
		//遍历最右面的列
		for (int left = row - 2; left > start_row; --left) {
			res.push_back(mat[left][start_col]);
		}
		Printf(mat, res, start_row + 1, start_col + 1,row - 2, col - 2);
	}
	vector<int> clockwisePrint(vector<vector<int> > mat,int n, int m) {
		//因为顺时针处理逻辑相似，故采用递归查询
		vector<int> res;
		Printf(mat, res, 0, 0, n, m);
		return res;
	}
};
int main() {

	Printer p;
	vector<int> res;
	vector<vector<int>> mat(3,vector<int>(3,0));
	for (int i = 0; i < 3;++i) {
		for (int j = 0; j < 3;++j) {
			mat[i][j] = i + j;
		}
	}
	res = p.clockwisePrint(mat,3,3);
	for (auto& e:res) {
		cout << e << endl;
	}
	system("pause");
	return 0;
}