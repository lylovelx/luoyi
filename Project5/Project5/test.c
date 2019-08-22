#include<stdio.h>
#include<stdlib.h>
int main(){
	char* c[] = {"work","at","ailbaba","shhi"};
	char** cp[] = {c+3,c+2,c+1,c};
	char** cpp = cp;
	printf("%s\n",**++cpp);
	//printf("%s\n",*--*++cpp+3);
	printf("%s\n",*cpp[-2]+3);
	system("pause");
	return 0;
}