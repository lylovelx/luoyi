#include<stdio.h>
#include<string.h>
int main(){
	int length,sum = 0;
	int a = 0, b = 0, c = 0, d = 0;
	int score1, score2, score3, score4, score5;
	char password1[100];
	char* password = password1;
	scanf("%s", password);
	length = strlen(password);
	if (length <= 4){
		score1 = 5;
	}
	else if (length >= 5 && length <= 7){
		score1 = 10;
	}
	else{
		score1 = 25;
	}
	while (*password != 0){
		if (*password >= 65 && *password <= 90){
			a++;
		}
		if (*password >= 97 && *password <= 122){
			b++;
		}
		password++;
	}
	if ((a == 0 && b != 0) || (b == 0 && a != 0)){
		score2 = 10;
	}
	else if (a == 0 && b == 0){
		score2 = 0;
	}
	else{
		score2 = 20;
	}
	while (*password != 0){
		if (*password >= 48 && *password <= 57){
			c++;
		}
		password++;
	}
	if (c == 0){
		score3 = 0;
	}
	else if (c == 1){
		score3 = 10;
	}
	else{
		score3 = 20;
	}
	while (*password != 0){
		if (*password >= 32 && *password <= 47){
			d++;
		}
		++password;
	}
	if (d == 0){
		score4 = 0;
	}
	else if (d == 1){
		score4 = 10;
	}
	else{
		score4 = 25;
	}
	if (score2 >= 10 && score3 >= 10){
		score5 = 2;
	}
	else if (score2 >= 10 && score3 >= 10 && score4 >= 10){
		score5 = 3;
	}
	else if (score2 >= 20 && score3 >= 10 && score4 >= 10){
		score5 = 5;
	}
	sum = score1 + score2 + score3 + score4 + score5;
	if (sum >= 90){
		printf("VERY_SECURE");
	}
	else if (sum >= 80 && sum<90){
		printf("SECURE");
	}
	else if (sum >= 70 && sum<80){
		printf("VERY_STRONG");
	}
	else if (sum >= 60 && sum<70){
		printf("STRONG");
	}
	else if (sum >= 50 && sum<60){
		printf("AVERAGE");
	}
	else if (sum >= 25 && sum<50){
		printf("WEAK");
	}
	else if (sum >= 0 && sum<25){
		printf("VERY_WEAK");
	}
	return 0;
}
#include<stdio.h>
struct A{
	int a ;
	int b ;
	int c ;
	int d ;
	int s ;
}a = {0xaa,0xaa,0xaa,0x44,0xaa};
int main(){
	struct A a;
	system("pause");
	return 0;
}