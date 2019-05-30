#include<iostream>

using namespace std;
class UnusualAdd {
public:
	UnusualAdd(int n=0){
		if (i<n){
			i++;
		}
	}
	int addAB(int A, int B) {
		UnusualAdd ret(A);
		return i;
	}
private:
	static int i;
};
int UnusualAdd::i = 0;
int main(){
	UnusualAdd a;
	a.addAB(2, 3);
	cout << UnusualAdd::i << endl;
	system("pause");
	return 0;
}