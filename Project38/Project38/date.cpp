#include<iostream>
using namespace std;
//判断素数月
bool sss(int month) {
	if (month == 1) return false;
	for (int i = 2; i <= sqrt(month); ++i) {
		if (month%i == 0) {
			return false;
		}
	}
	return true;
}
//判断瑞年
bool Rui(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}
//每月的利润
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
	//起始
	int start_year, start_month, start_day;
	//结束
	int end_year, end_month, end_day;
	while (cin >> start_year >> start_month >> start_day >> end_year >> end_month >> end_day) {
		int sum = 0,ret=0;
		//起始
		while (start_year < end_year) {
			for (int month = 1; month <= 12; ++month) {
				sum += GetMoney(start_year, month);
			}
			++start_year;
			ret = 1;
		}
		//最后一年
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