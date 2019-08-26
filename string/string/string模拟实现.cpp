#include <assert.h>
#include<iostream>
using namespace std;
class String {
	typedef char* iterator;
	typedef const char* const_iterator;
	//迭代器
	const_iterator begin() const {
		return _str;
	}
	const_iterator end() const {
		return _str + _size;
	}
	iterator begin() {
		return _str;
	}
	iterator end() {
		return _str + _size;
	}
	//构造函数
	String(const char* str = "") :_str(nullptr), _capacity(0) {
		_size = strlen(str);
		Reserve(_size);
		strcpy(_str, str);
	}
	//拷贝构造
	String(const String& s) :_str(nullptr), _size(0), _capacity(0) {
		//现代写法，创建一个临时对象,在临时对象出了作用域之后自动释放空间
		//类的默认拷贝构造是浅拷贝
		//在这里只能调用构造函数
		String tmp(s._str);
		Swap(tmp);
	}
	//赋值重载运算符 =
	String& operator=(String& s) {
		//赋值重载的现代写法，创建临时对象
		//在作用域结束之后，原来对象的空间自动释放
		Swap(s);
		return *this;
	}
	//Swap的实现
	void Swap(String& s) {
		//变量内容的改变
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	//析构函数
	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}
	//字符的尾插
	void PushBack(char ch) {
		Insert(_size, ch);
	}
	//字符串的尾插
	void Append(const char* str) {
		Insert(_size, str);
	}
	//+= 'ch'的运算符的重载
	String& operator+=(char ch) {
		PushBack(ch);
		return *this;
	}
	//+= ""的运算符重载
	String& operator+=(const char* str) {
		Append(str);
		return *this;
	}
	//字符在任意位置的插入删除
	void Insert(size_t pos, char ch) {
		//此处断言
		assert(pos <= _size);
		//如果相等则要增容
		if (_size == _capacity) {
			Resever(_capacity * 2);
		}
		//实现任意位置的插入删除 字符
		for (int i = _size; i >= pos; --i) {
			_str[i + 1] = _str[i];
		}
		_str[pos] = ch;
		_size++;
	}
	//字符串在任意位置的插入
	void Insert(size_t pos, const char* str) {
		size_t len = strlen(str);
		if (_size + len > _capacity) {
			Resever(_size + len);
		}
		int end = _size;
		while (end >= pos) {
			_str[end + len] = _str[end];
			--end;
		}
		strncpy(_str + pos, str, len);
		_size += len;
	}
	//任意位置的删除
	void Erase(size_t pos=0, size_t len = npos) {
		if (pos+len>=_size) {
			_size = pos;
			_str[_size] = '\0';
		}
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
