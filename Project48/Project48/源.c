#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Max 11
#define N 8
int hashtable[Max];
//int leap(int a){
//
//	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0){
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int numble(int year, int month, int day){
//	int sum = 0;
//	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (year){
//		for (int i = 0; i < month-1;++i){
//			sum += a[i];
//		}
//		sum += day;
//		return sum;
//	}
//	else{
//		for (int j = 0; j < month - 1;++j){
//			sum += b[j];
//		}
//		sum += day;
//		return sum;
//	}
//}
//int leap(int year){
//	if (year%4==0&&year%100!=0||year%400==0){
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
//int numble(int year,int month,int day){
//	int sum = 0;
//		int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (leap(year)==1){
//			for (int i = 0; i < month-1;++i){
//				sum += b[i];
//			}
//			sum += day;
//		}
//		else{
//			for (int j = 0; j < month - 1;++j){
//				sum += a[j];
//			}
//			sum += day;
//		}
//		for (int i = 2011; i < year;++i){
//			if (leap(year)){
//				sum += 365;
//			}
//			else{
//				sum += 355;
//			}
//		}
//		return sum;
//}
//int func(int value){
//	return value%Max;
//}
//int search(int key){
//	int pos, t;
//	pos = func(key);
//	t = pos;
//	while (hashtable[t] != key&&hashtable[t] != -1){
//		t = (t + 1) % Max;
//		if (pos == t){
//			return -1;
//		}
//	}
//	if (hashtable[t] == -1){
//		return NULL;
//	}
//	else{
//
//		return t;
//	}
//}
//void creathash(int key){
//	int pos, t;
//	pos = func(key);
//	t = pos;
//	while (hashtable[t]!= -1){ 
//		t = (t + 1) % Max;
//		if (pos == t){
//			printf("��ϣ������\n");
//			return;
//		}
//
//	}
//	hashtable[t] = key;
//}
//int func(n){
//	if (n==1||n==2){
//		return 1;
//	}
//	return func(n - 1) + func(n - 2);
//}

//int ss(int i){
//	if (i<=1){
//		return 0;
//	}
//	if (i==2){
//		return 1;
//	}
//	for (int j = 2; j < i;++j){
//		if (i%j==0){
//			return 0;
//		}
//		else if (i!=j+1){
//			continue;
//		}
//		else{
//			return 1;
//		}
//	}
//}

int main(){
	int a[32], b[4], n = 1, j = 0;
	for (int i = 1; i <= 32; i++){
		scanf("%d", a[i]);
	}
	for (int i = 32; i >= 1; --i, n++){
		b[j] = b[j] + a[i] * pow(2, 32 - i);
		while (n % 8 == 0){
			j++;
			break;
		}
	}
	for (int j = 4; j >0; --j){
		printf("%d.", b[j]);
	}



	////��ʦ���ǹ�
	//int n;
	//float sum1, sum2;
	//for (n = 11;;n++){
	//	sum1 = (n + 9) / 10.0;
	//	sum2 = (9 * n + 171) / 100.0;
	//	if (sum1!=(int)sum1){
	//		continue;
	//	}

	//	if (sum2!=(int)sum2){
	//		continue;
	//	}
	//	if (sum1==sum2){
	//		break;
	//	}
	//}
	//printf("����%d��ѧ��\n,���ǹ��ֳ���%d��",(int)(n/sum1),n);



	////�ɷ�ƻ��
	//int x[7], y[7], s;
	//s = 2520 / 6;
	//for (int i = 2; i <= 6;++i){
	//	y[i] = s*(9 - i) / (8-i);
	//	y[1] = x[1] = (s - y[6] / 3) * 8 / 7;
	//}
	//for (int i = 2; i <= 6;++i){
	//	x[i] = y[i] - y[i - 1] / (10 - i);
	//}
	//for (int i = 1; i <= 6;++i){
	//	printf("x[%d]=%d\n",i,x[i]);
	//}

	//С������
	/*double h = 100,s=100;
	int time = 1;
	while (time!=10){
	h = h / 2;
	s =2*h + s;
	time++;
	}
	s = s + h;
	printf("%lf %lf",s,h/2);*/

	////n����ת��Ϊ10����
	//long t1;
	//int i, n, t, t3;
	//char a[100];
	//printf("���������֣�\n");
	//gets(a);
	//strupr(a);
	//t3 = strlen(a);
	//t1 = 0;
	//printf("���������n(2��8��16): \n");
	//scanf("%d",&n);
	//for (int i = 0; i < t3;++i){
	//	if (a[i]-'0'>n||a[i]-'A'+10>=n){
	//		printf("��������");
	//		exit(0);
	//	}
	//	if (a[i]>='0'&&a[i]<='9'){
	//		t = a[i] - '0';
	//	}
	//	else if (n>=11&&(a[i]>='A'&&a[i]<='A'+n-10)){
	//		t = a[i] - 'A' + 10;
	//	}
	//	else{
	//		t1 = t1*n + t;
	//	}
	//}
	//printf("%ld",t1);


	//��Ƴ�˹����
	/*int i, j, n, m;
	int a[16] = { 0 };
	system("cls");
	scanf("%d",&n);
	for ( m = 0; m < 15;m++){
	i=n % 2;
	n = n / 2;
	a[m] = i;
	}
	for (m = 15; m >= 0;--m){
	printf("%d",a[m]);
	if (m%4==0){
	printf(" ");
	}
	}*/


	//	//��°ͺղ���
	//	nt j,flag1,flag2,n=0;
	//	for (int i = 30; i < 100;i+=2){
	//		for (int k = 2; k <=i/2;k++){
	//			j = i - k;
	//			flag1 = ss(k);
	//			if (flag1){
	//				flag2 = ss(j);
	//				if (flag2){
	//					printf("%3d=%3d+%3d,",i,j,k);
	//					n++;
	//					if (n%5==0){
	//						printf("\n");
	//					}
	//				}
	//			}
	//		}
	//	}
	//
	//	printf("\n");
	//

	//쳲���������
	/*int n = 30;
	printf("%d",func(n));*/

	//��ϣ����
	/*int flag[50], i, t;
	for (i = 0; i < Max; ++i){
	hashtable[i] = -1;
	}
	for (i = 0; i < 50; ++i){
	flag[i] = 0;
	}
	srand((unsigned long)time(0));
	i = 0;
	while (i != N){
	t = rand() % 50;
	if (flag[t] == 0){
	creathash(t);
	printf("%2d:", t);
	for (int j = 0; j < Max; ++j){
	printf("(%2d)", hashtable[j]);
	}
	printf("\n");
	flag[t] = 1;
	}
	i++;
	}
	printf("������������ҵ�Ԫ�أ�");
	scanf("%d", &t);
	if (t>0 && t<50){
	i = search(t);
	if (i != -1){
	printf("���ҳɹ�����λ���ǣ�%d\n", i);
	}
	else{
	printf("����ʧ�ܣ�");
	}
	}
	else{
	printf("��������");
	}*/
	//int a[11];
	//printf("������10�����ݣ���\n");
	//for (int i = 1; i <= 10;++i){
	//	scanf("%d",a[i]);
	//}
	//for (int i = 1; i < 11;++i){
	//	printf("%5d",a[i]);
	//}
	//insort(a,10);


	//float  a, b, c, s, area;
	//scanf("%d %d %d", &a, &b, &c);
	//if ((a + c) > b && (a + b) > c && (b + c) > a){
	//	//������Ҫ�õ������ĺ��׹�ʽ
	//	s = (a + b + c) / 2;
	//	area = (float)sqrt(s*(s - a)*(s - b)*(s - c));
	//	printf("����ǣ�%f\n", area);
	//	if (a == b&b == c){
	//		printf("�ȱ�������");
	//	}
	//	else if (a == b || a == c || b == c){
	//		printf("����������");
	//	}
	//	else if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (c*c + b*b == a*a)){
	//		printf("ֱ��������");
	//	}
	//	else{
	//		printf("��ͨ������");
	//	}
	//}
	//else{
	//	printf("���ܹ���������");
	//}

	////����ɹ������
	//int year, month, day,n;
	//scanf("%d%d%d",&year,&month,&day);
	//   n = numble(year,month,day);
	//if ((n%5)<4&&(n%5)>0){
	//	printf("����");
	//}
	//else{
	//	printf("ɹ��");
	//}

	/*int cock, hen, chick;
	for (cock = 0; cock <= 20;++cock){
	for (hen = 0; hen <= 33;++hen){
	for (chick = 3; chick <= 99;++chick){
	if ((5*cock+3*hen+chick/3)==100){
	if ((cock+hen+chick)==100){
	if (chick % 3 == 0){
	printf("������%d ĸ����%d ������%d\n", cock, hen, chick);
	}
	}
	}
	}
	}
	}
	*/

	//�����ϵĻ���
	/*int a, b, c;
	for (int a = 1; a <= 3; ++a){
	for (int b = 1; b <= 3; ++b){
	for (int c = 1; c <= 3; ++c){
	if (a != 1 && c != 1 && c != 3 && a != b&&a != c&&b != c){
	printf("%c���޸���A\n", 'X' + a - 1);
	printf("%c���޸���B\n", 'X' + b - 1);
	printf("%c���޸���C\n", 'X' + c - 1);
	}
	}
	}
	}*/

	/*int year, month, day, n;
	scanf("%d %d %d", &year, &month, &day);
	n = numble(year, month, day);
	printf("%d", n);*/
	system("pause");
	return 0;
}