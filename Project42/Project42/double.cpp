#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
//��������ŵ�����
long long fault(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	long long first = 0, second = 1, third;
	for (int i = 3; i <= n; ++i) {
		third = (i - 1)*(first + second);
		first = second;
		second = third;
	}
	return third;
}
//����ܵ���������
long long Sum(int n) {
	if (n == 1) return 1;
	long long first = 1, second;
	for (int i = 2; i <= n; ++i) {
		second = i * first;
		first = second;
	}
	return second;
}
int main() {
	int n;
	while (cin >> n) {
		printf("%.2f%%\n", (1.0*fault(n) / Sum(n))*100);
	}
	return 0;
}