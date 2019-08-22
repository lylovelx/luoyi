#include<iostream>
#include<string>
using namespace std;
//int main(){
//	int W, H, Y;
//	cin >> W >> H;
//	if (W % 4 == 0 || H % 4 == 0){
//		Y = W*H / 2;
//	}
//	else if (W % 2 == 0 && H % 2 == 0){
//		Y = (W*H / 4 + 1) * 2;
//	}
//	else{
//		Y = W*H / 2 + 1;
//	}
//	return 0;
//}
int StrToInt(string str) {
	if (str.c_str() == NULL){
		return 0;
	}
	int count = 0;
	for (int i = 0; i < str.size(); ++i){
		if (i == 0 && (str[i] == '+' || str[i] == '-')){
			if (str.size() == 1){
				return 0;
			}
			else{
				count = 1;
				continue;
			}

		}
		if (count == 1 && (str[i]<'0' || str[i]>'9')){
			return 0;
		}
		if (count == 1 && str[1] == '0'){
			return 0;
		}
		if (str[0] == '0'&&str.size() != 1){
			return 0;
		}
		if (count == 0 && (str[i]<'0' || str[i]>'9')){
			return 0;
		}
	}
	int sum = 0;
	int x = '1' - 1;
	if (str[0] == '+'){
		for (int i = 1; i < str.size(); ++i){
			sum = sum + (str[i] - x)*pow(10, str.size() - i - 1);
		}
		return sum;
	}
	else if (str[0] == '-'){
		for (int i = 1; i < str.size(); ++i){
			sum = sum + (str[i] - x)*pow(10, str.size() - i - 1);
		}
		return -sum;
	}
	else{
		for (int i = 0; i < str.size(); ++i){
			sum = sum + (str[i] - x)*pow(10, str.size() - i - 1);
		}
		return sum;
	}
}
int main(){
	cout << StrToInt("0123") << endl;
	system("pause");
	return 0;
}