
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return construct(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
	}

	TreeNode* construct(vector<int>& pre, vector<int>& vin, int l1, int r1, int l2, int r2)
	{
		if (l1 > r1 || l2 > r2) return NULL;
		TreeNode* root = new TreeNode(pre[l1]);
		int val = pre[l1];
		int index;
		for (index = l2; index <= r2; index++)
		{
			if (vin[index] == val)
				break;
		}
		int left_tree_len = index - l2;
		int right_tree_len = r2 - index;
		if (left_tree_len > 0)
			root->left = construct(pre, vin, l1 + 1, l1 + left_tree_len, l2, index - 1);
		if (right_tree_len > 0)
			root->right = construct(pre, vin, l1 + 1 + left_tree_len, r1, index + 1, r2);
		return root;
	}
};
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		//利用二分查找法
		int start = 0;
		int end = rotateArray.size() - 1;
		//这种情况下相当于没有移动
		if (rotateArray[start] < rotateArray[end]) {
			return rotateArray[start];
		}
		while (start <= end) {
			int middle = (start + end) / 2;
			//在三者相等的情况下是不能判断指针如何移动，所以只能从头到尾遍历
			if (rotateArray[start] == rotateArray[end] && rotateArray[middle] == rotateArray[start]) {
				int min = rotateArray[0];
				for (size_t i = 0; i < rotateArray.size(); ++i) {
					if (min > rotateArray[i]) {
						min = rotateArray[i];
					}
				}
				return min;
			}
			//相差为一的时候即为最小值
			if (end - start == 1) {
				return rotateArray[end];
			}

			//说明在左非递减序列当中
			if (rotateArray[middle] >= rotateArray[start]) {
				start = middle;
			}
			//说明在右非递减序列当中
			if (rotateArray[middle] <= rotateArray[end]) {
				end = middle;
			}
		}
		return 0;
	}
};