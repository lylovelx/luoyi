
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
		//���ö��ֲ��ҷ�
		int start = 0;
		int end = rotateArray.size() - 1;
		//����������൱��û���ƶ�
		if (rotateArray[start] < rotateArray[end]) {
			return rotateArray[start];
		}
		while (start <= end) {
			int middle = (start + end) / 2;
			//��������ȵ�������ǲ����ж�ָ������ƶ�������ֻ�ܴ�ͷ��β����
			if (rotateArray[start] == rotateArray[end] && rotateArray[middle] == rotateArray[start]) {
				int min = rotateArray[0];
				for (size_t i = 0; i < rotateArray.size(); ++i) {
					if (min > rotateArray[i]) {
						min = rotateArray[i];
					}
				}
				return min;
			}
			//���Ϊһ��ʱ��Ϊ��Сֵ
			if (end - start == 1) {
				return rotateArray[end];
			}

			//˵������ǵݼ����е���
			if (rotateArray[middle] >= rotateArray[start]) {
				start = middle;
			}
			//˵�����ҷǵݼ����е���
			if (rotateArray[middle] <= rotateArray[end]) {
				end = middle;
			}
		}
		return 0;
	}
};