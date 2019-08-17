////#include<iostream>
////#include<algorithm>
////using namespace std;
////	for (int i = 1; i < size;++i) {
////		int temp = arr[i];
////		int j;
////		for (j = i - 1; j >= 0 && temp < arr[j];--j) {
////			arr[j + 1] = arr[j];
////		}
////		arr[j + 1] = temp;
////	}
////}
////
////冒泡排序
////void Sort(int* arr,int size) {
////	for (int i = 0; i < size - 1;++i) {
////		for (int j = 0; j < size - 1 - i;++j) {
////			if (arr[j] > arr[j+1]) {
////				swap(arr[j],arr[j+1]);
////			}
////		}
////	}
////}
////选择排序
////void Sort(int* arr,int size) {
////	for (int i = 0; i < size-1;++i) {
////		int maxIndex = 0;
////		int j;
////		for (j = 0; j < size - i;++j) {
////			if (arr[maxIndex] < arr[j]) {
////				maxIndex = j;
////			}
////		}
////		swap(arr[j-1],arr[maxIndex]);
////	}
////}
////堆排序
////void AdjustDown(int* arr,int size,int index){
////	//小堆----排降序
////	while (1) {
////		//左孩子下标
////		int leftIndex = 2 * index + 1;
////		//判断是否存在
////		if (leftIndex>=size) {
////			return;
////		}
////		//判断右孩子是否存在
////		int minIndex = leftIndex;
////		int rightIndex = 2 * index + 2;
////		//得到最小下标
////		if (rightIndex < size&&arr[rightIndex] < arr[leftIndex]) {
////			minIndex = rightIndex;
////		}
////		if (arr[index] < arr[minIndex]) {
////			return;
////		}
////		swap(arr[index],arr[minIndex]);
////		index = minIndex;
////	}
////}
////void AdjustUp(int* arr, int size, int index) {
////	//大堆排升序
////	while (index > 0) {
////		int parentIndex = (index - 1) / 2;
////		if (arr[parentIndex]>=arr[index]) {
////			return;
////		}
////		swap(arr[parentIndex],arr[index]);
////		index = parentIndex;
////	}
////}
////void CreateHeap(int* arr, int size) {
////
////	/*for (int i = (size - 2) / 2; i >= 0;--i) {
////		AdjustUp(arr,size,i);
////	}*/
////	for (int i = size - 1; i >= 0;--i) {
////		AdjustUp(arr,size,i);
////	}
////}
////void Sort(int* arr, int size) {
////	CreateHeap(arr, size);
////	for (int i = 0; i < size; ++i) {
////		swap(arr[0], arr[size - 1 - i]);
////		AdjustUp(arr, size - 1 - i, size-i-1);
////	}
////}
////快速排序
////int partion_1(int arr[], int left, int right) {
////	int begin = left;
////	int end = right;
////	int pivot = arr[right];
////	while (begin < end) {
////		while (begin < end&&arr[begin] <= pivot) {
////			begin++;
////		}
////		while (begin < end&&arr[end] >= pivot) {
////			end--;
////		}
////		swap(arr[begin], arr[end]);
////	}
////	swap(arr[begin], arr[right]);
////	return begin;
////}
////void QuickSort(int arr[], int left, int right) {
////	if (left >= right) {
////		return;
////	}
////	int d = partion_1(arr, left, right);
////	QuickSort(arr, left, d - 1);
////	QuickSort(arr, d + 1, right);
////}
////
//////插入排序 
//////void Sort(int* arr,int size) {
////
//////归并排序
////void Merge(int* arr,int left,int mid, int right) {
////	int* tmp = (int*)malloc(sizeof(int)*(right - left+1));
////	int i = left;
////	int j = mid+1;
////	int k = 0;
////	while (i<=mid&&j<=right) {
////		if (arr[i]>arr[j]) {
////			tmp[k++] = arr[j++];
////		}
////		else {
////			tmp[k++] = arr[i++];
////		}
////	}
////	while (i<=mid) {
////		tmp[k++] = arr[i++];
////	}
////	while (j<=right) {
////		tmp[k++] = arr[j++];
////	}
////	for (int i = 0; i < k;++i) {
////		arr[left+i] = tmp[i];
////	}
////	free(tmp);
////}
////void Sort(int* arr,int left,int right) {
////	if (left >= right) {
////		return;
////	}
////	int mid = (right + left) / 2;
////	Sort(arr,left,mid);
////	Sort(arr,mid+1,right);
////	Merge(arr,left,mid,right);
////}
////
////int main() {
////	int arr[] = { 1,3,1,11,23,23,1,2,3,67,23,232,2 };
////	Sort(arr, 0,sizeof(arr) / sizeof(arr[0])-1);
////	for (auto e : arr) {
////		cout << e << " ";
////	}
////	return 0;
////}
////
/////*
////struct ListNode {
////	int val;
////	struct ListNode *next;
////	ListNode(int x) :
////		val(x), next(NULL) {
////	}
////};
////*/
////class Solution {
////public:
////	ListNode* deleteDuplication(ListNode* pHead)
////	{
////		ListNode* Head = new ListNode(1);
////		Head->next = pHead;
////		ListNode* pre = Head;
////		ListNode* cur = pHead;
////		while (cur != nullptr) {
////			if (cur->next != nullptr&&cur->val == cur->next->val) {
////				while (cur->next != nullptr&&cur->val == cur->next->val) {
////					cur = cur->next;
////				}
////				pre->next = cur->next;
////				cur = cur->next;
////			}
////			else {
////				pre = pre->next;
////				cur = cur->next;
////			}
////
////		}
////		return Head->next;
////	}
////};
////class Solution {
////public:
////	vector<vector<int>> levelOrder(TreeNode* root) {
////		vector<vector<int>> vv;
////		if (root == nullptr) return vv;
////		queue<TreeNode*> q;
////		q.push(root);
////		while (!q.empty()) {
////			int layer_size = q.size();
////			//记录每一层的节点
////			vector<int> ret;
////			for (int i = 0; i < layer_size; ++i) {
////				auto p = q.front();
////				if (p->left)  q.push(p->left);
////				if (p->right) q.push(p->right);
////				ret.push_back(p->val);
////				q.pop();
////			}
////			vv.push_back(ret);
////		}
////		return vv;
////	}
////};
////
////class Solution {
////public:
////	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
////		if (root == nullptr)
////			return nullptr;
////		if (root == p || root == q) {
////			return root;
////		}
////		TreeNode* left = lowestCommonAncestor(root->left, p, q);
////		TreeNode* right = lowestCommonAncestor(root->right, p, q);
////
////		if (left != nullptr&&right != nullptr) {
////			return root;
////		}
////		else if (left != nullptr) {
////			return left;
////		}
////		else if (right != nullptr) {
////			return right;
////		}
////		return nullptr;
////	}
////}
//
//
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	double Power(double base, int exponent) {
//		int n = exponent;
//		if (base == 0) {
//			if (exponent >= 0) {
//				return 0;
//			}
//			else {
//				throw "Division by zero condition!";
//			}
//		}
//		else {
//			if (base == 1) {
//				return 1;
//			}
//		}
//		double result = 1;
//		while (exponent != 0) {
//			if ((exponent & 1) == 1) {
//				result *= base;
//			}
//			base *= base;
//			exponent >>= 1;
//		}
//		return n > 0 ? result : (1 / result);
//	}
//};
//
//int main() {
//
//	Solution s;
//	cout << s.Power(2.2, 5) << endl;
//	return 0;
//}