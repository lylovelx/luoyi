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
//	// һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ��
//	// �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
//	AutoPtr(AutoPtr<T>& ap)
//		: _ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// ����Ƿ�Ϊ�Լ����Լ���ֵ
//		if (this != &ap)
//		{
//			// �ͷŵ�ǰ��������Դ
//			if (_ptr)
//				delete _ptr;
//			// ת��ap����Դ����ǰ������
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
//	// �����ٴ�ʵ��ԭ����������ᷢ�֣����������ap�����ָ�븳���ˣ�����ap��������
//	// ͨ��ap���������Դʱ�ͻ�������⡣
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

