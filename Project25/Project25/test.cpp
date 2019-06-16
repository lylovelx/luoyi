////#include<iostream>
////#include<stack>
////#include<string>
////#include<vector>
////using namespace std;
////class Solution {
////public:
////	int evalRPN(vector<string>& tokens) {
////		stack<int> s;
////		for (int i = 0; i < tokens.size(); ++i) {
////			string& str = tokens[i];
////			if (!(str == "-" || str == "+" || str == "/" || str == "*")) {
////				s.push(atoi(str.c_str()));
////			}
////			else {
////				int right = s.top();
////				s.pop();
////				int left = s.top();
////				s.pop();
////				switch (str[0]) {
////				case '+':
////					s.push(right + left);
////					break;
////				case '-':
////					s.push(left - right);
////					break;
////				case '/':
////					s.push(left / right);
////					break;
////				case '*':
////					s.push(left*right);
////					break;
////				}
////			}
////		}
////		return s.top();
////	}
////};
//
//	//int getValue(vector<int> gifts, int n) {
//	//	//�ü�¼���㷨��ʵ��
//	//	int count = 0, i = 0;
//	//	int tmp = gifts[0];
//	//	while (i < n) {
//	//		if (count == 0) {
//	//			tmp = gifts[i];
//	//			count = 1;
//	//		}
//	//		else if (tmp != gifts[i]) {
//	//			count--;
//	//		}
//	//		else {
//	//			count++;
//	//		}
//	//		i++;
//	//	}
//	//	if (count == 0) {
//	//		return 0;
//	//	}
//	//	else {
//	//		return tmp;
//	//	}
//	//}
//	//int main() {
//	//	int n;
//	//	cin >> n;
//	//	vector<int> v(n);
//	//	for (int i = 0; i < n;++i) {
//	//		cin >> v[i];
//	//	}
//	//	cout << getValue(v, n) << endl;
//	//	system("pause");
//	//	return 0;
//	//}
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
////�ַ�������༭dp
//int main() {
//	string s1, s2;
//	while (cin >> s1 >> s2) {
//		int n = s1.size();
//		int m = s2.size();
//		//����Ϊ�˿��ǵ��ַ���Ϊ�յ����������Ҫ���һ��λ���������ַ���Ϊ�յ����
//		int dp[n + 1][m + 1];
//		//��ά�����dp��ʼ��
//		for (int i = 0; i <= n; ++i) {
//			dp[i][0] = i;
//		}
//		for (int j = 0; j <= m; ++j) {
//			dp[0][j] = j;
//		}
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= m; ++j) {
//				//��Ϊ�ַ����±��Ǵ�0��ʼ�ģ�����Ҫ -1 
//				if (s1[i - 1] == s2[j - 1]) {
//					dp[i][j] = dp[i - 1][j - 1];
//				}
//				else {
//					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
//				}
//			}
//		}
//		cout << dp[n][m] << endl;
//	}
//	return 0;
//}
//class Bonus {
//public:
//	int getMost(vector<vector<int> > board) {
//		int n = board.size();
//		int m = board[0].size();
//		int dp[n][m];
//		dp[0][0] = board[0][0];
//		for (int i = 1; i < n; ++i) {
//			dp[i][0] = dp[i - 1][0] + board[i][0];
//		}
//		for (int j = 1; j < m; ++j) {
//			dp[0][j] = dp[0][j - 1] + board[0][j];
//		}
//		for (int i = 1; i < n; ++i) {
//			for (int j = 1; j < m; ++j) {
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
//			}
//		}
//		return dp[n - 1][m - 1];
//	}
//};
#include<iostream>
#include<vector>
using namespace std;
//����
int N, M;
//����·��
vector<vector<int>> path_best;
//��ʱ·��
vector<vector<int>> path_temp;
//����
vector<vector<int>> maritx;

void dfs(int x, int y) {
	//��ǵ�ǰλ���Ѿ�����
	maritx[x][y] = 1;
	//����·������path_temp����
	path_temp.push_back({ x,y });
	//�ж��Ƿ�����
	if (x == N - 1 && y == M - 1) {
		//ÿ�ε�������Ժ����path_best,ȷ��Ϊ���·��
		if (path_best.empty() || path_best.size() > path_temp.size()) {
			//ֱ�Ӹ�ֵ---easy
			path_best = path_temp;
			return;
		}
	}
	//������
	if (x - 1 >= 0 && maritx[x - 1][y] == 0)  dfs(x - 1, y);
	//������
	if (x + 1 < N && maritx[x + 1][y] == 0)  dfs(x + 1, y);
	//������
	if (y - 1 >= 0 && maritx[x][y - 1] == 0)  dfs(x, y - 1);
	//������
	if (y + 1 < M && maritx[x][y + 1] == 0)  dfs(x, y + 1);
	//������������һ�Σ�һ�α���������Ȼ�����
	maritx[x][y] = 0;
	path_temp.pop_back();
	return;
}

int main() {
	while (cin >> N >> M) {
		//��ʼ������
		maritx = vector<vector<int>>(N, vector<int>(M, 0));
		//ÿһ�ζ�����һ�εĽ�����
		path_temp.clear();
		path_best.clear();
		for (auto& i : maritx) {
			for (auto& j : i) {
				cin >> j;
			}
		}
		//���������������
		dfs(0, 0);//���ݷ�
		for (auto& i : path_best) {
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
		}
	}
	return 0;
}