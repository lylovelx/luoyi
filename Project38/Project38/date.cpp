#include<iostream>
using namespace std;
//�ж�������
bool sss(int month) {
	if (month == 1) return false;
	for (int i = 2; i <= sqrt(month); ++i) {
		if (month%i == 0) {
			return false;
		}
	}
	return true;
}
//�ж�����
bool Rui(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}
//ÿ�µ�����
int GetMoney(int year, int month) {
	if (Rui(year)) {
		int Month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
		if (sss(month)) {
			return Month[month];
		}
		else {
			return Month[month] * 2;
		}
	}
	else {
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (sss(month)) {
			return Month[month];
		}
		else {
			return Month[month] * 2;
		}
	}
	

}
int main() {
	//��ʼ
	int start_year, start_month, start_day;
	//����
	int end_year, end_month, end_day;
	while (cin >> start_year >> start_month >> start_day >> end_year >> end_month >> end_day) {
		int sum = 0,ret=0;
		//��ʼ
		while (start_year < end_year) {
			for (int month = 1; month <= 12; ++month) {
				sum += GetMoney(start_year, month);
			}
			++start_year;
			ret = 1;
		}
		//���һ��
		if (ret==0) {
			for (int month = start_month; month < end_month; ++month) {
				sum += GetMoney(end_year, month);
			}
		}
		else {
			for (int month = 1; month < end_month; ++month) {
				sum += GetMoney(end_year, month);
			}
		}
		
		if (sss(end_month)) {
			sum += end_day;
		}
		else {
			sum +=end_day * 2;
		}
		cout << sum << endl;
	}
}