#include<string>
#include<iostream>
using namespace std;
string addStrings(string num1, string num2) {
	int l1 = num1.size();
	int l2 = num2.size();
	int flag = 0;
	if (l1>l2){
		num2.insert(0, l1 - l2, '0');
	}
	else{
		num1.insert(0, l2 - l1, '0');
	}
	int i = num1.size() - 1;
	while (i >= 0){
		if ((num1[i] - '0') + (num2[i] - '0') + flag>9){
			num1[i] = ((num1[i] - '0') + (num2[i] - '0') + flag) % 10 + '0';
			flag = 1;
		}
		else{
			num1[i] = (num1[i] - '0') + (num2[i] - '0') + flag + '0';
			flag = 0;
		}
		i--;
	}
	if (flag == 1){
		num1.insert(0, 1, '1');
	}
	return num1;
}
int main(){
	string a("9");
	string b("99");
	string ret = addStrings(a,b);
	cout << ret << endl;
	system("pause");
	return 0;
}