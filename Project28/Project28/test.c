#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[100], n;
void quicksort(int left, int right){
	if (left>right){
		return;
	}
	int i, j, t, temp;//基准数
	temp = a[left];
	i = left;
	j = right;
	while (i != j){
		while (a[j] >= temp&&i<j){
			j--;
		}
		while (a[i] <= temp&&i<j){
			i++;
		}
		if (i<j){
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}
	//将基准数归位
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);//因为后面步骤一样，所以这里采用递归的思想
	quicksort(i + 1, right);//同理
}abc
int lengthOfLongestSubstring(char* s) {
	int sum = 1;
	int n = strlen(s);
	for (int i = 0; i<n - 1; ++i){
		int length = 1,sum1=0,a=0;
		for (int j = i + 1; j<n; ++j){
			length = 1;
			for (int x = i; x<j; ++x){
				if (s[j] != s[x]){                  // abcddartuj
					length++;
				}
				else{
					a = 1;
					break;
				}
				
			}
			if (a == 1){
				break;
			}
			if (sum1<length){
				sum1 = length;
			}
			
		}
		if (sum<sum1){
			sum = sum1;
		}
	}
	return sum;
}
char* longestPalindrome(char* s) {
	int size = 0;
	char p[1000] = { 0 };
	for (size = 0;; size++){
		if (s[size] == 0){
			break;
		}
	}
		
		for (int i = 0; i<size; ++i){
			int a = i, b = i, sum11 = 0, sum22 = 0, sum3 = 0, sum33 = 0;
			int x1, x2, x3;
			if (s[a] == s[b + 1]){
				int sum1 = 2;
				while (s[a - 1] == s[b + 2]){
					a--;
					b++;
					sum1 += 2;
					x1 = a;
				}
				if (sum1>sum11){
					sum11 = sum1;
				}

			}
			else if (s[b] == s[a - 1]){
				int sum2 = 2;
				while (s[a - 2] == s[b + 1]){
					a--;
					b++;
					sum2 += 2;
					x2 = a;
				}
				if (sum2>sum22){
					sum22 = sum2;
				}
			}
			while (s[a - 1] == s[b + 1]){
				a--;
				b++;
				sum3 += 2;

			}


		}


	}





char* longestPalindrome(char* s) {
	int size = 0;
	char p[1000] = { 0 };
	for (size = 0;; size++){
		if (s[size] == 0){
			break;
		}
	}
	for (int i = 0; i<size; ++i){
		int a = i, b = i, sum11 = 0, sum22 = 0, sum33 = 0;
		int x1, x2, x3;
		if (s[a] == s[b + 1]){
			int sum1 = 2;
			while (s[a - 1] == s[b + 2]){
				a--;
				b++;
				sum1 += 2;
				x1 = a;
			}
			if (sum1>sum11){
				sum11 = sum1;
			}

		}
		else if (s[b] == s[a - 1]){
			int sum2 = 2;
			while (s[a - 2] == s[b + 1]){
				a--;
				b++;
				sum2 += 2;
				x2 = a;
			}
			if (sum2>sum22){
				sum22 = sum2;
			}
		}
		if (s[a - 1] == s[b + 1]){
			int sum3 = 1;
			while (s[a - 1] == s[b + 1]){
				a--;
				b++;
				sum3 += 2;
				x3 = a;
			}
			if (sum3>sum33){
				sum33 = sum3;
			}
		}
		if (sum11>sum22&sum11>sum33){
			for (int i = 0; i<sum11; ++i){
				p[i] = s[x1];
				x1++;
			}
			return p;
		}
		else if (sum22>sum11&&sum22>sum33){
			for (int i = 0; i<sum22; ++i){
				p[i] = s[x2];
				x2++;
			}
			return p;
		}
		else{
			for (int i = 0; i<sum33; ++i){
				p[i] = s[x3];
				x3++;
			}
			return p;
		}
	}
	return 0;
}

char p[1000] = { 0 };
char* longestPalindrome(char* s) {

	int size = strlen(s);
	for (int i = 0; i<size; ++i){
		int a = i, b = i, sum11 = 0,sum33 = 0;
		int x1, x2, x3;
		if (s[a] == s[b + 1]){
			int sum1 = 2;
			while (s[a - 1] == s[b + 2]){
				a--;
				b++;
				sum1 += 2;
				x1 = a;
			}
			if (sum1>sum11){
				sum11 = sum1;
			}
		}
		if (s[a - 1] == s[b + 1] && (i >= 1 && i<size - 1)){
			int sum3 = 1;
			while (s[a - 1] == s[b + 1]){
				a--;
				b++;
				sum3 += 2;
				x3 = a;
			}
			if (sum3>sum33){
				sum33 = sum3;
			}
		}
		if (sum11>sum33){
			for (int i = 0; i<sum11; ++i){
				p[i] = s[x1];
				x1++;
			}
			return p;
		}
		else if(sum33>sum11){
			for (int i = 0; i<sum33; ++i){
				p[i] = s[x3];
				x3++;
			}
			return p;
		}
	}
	return 0;
}

int main(){
	char s[] = "aba";
	char* p = longestPalindrome(s);
	printf("%s",p);
	printf("%d", lengthOfLongestSubstring(s));*/
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	quicksort(0, n - 1);-

	for (int j = 0; j < n; ++j){
		printf("%d ", a[j]);
	}
	int a[] = { 1, 23, 43, 54, 65, 32 };
	for (int i = 1; i < 6;++i){
		for (int j = 0; j < i;++j){
			if (a[i]<a[j]){
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < 6;++i){
		printf("%d  ",a[i]);

	}
	system("pause");
	return 0;
}
int* twoSum(int* nums, int numsSize, int target) {
	int a[2] = { 0 };
	for (int i = 0; i<numsSize - 1; ++i){
		for (int j = i + 1; j<numsSize; ++j){
			if (nums[i] + nums[j] == target){
				a[0] = i;
				a[1] = j;
				return a;
			}
		}
	}
	return 0;
}


