#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	//×Ö·ûÉıĞòÅÅÁĞ

	//¾ØÕóµÄ×ªÖÃ
	/*int a[4][4] = { { 1, 2, 3, 4 }, { 4, 5, 6, 7 }, { 7, 8, 9, 0 }, { 12, 12, 34, 35 } };
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 4;++i){
		for (int j = 0; j < 4;++j){
			a[j][i] = a[i][j];
		}
	}
	printf("\n");	
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
*/

	/*int a[] = {1,2,3,1,1,1,2,2,2,3,3,3,4,4,4},count1=0,count2=0,count3=0,count4=0;
	int size = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < size;++i){
		if (a[i]==1){
			count1++;
		}
		else if (a[i]==2){
			count2++;
		}
		else if (a[i]==3){
			count3++;
		}
		else{
			count4++;
		}
}
	printf("candidate1:%d\n",count1);
	printf("candidate2:%d\n", count2);
	printf("candidate3:%d\n", count3);
	printf("candidate4:%d\n", count4);
*/

	/*int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, b[10], k = 0, j;
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size - 1; ++i){
		j = i;
		b[k++] = a[j] + a[j + 1];
	}
	for (int i = 0; i < k; ++i){
		printf("%4d", b[i]);
		if ((i + 1) % 3 == 0){
			printf("\n");
		}
	}*/

	/*int a[] = {2,3,4,5};
	int size = sizeof(a) / sizeof(a[0]);
	int left = 0;
	int right = size-1;
	while (left<=right){
	int temp = a[left];
	a[left] = a[right];
	a[right] = temp;
	left++;
	right--;
	}
	for (int i = 0; i < 4;++i){
	printf("%d ",a[i]);
	}*/

	/*char cstring[100];
	int count = 0;
	gets(cstring);
	char* cstring1 = cstring;
	while (*cstring1!=0){
	while (*cstring1 != ' '&&*cstring1!=0){
	cstring1++;
	}
	if (*cstring1==' '){
	cstring1++;
	count++;
	}
	}
	count++;
	printf("%d",count);

	*/

	/*float total = 0;
	for (int i = 1; i <= 5;++i){
	total = (total + 1000) / (1+0.025);
	}
	printf("%f",total);*/

	/*int a = 5;
	int b = 2;
	printf("%f", 5 / 2);*/


	/*int day = 0,sum=1020;
	while (sum){
	sum = sum - (sum / 2 + 2);
	day++;
	}
	printf("%d",day);*/

	/*int c;
	for (int i = 1; i <= 10;++i){
	srand((unsigned int)(time(0))+i);
	printf("%d====%d\n", i, rand()%100);
	}*/

	/*int m,sum,n=1;
	while (n){
	m = n;
	sum = 0;
	for (int i = 1; i < 8; ++i){
	m = m * 2;
	sum = sum + m;
	}
	sum = sum + n;
	if (sum==765){
	printf("%d\n",n);
	printf("%d\n",m);
	break;
	}
	n++;
	}*/

	/*int a[10], s[10] = { 0 }, j = 0, temp3, temp4, k;
	for (int i = 18; i <= 21; ++i){
	temp3 = i*i*i;
	temp4 = i*i*i*i;
	while (temp3 != 0){
	a[j++] = temp3 % 10;
	temp3 = temp3 / 10;
	}
	while (temp4 != 0){
	a[j++] = temp4 % 10;
	temp4 = temp4 / 10;
	}
	for (k = 0; k < 10; ++k){
	s[a[k]]++;
	}
	for (k = 0; k < 10; ++k){
	if (s[k] == 1){
	if (k == 9){
	printf("%d", i);
	}
	}
	else{
	break;
	}
	}
	}*/
	system("pause");
	return 0;
}