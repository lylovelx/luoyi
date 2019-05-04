#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.empty())  return 0;
//		int index = 0;
//		for (int i = 1; i<nums.size(); ++i){
//			if (nums[index] != nums[i]){
//				nums[++index] = nums[i];
//			}
//		}
//		return index + 1;
//	}
//};
//
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.size()<2) return nums.size();
//		int index = 0;
//		int count = 1;
//
//		for (int i = 1; i<nums.size(); ++i){
//			if (nums[i] == nums[index] && count == 1){
//				nums[++index] = nums[i];
//				count = 2;
//			}
//
//			if (nums[i] == nums[index] && count == 2){
//				continue;
//			}
//
//			if (nums[i] != nums[index]){
//				nums[++index] = nums[i];
//				count = 1;
//			}
//
//		}
//		return index + 1;
//	}
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
int main(){
	int arr[] = { 3,1 };
	int size = sizeof(arr) / sizeof(int);
	int a = search(arr,1,2);
	printf("%d",a);
	system("pause");
	return 0;
}

