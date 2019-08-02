#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct player {
	int w;
	int h;
};
bool com_w(player p1, player p2) {
	if (p1.w != p2.w) {
		return p1.w <= p2.w;
	}
	else {
		return p1.h > p2.h;
	}
}


int main() {
	int N;
	int h;
	int w;
	int index;
	vector<player> vp;
	while (cin >> N) {
		vp.clear();
		for (int i = 0; i < N; ++i) {
			player pt;
			cin >> index >> w >> h;
			pt.w = w;
			pt.h = h;
			vp.push_back(pt);
		}
		sort(vp.begin(), vp.end(), com_w);

		int dp2[N];
		int max = 0;
		dp2[0] = 1;
		for (int i = 1; i < N; ++i) {
			dp2[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (vp[j].h <= vp[i].h && dp2[i] < dp2[j] + 1) {
					dp2[i] = dp2[j] + 1;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (max < dp2[i]) {
				max = dp2[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}