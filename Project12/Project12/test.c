#include<stdio.h>
void Func(int* b){
	*b = 1;
}
int main(){
	int a = 10;
	Func(&a);
	printf("%d",a);
	return 0;
}