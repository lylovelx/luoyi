#pragma once
#include<iostream>
using namespace std;
class Date{
public:
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;

	}

	int GetDays(int year, int month){
		int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if ((month == 2) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)){
			int months[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			return 29;
		}
		return months[month];

	}

	//构造函数
	Date(int year = 1900, int month = 1, int day = 1){
		if (year >= 1900 && month<13 && month>0 && day>0 && day <= GetDays(year, month)){
			_year = year;
			_month = month;
			_day = day;
		}
	}

	//拷贝构造函数
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	Date operator+(int days) {
		Date ret(*this);
		if (ret._day + days > GetDays(ret._year, ret._month)){
			while (ret._day + days > GetDays(ret._year, ret._month)){
				days = ret._day + days - GetDays(ret._year, ret._month);
				ret._day = 0;
				ret._month++;
				if (ret._month > 12){
					ret._month = 1;
					ret._year++;
				}
			}
			ret._day += days;
		}
		else{
			ret._day += days;
		}
		return  ret;
	}

	Date operator-(int days){
		Date ret(*this);
		if (ret._day - days <= 0){
			while (ret._day - days <= 0){
				ret._month--;
				if (ret._month<1){
					ret._month = 12;
					ret._year--;
				}
				days = days - ret._day;
				ret._day = GetDays(ret._year, ret._month);
			}
			ret._day -= days;
		}
		else{
			ret._day -= days;
		}
		return ret;
	}

	int operator-(const Date& d){

		int i = 0;
		
		if (*this>d){
			
			Date ret(d);
			while (ret + i < *this){
				++i;
			}
		}
		else{
		
			while (*this + i<d){
				i++;
				
			}
		}
		
		return i;
	}
	//前置++
	Date& operator++(){

		if (_day + 1>GetDays(_year, _month)){
			_day = 1;
			_month++;
			if (_month>12){
				_month = 1;
				_year++;
			}
		}
		else{
			_day = _day + 1;
		}
		return *this;
	}
	//后置++
	Date operator++(int){
		Date ret(*this);
		if (_day + 1>GetDays(_year, _month)){
			_day = 1;
			_month++;
			if (_month>12){
				_month = 1;
				_year++;
			}

		}
		else{
			_day += 1;
		}
		return ret;
	}

	//前置--
	Date& operator--(){
		if (_day - 1 <= 0){
			_month--;
			if (_month<1){
				_month = 12;
				_year--;
			}
			_day = GetDays(_year, _month);

		}
		else{
			_day -= 1;
		}
		return *this;
	}
	//后置--
	Date operator--(int){
		Date ret(*this);
		if (_day - 1 <= 0){
			_month--;
			if (_month<1){
				_month = 12;
				_year--;
			}
			_day = GetDays(_year, _month);

		}
		else{
			_day -= 1;
		}
		return ret;
	}

	bool operator==(const Date& d) const{

		return _year == d._year&&_month == d._month&&_day == d._day;

	}

	bool operator!=(const Date& d) const{
		if (_year != d._year){
			return true;
		}
		else if (_year == d._year){
			if (_month != d._month){
				return true;
			}
			else if (_month == d._month){
				if (_day != d._day){
					return true;
				}
			}
		}
		return false;
	}

	bool operator<=(const Date& d) const{
		return _year <= d._year&&_month <= d._month&&_day <= d._day;
	}

	bool operator>=(const Date& d) const{
		return _year >= d._year&&_month >= d._month&&_day >= d._day;
	}

	bool operator<(const Date& d) const{
		if (_year<d._year){
			return true;
		}
		else if (_year == d._year){
			if (_month<d._month){
				return true;
			}
			else if (_month == d._month){
				if (_day<d._day){
					return true;
				}
			}
		}
		return false;
	}

	bool operator>(const Date& d) const{
		if (_year>d._year){
			return true;
		}
		else if (_year == d._year){
			if (_month>d._month){
				return true;
			}
			else if (_month == d._month){
				if (_day>d._day){
					return true;
				}
			}
		}
	    return false;
	}

private:
	int _year;
	int _month;
	int _day;

};
