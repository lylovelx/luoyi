
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int numDecodings(char * s){
	//1. 如果s[n] == '0' && s[n-1] == '0': dp[n] = 0;  // 当前的字符'0'无法解码
	//2. 如果s[n] == '0' && s[n-1] != '0' && num <= 26: dp[n] = dp[n-2];  // 当前的字符'0'必须得和上一个字符一起解码
	//3. 如果s[n] == '0' && s[n-1] != '0' && num > 26: dp[n] = 0;  // 当前字符'0'无法解码
	//4. 如果s[n] != '0' && s[n-1] == '0': dp[n] = dp[n-1];  // 当前字符必须单独解码
	//5. 如果s[n] != '0' && s[n-1] != '0' && num <= 26: dp[n] = dp[n-2] + dp[n-1]; // 当前字符可以单独解码也可以和前一个字符一起解码
	//6. 否则：dp[n] = dp[n-1];  // 当前字符和前一个字符形成的数字大于26，必须单独解码
	int dp[10000], n = strlen(s);
	dp[0] = s[0] = '0' ? 0 : 1;
	if (n == 1) return dp[0];
	if (s[1] == '0' && ((s[0] - '0') * 10 + s[1] - '0'>26)){
		return 0;
	}
	else{
		dp[1] = 2;
	}
	for (int i = 2; i<strlen(s); ++i){
		if (s[i] == '0'&&s[i - 1] == '0'){
			return 0;
		}
		if (s[i] == '0' && ((s[0] - '0') * 10 + s[1] - '0'>26)){
			return 0;
		}
		else if (s[i] == '0' && ((s[0] - '0') * 10 + s[1] - '0' <= 26)){
			dp[i] = dp[i - 2];
		}
		if (s[i] != '0'&&s[i - 1] == '0'){
			dp[i] = dp[i - 1];
		}
		if (s[i] != '0'&&s[i - 1] != '0' && ((s[0] - '0') * 10 + s[1] - '0' <= 26)){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	return dp[n - 1];
}




int main(){

	char str[] = "226";
	printf("%d", numDecodings(str));
	system("pause");
	return 0;
}
