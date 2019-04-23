#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* String(char* str){
	int count = 0;
	char* str1 = str;
	while (*str1++ == ' '){
		count++;
	}
	int newlen = strlen(str) + count * 2 + 1;
	char* newstr = (char*)malloc(sizeof(char)*newlen);
	int i = 0;
	while (*str!=0){
		newstr[i++] = *str++;
	}
	newstr[i] = 0;
	return newstr;
}
int main(){
	char  str[] = "we are family";
	printf("%s",String(str));
	system("pause");
	return 0;
}