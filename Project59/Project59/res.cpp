//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		//利用插入排序的思想
//		for (int i = 1; i < array.size(); ++i) {
//			int temp = array[i];
//			int j;
//			for (j = i - 1; j >= 0 && temp %2 != 0 && array[j] % 2 == 0; --j) {
//				array[j + 1] = array[j];
//			}
//			array[j + 1] = temp;
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> v = { 1,2,3,2,4,2,7,9};
//	s.reOrderArray(v);
//	for (auto e : v) {
//		cout << e << " ";
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//class Solution {
//public:
//	void print(vector<vector<int>> matrix, int start_row, int start_col, int row, int col) {
//		//出口
//		if (start_row >= row || start_col >= col) {
//			return;
//		}
//		//打印第一行
//		for (int i = start_col; i < col; ++i) {
//			cout << matrix[start_row][i];
//		}
//		//打印左边的列
//		for (int i = start_row + 1; i < row; ++i) {
//			cout << matrix[i][col - 1];
//		}
//		//打印最下边的一行
//		for (int i = col - 2; i >= start_col; --i) {
//			cout << matrix[row - 1][i];
//		}
//		//打印最右边的列
//		for (int i = row - 2; i > start_row; --i) {
//			cout << matrix[i][start_col];
//		}
//		//递归
//		print(matrix, start_row + 1, start_col + 1, row - 1, col - 1);
//
//	}
//	void printMatrix(vector<vector<int> > matrix) {
//		int row = matrix.size();
//		int col = matrix[0].size();
//		print(matrix, 0, 0, row, col);
//	}
//};

//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		stack<int> s;
//		int i = 0;
//		int j = 0;
//		while (i < pushV.size() || !s.empty()) {
//			if (s.empty()) {
//				s.push(pushV[i]);
//				i++;
//				continue;
//			}
//			if (s.top() == popV[j]) {
//				s.pop();
//				j++;
//				continue;
//			}
//			if (s.top() != popV[j]) {
//				s.push(pushV[i]);
//				i++;
//				continue;
//			}
//		}
//		if (j == popV.size()) {
//			return true;
//		}
//		return false;
//	}
//};


//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		if (pushV.empty() || popV.empty()) return false;
//
//		stack<int> s;
//		int i = 0, j = 0;
//		while (i < pushV.size()) {
//			s.push(pushV[i++]);
//			while (j < popV.size() && s.top() == popV[j++]) {
//				s.pop();
//			}
//		}
//
//		return s.empty();
//	}
//};
//class Solution {
//public:
//	bool VerifySquenceOfBSt(vector<int> sequence, int start, int end) {
//		if (start >= end) {
//			return true;
//		}
//		int i;
//		for (i = start; i <= end; ++i) {
//			if (sequence[i] > sequence[end]) {
//				break;
//			}
//		}
//		for (int j = i; j <= end - 1; ++j) {
//			if (sequence[j] < sequence[end]) {
//				return false;
//			}
//		}
//		return VerifySquenceOfBSt(sequence, start, i - 1) && VerifySquenceOfBSt(sequence, i, end - 1);
//	}
//	bool VerifySquenceOfBST(vector<int> sequence) {
//		if (sequence.empty()) return false;
//		return VerifySquenceOfBSt(sequence, 0, sequence.size() - 1);
//	}
//};

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	void Sum(vector<int>& v) {
		int sum = 0;
		for (int i = 0; i < v.size(); ++i) {
			sum += v[i];
		}
	}
	void Find(TreeNode* root, vector<vector<int>>& vv, vector<int> v, int exp) {

		v.push_back(root->val);

		if (root->right == nullptr && root->left == nullptr && Sum(v) == exp) {
			vv.push_back(v);
			return;
		}

		Find(root->left, vv, v, exp);
		Find(root->right, vv, v, exp);
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> vv;
		if (root == nullptr) return vv;
		vector<int> v;
		Find(root, vv, v, expectNumber);
		sort(vv.rbegin(), vv, rend());
		return vv;
	}
};
int main() {
	Solution s;
	//vector<vector<int>> v = { {1,2},{5,6},{9,10},{13,14} };
	//s.printMatrix(v);

	/*vector<int> s(1);
	if (s.empty()) {
		cout << " 222222222222222";
		s.push_back(1);
	}
	cout << s[0] << endl;*/


	vector<int> a = { 9,8,7,6,5,4,3,2,11 };

	cout << s.VerifySquenceOfBST(a);
	system("pause");
}