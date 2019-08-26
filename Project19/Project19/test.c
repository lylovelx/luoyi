#include<stdio.h>
#include<stdlib.h>
int main(){
	int b[4][6] = {2,2,3,2,3,2,3,2,32,3,2,3,3,3,3,3,3,3};
	printf("%p\n",b[1]+1);
	printf("%p",&b[1][1]);
	system("pause");
	return 0;
}