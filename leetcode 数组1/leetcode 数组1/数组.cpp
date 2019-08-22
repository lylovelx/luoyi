#include<stdio.h>
#include<stdlib.h>
#include<string.h>
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())  return 0;
		int index = 0;
		for (int i = 1; i<nums.size(); ++i){
			if (nums[index] != nums[i]){
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size()<2) return nums.size();
		int index = 0;
		int count = 1;

		for (int i = 1; i<nums.size(); ++i){
			if (nums[i] == nums[index] && count == 1){
				nums[++index] = nums[i];
				count = 2;
			}

			if (nums[i] == nums[index] && count == 2){
				continue;
			}

			if (nums[i] != nums[index]){
				nums[++index] = nums[i];
				count = 1;
			}

		}
		return index + 1;
	}
int search(int nums[], int target,int size) {
	//左闭右闭区间
	//if (nums.size()<1) return -1;
	int left = 0;
	int right = 2 - 1;
	while (left <= right){
		int mid = (right + left) / 2;
		//分而之治
		if (target == nums[mid]){
			return mid;
		}
		if (nums[left]<nums[mid]){
			if (target >= nums[left] && target<nums[mid]){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		else{
			if (target <= nums[right] && target>nums[mid]){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
	}
	return -1;
}
//int main(){
//	int arr[] = { 3,1 };
//	int size = sizeof(arr) / sizeof(int);
//	int a = search(arr,1,2);
//	printf("%d",a);
//	system("pause");
//	return 0;
//}
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//使用哈希表
		unordered_map<int, bool> used;
		for (auto i : nums)  used[i] = false;

		int longest = 0;

		for (auto i : nums){
			if (used[i])  continue;

			int length = 1;

			used[i] = true;

			for (int j = i + 1; used.find[j] != used.end(); ++j){
				used[j] = true;
				++length;
			}

			for (int j = i - 1; used.find[j] != used.end(); ++j){
				used[j] = true;
				++length;
			}

			longest = max(length, longest);
		}
		return longest;
	}
};
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size()<3)  return result;
		sort(nums.begin(), nums.end());
		const int target = 0;
		auto last = nums.end();
		for (auto i = nums.begin(); i<last - 2; ++i){
			auto j = i + 1;
			if (i>nums.begin() && *i == *(i - 1))  continue;
			auto k = last - 1;
			while (j<k){
				if (*i + *j + *k<target){
					++j;
					while (*j == *(j - 1) && j<k) ++j;
				}
				else if (*i + *j + *k>target){
					--k;
					while (*k == *(k + 1) && j<k) --k;
				}
				else{
					result.push_back({ *i, *j, *k });
					++j;
					--k;
					while (*j == *(j - 1) && *k == *(k + 1) && j<k) ++j;
				}
			}
		}
		return result;
	}
};
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		int min_gap = INT_MAX;
		sort(nums.begin(), nums.end());
		for (auto a = nums.begin(); a<nums.end(); ++a){
			auto b = a + 1;
			auto c = nums.end() - 1;
			while (b<c){
				const int sum = *a + *b + *c;
				const int gap = abs(sum - target);
				if (gap<min_gap){
					result = sum;
					min_gap = gap;
				}
				if (sum<target) ++b;
				else           --c;
			}
		}
		return result;
	}
};
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {

		if (nums.size() == 0) return 0;
		int index = 0;
		for (int j = 0; j<nums.size(); ++j){
			if (nums[j] != val){
				nums[index++] = nums[j];
			}
		}
		return index;
	}
};