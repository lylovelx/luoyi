#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){

	/*char str[] = "asasdio";
	int flag = 3;
	int length = strlen(str);
	while (flag != 0){

	char temp = str[length - 1];
	for (int i = length - 2; i >= 0; --i){
	str[i + 1] = str[i];
	}
	str[0] = temp;
	flag--;
	}

	printf("%s", str);*/

	/*char a[] = "123";
	int length = strlen(a);
	int temp = '5';
	int x = '5' - 5;
	int flag = 0;
	int j = 0;
	for (int i = length - 1; i >= 0; --i){
		flag = flag + (a[i] - x)*pow(10, j);
		j++;
	}
	printf("%d",flag);*/
	int a[100];
	a[0] = a[1] = 1;
	for (int i = 2; i <= 10;++i){
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%d",a[10]);
	system("pause");
	return 0;

}