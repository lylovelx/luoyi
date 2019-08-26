#include<stdio.h>
#include<stdlib.h>
void Grid(int a, int b){
	if (a == 0 || b == 0){
		//∑«∑® ‰»Î
		return;
	}
	if (a<b){
		a = a^b;
		b = a^b;
		a = a^b;
		return;
	}
	while (1){
		int temp = a%b;
		if (a%b == 0){
			printf("%d", b);
			return;
		}
		else{
			a = b;
			b = temp;
		}
	}
}
int main(){
	int a = 0;
	int b = 0;
	scanf_s("%d %d", a, b);
	Grid(a, b);
	system("pause");
	return 0;
}
