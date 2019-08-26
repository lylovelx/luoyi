#include <assert.h>
#include<iostream>
using namespace std;
class String {
	typedef char* iterator;
	typedef const char* const_iterator;
	//������
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
	//���캯��
	String(const char* str = "") :_str(nullptr), _capacity(0) {
		_size = strlen(str);
		Reserve(_size);
		strcpy(_str, str);
	}
	//��������
	String(const String& s) :_str(nullptr), _size(0), _capacity(0) {
		//�ִ�д��������һ����ʱ����,����ʱ�������������֮���Զ��ͷſռ�
		//���Ĭ�Ͽ���������ǳ����
		//������ֻ�ܵ��ù��캯��
		String tmp(s._str);
		Swap(tmp);
	}
	//��ֵ��������� =
	String& operator=(String& s) {
		//��ֵ���ص��ִ�д����������ʱ����
		//�����������֮��ԭ������Ŀռ��Զ��ͷ�
		Swap(s);
		return *this;
	}
	//Swap��ʵ��
	void Swap(String& s) {
		//�������ݵĸı�
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	//��������
	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}
	//�ַ���β��
	void PushBack(char ch) {
		Insert(_size, ch);
	}
	//�ַ�����β��
	void Append(const char* str) {
		Insert(_size, str);
	}
	//+= 'ch'�������������
	String& operator+=(char ch) {
		PushBack(ch);
		return *this;
	}
	//+= ""�����������
	String& operator+=(const char* str) {
		Append(str);
		return *this;
	}
	//�ַ�������λ�õĲ���ɾ��
	void Insert(size_t pos, char ch) {
		//�˴�����
		assert(pos <= _size);
		//��������Ҫ����
		if (_size == _capacity) {
			Resever(_capacity * 2);
		}
		//ʵ������λ�õĲ���ɾ�� �ַ�
		for (int i = _size; i >= pos; --i) {
			_str[i + 1] = _str[i];
		}
		_str[pos] = ch;
		_size++;
	}
	//�ַ���������λ�õĲ���
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
	//����λ�õ�ɾ��
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
