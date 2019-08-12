//#include<iostream>
//#include <memory>
//using namespace std;
//
//class Date
//{
//public:
//Date() { cout << "Date()" << endl;}
//~Date(){ cout << "~Date()" << endl;}
//int _year;
//int _month;
//int _day;
//};
//
//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = NULL)
//		: _ptr(ptr)
//	{}
//	~AutoPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	// 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系，
//	// 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
//	AutoPtr(AutoPtr<T>& ap)
//		: _ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// 检测是否为自己给自己赋值
//		if (this != &ap)
//		{
//			// 释放当前对象中资源
//			if (_ptr)
//				delete _ptr;
//			// 转移ap中资源到当前对象中
//			_ptr = ap._ptr;
//			ap._ptr = NULL;
//		}
//		return *this;
//	}
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	T* _ptr;
//};
//int main()
//{
//	AutoPtr<Date> ap(new Date);
//	// 现在再从实现原理层来分析会发现，这里拷贝后把ap对象的指针赋空了，导致ap对象悬空
//	// 通过ap对象访问资源时就会出现问题。
//	return 0;
//}
#include<string>
#include<iostream>
using namespace std;
int main() {
	string first("They are students.");
	string second("aeheou");
	int str[256] = { 0 };
	for (int i = 0; i < second.size();++i) {
		str[second[i]] = 1;
	}
	for (int i = 0; i < first.size();++i) {
		if (str[first[i]] == 1) {
			first.erase(first.begin()+i);
			i;
		}
	}
	cout << first << endl;
	return 0;
}

