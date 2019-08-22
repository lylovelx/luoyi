#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void spin(char str[], int move, int length){
	for (int i = move; i < length; ++i){
		int move1 = i;
		while (move1 != (i - move)){
			char temp = ' ';
			temp = *(str + move1);
			*(str + move1) = *(str + move1 - 1);
			*(str + move1 - 1) = temp;
			move1--;

		}

	}

}
int main(){
	int move = 0;
	char str[] = "abcdefg";
	int length = strlen(str);
	scanf("%d", &move);
	spin(str, move, length);
	printf("%s", str);
	system("pause");
	return 0;
}
