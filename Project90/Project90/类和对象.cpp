//#define  _CRT_SECURE_NO_WARNINGS
#include <iostream> 
//#include<stdio.h>
using namespace std;
class Date{
public:
	void SetDate(int year,int month,int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void Display(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main() {
	Date A;
	A.Display();
	A.SetDate(2019,5,7);
	//A.Display();
	system("pause");
	return 0;
}