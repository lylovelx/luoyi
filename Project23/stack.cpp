class Solution {
public:
	bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path) {
		if (root == nullptr) {
			return false;
		}
		使用前序遍历的方式将节点的路劲全部压入栈中
		path.push(root);
		if (root == x) {
			return true;
		}
		if (GetPath(root->left, x, path) == true) {
			return true;
		}
		if (GetPath(root->right, x, path) == true) {
			return true;
		}
		程序走到这里说明左右节点都不满足，则继续弹出
		path.pop();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		使用两个栈来分别记录p,q的路径
		stack<TreeNode*> ppath;
		stack<TreeNode*> qpath;
		GetPath(root, p, ppath);
		GetPath(root, q, qpath);
		让长的路径弹出，长度和短的一样，然后寻找共同的节点即为公共系节点
		while (ppath.size() != qpath.size()) {
			if (ppath.size() > qpath.size()) {
				ppath.pop();
			}
			else {
				qpath.pop();
			}
		}
		while (ppath.top() != qpath.top()) {
			ppath.pop();
			qpath.pop();
		}
		return ppath.top();
	}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == nullptr) return vv;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int layer_size = q.size();
			记录每一层的节点
			vector<int> ret;
			for (int i = 0; i < layer_size; ++i) {
				auto p = q.front();
				if (p->left)  q.push(p->left);
				if (p->right) q.push(p->right);
				ret.push_back(p->val);
				q.pop();
			}
			vv.push_back(ret);
		}
		return vv;
	}
};
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int dp[s1.size()][s2.size()];
		int max = 0;
		transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
		transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
		for (int i = 0; i < s1.size(); ++i) {
			for (int j = 0; j < s2.size(); ++j) {
				if (s1[i] == s2[j]) {
					if (i == 0 || j == 0) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = dp[i - 1][j - 1] + 1;
					}
				}
				else {
					dp[i][j] = 0;
				}
				if (max < dp[i][j]) {
					max = dp[i][j];
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size()) return false;
		stack<int> s;
		int index = 0;
		int outdex = 0;
		while (outdex < popV.size()) {
			while (s.empty() || s.top() != popV[outdex]) {
				if (index < pushV.size()) {
					s.push(pushV[index]);
					index++;
				}
				else {
					return false;
				}
			}
			s.pop();
			outdex++;
		}
		return true;
	}
};