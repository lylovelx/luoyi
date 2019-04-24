#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* String(char* str){
	int count = 0;
	char* str1 = str;
	while (*str1++ !=0){
		if (*str1==' '){
			count++;
		}
	}
	int length = strlen(str);
	int newlen = strlen(str) + count * 2 + 1;
	char* newstr = (char*)malloc(sizeof(char)*newlen);
	int i = 0;
	while (*str!=0){
		newstr[i++] = *str++;
	}
	newstr[i] = 0;
	int p1 = length;
	int p2 = newlen-1;
	while (p1!=-1){
		if (newstr[p1]==' '){
			newstr[p2--] = '0';
			newstr[p2--] = '2';
			newstr[p2--] = '%';
			//p1--;
		}
		newstr[p2] = newstr[p1];
		p2--;
		p1--;
	}
	return newstr;
}
int main(){
	char  str[] = "we are family";
	printf("%s",String(str));
	system("pause");
	return 0;
}