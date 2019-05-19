#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	std::vector<int> nums;
	int n, sum = 0;
	cin >> n;
	nums.resize(3 * n);
	sort(nums.begin(), nums.end());
	if (n == 1) return nums[1];
	for (int i = 0; nums.size(); ++i){
		cin >> nums[i];
	}
	for (int i = 0; i<nums.size(); ++i){
		if (i % 2 == 0){
			sum += nums[i];
		}
	}
	cout << sum << endl;
	return 0;

}
