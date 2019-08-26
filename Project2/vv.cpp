////////#include<iostream>
////////#include<string>
////////#include<vector>
////////#include<algorithm>
////////using namespace std;
/////////*class Solution {
////////public:
////////	static bool cmp(int a, int b) {
////////
////////		string A = to_string(a) + to_string(b);
////////		string B = to_string(b) + to_string(a);
////////		return A < B;
////////	}
//////// 	string PrintMinNumber(vector<int> numbers) {
////////		string result;
////////		if (numbers.empty()) return result;
////////		sort(numbers.begin(), numbers.end(), cmp);
////////		for (auto& e : numbers) {
////////			result += to_string(e);
////////		}
////////		return result;
////////	}
////////}*/;
//////////class Solution {
//////////public:
//////////	int GetUglyNumber_Solution(int index) {
//////////		int tmp = 0;
//////////		while (index) {
//////////			tmp++;
//////////			int i = tmp;
//////////			while (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
//////////				if (i % 2 == 0) i /= 2;
//////////				if (i % 3 == 0) i /= 3;
//////////				if (i % 5 == 0) i /= 5;
//////////			}
//////////			if (i == 1) {
//////////				index--;
//////////			}
//////////			
//////////		}
//////////		return tmp;
//////////	}
//////////};
////////#include<map>
////////int main() {
////////
////////	map<int,string> s;
////////	s.insert(make_pair(1,"www"));
////////	s.insert(make_pair(2,"www"));
////////	for (auto& e : s) {
////////		cout << e.second << " ";
////////	}
////////	system("pause");
////////}
//////
//////#include<stdio.h>
//////#include<stdlib.h>
//////#include<iostream>
//////using namespace std;
//////
//////
//////class A {
//////public:
//////	A(){
//////		cout << "A()\n";
//////	}
//////private:
//////	int _a;
//////	int _b;
//////};
//////int main() {
//////
//////	/*char a = -1;
//////	signed char b = -1;
//////	unsigned char c = -1;
//////	printf("a=%d,b=%d,c=%d", a, b, c)*/
//////
//////	/*int i = -20;
//////	unsigned int j = 10;*/
//////	//int n = 9;
//////	//float *pFloat = (float *)&n;
//////	//printf("n的值为：%d\n", n);
//////	//printf("*pFloat的值为：%f\n", *pFloat);
//////	//*pFloat = 9.0;
//////	//printf("num的值为：%d\n", n);
//////	//printf("*pFloat的值为：%f\n", *pFloat);
//////
//////	//int a = 10;
//////	//int& b = a;
//////	//b = 1000;
//////	//cout << b << endl
//////	
//////	A* a =new A();
//////	system("pause");
//////	return 0;
//////}
////
////#include<iostream>
////#include<memory>
////#include<mutex>
////#include<thread>
////using namespace std;
//////mutex mtx;
//////int n = 0;
//////void func() {
//////	for (int i = 0; i < 100; ++i) {
//////		lock_guard<mutex> lock(mtx);
//////		++n;
//////	}
//////}
////class A
////{
////public:
////	virtual void f() {
////		cout << "HelloWorld\n";
////	}
////};
////class B : public A
////{
////	virtual void s() {
////		cout << "     " << endl;
////	}
////};
////void fun(A* pa)
////{
////	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
////	B* pb1 = static_cast<B*>(pa);
////	B* pb2 = dynamic_cast<B*>(pa);
////	cout << "pb1:" << pb1 << endl;
////	cout << "pb2:" << pb2 << endl;
////}
////int main()
////{
////	A a;
////	B b;
////	fun(&a);
////	fun(&b);
////	
////	system("pause");
////	return 0;
////}
//////int main() {
//////	
//////	/*shared_ptr<int> sp1(new int(10));
//////	shared_ptr<int> sp2(sp1);
//////	cout << sp1.use_count() << endl;
//////	cout << sp2.use_count() << endl;
//////	thread t1(func);*/
//////	/*int a = 10;
//////	int* p = static_cast<int*>(&a);*/
//////	//cout << p << endl;
//////	system("pause");
//////}
//
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int GetNumberOfK(vector<int> data, int k) {
//		if (data.empty()) return 0;
//
//		//二分查找的思路
//		int start = 0, cnt = 0;
//		int end = data.size() - 1;
//		int pos;
//		while (start <= end) {
//
//			int mid = (start + end) / 2;
//			if (data[mid] > k) {
//				end = mid - 1;
//			}
//			if (data[mid] < k) {
//				start = mid + 1;
//			}
//			if (data[mid] == k) {
//				pos = mid;
//				break;
//			}
//		}
//		int tmp1 = pos;
//		int tmp2 = pos + 1;
//		while (tmp1 >= 0) {
//			if (data[tmp1] == k) {
//				cnt++;
//			}
//			else {
//				break;
//			}
//			tmp1--;
//		}
//		while (tmp2 <= end) {
//			if (data[tmp2] == k) {
//				cnt++;
//			}
//			else {
//				break;
//			}
//			tmp2++;
//		}
//		return cnt;
//	}
//};
//int main() {
//	Solution s;
//	cout << s.GetNumberOfK({ 3,3,3,3,4,5 }, 3) << endl;
//	system("pause");
//	return 0;
//}
#include<map>
//class Solution {
//public:
//	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//		//异或
//		int res = 0;
//		for (int i = 0; i < data.size(); ++i) {
//			res ^= data[i];
//		}
//		int N;
//		for (int i = 0; i < 32; ++i) {
//			if ((res & (1 << i)) != 0) {
//				N = i;
//				break;
//			}
//		}
//		*num1 = 0;
//		*num2 = 0;
//		for (int i = 0; i < data.size(); ++i) {
//			if ((data[i] & (1 << N)) != 0) {
//				*num1 ^= data[i];
//			}
//			else {
//				*num2 ^= data[i];
//			}
//		}
//	}
//};

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		//利用滑动窗口的思想
		vector<vector<int>> v;
		if (sum < 3) return v;
		int start = 1;
		int end = 2;
		while (start < end) {
			int cur = (end - start + 1)*(start + end) / 2;
			if (sum == cur) {
				vector<int> tmp;
				for (int i = start; i < end; ++i) {
					tmp.push_back(i);
				}
				v.push_back(tmp);
				start++;
			}
			if (cur < sum) {
				end++;
			}
			if (cur > sum) {
				start++;
			}
		}
		return v;
	}
};
int main() {
	
	Solution s;
	vector<vector<int>> v = s.FindContinuousSequence(3);
	
	for (auto& e : v) {
		for (auto& i : e) {
			cout << i << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}