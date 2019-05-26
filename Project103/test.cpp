//#include<iostream>
//using namespace std;
//class A{
//	 friend void fun(int s){
//
//	}
//public:
//	A(int a=10){
//		
//		printf("sssssss\n");
//	}
//};
//int main(){
//	/*for (int i = 0; i < 5;++i){
//		A::fun(2);
//	}*/
//	int a = 1;
//	int x = a++;
//	cout << x << endl;
//	cout << x << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<vector>
#include<string>
#include<stack>
//using namespace std;
//int main(){
//	int N;
//	cin >> N;
//	int array[100];
//	array[0] = 0;
//	array[1] = 1;
//	//o(1) 空间复杂度 o(1) 时间复杂度
//	for (int i = 2; i<100; ++i){
//		array[i] = array[i - 1] + array[i - 2];
//	}
//	int left = N;
//	int right = N;
//	int LeftStep = 0;
//	int RightStep = 0;
//	int flag1 = 0;
//	int flag2 = 0;
//	while (left - LeftStep >= 0){
//		for (int i = 0; i<100; ++i){
//			if (left - LeftStep == array[i]){
//				flag1 = 1;
//				break;
//			}
//		}
//		if (flag1==1){
//			break;
//		}
//		LeftStep++;
//	}
//	while (right + RightStep <= 1000000 && flag2 != 1){
//		for (int i = 0; i<100; ++i){
//			if (right + RightStep == array[i]){
//				flag2 = 1;
//				break;
//			}
//		}
//		if (flag2==1){
//			break;
//		}
//		RightStep++;
//	}
//	if (LeftStep>RightStep){
//		cout << RightStep << endl;
//	}
//	else{
//		cout << LeftStep << endl;
//
//	}
//	system("pause");
//	return 0;
//}
bool chkParenthesis(std::string A, int n) {
	std::stack<char> s;
	for (int i = 0; i<n; ++i){
		s.push(A[i]);
		if (s.top() == ')'){
			s.pop();
			while (s.top() != '('&&s.size()>0){
				s.pop();
			}
			if (s.top() == '('){
				s.pop();
			}
		}
	}
	if (s.empty()){
		return true;
	}
	return false;
}
int main(){
	
	std::string a("()()(()");
	std::cout << chkParenthesis(a, 7) << std::endl;
	system("pause");
	return 0;
}

















