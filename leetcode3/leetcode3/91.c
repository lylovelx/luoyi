
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int numDecodings(char * s){
	//1. ���s[n] == '0' && s[n-1] == '0': dp[n] = 0;  // ��ǰ���ַ�'0'�޷�����
	//2. ���s[n] == '0' && s[n-1] != '0' && num <= 26: dp[n] = dp[n-2];  // ��ǰ���ַ�'0'����ú���һ���ַ�һ�����
	//3. ���s[n] == '0' && s[n-1] != '0' && num > 26: dp[n] = 0;  // ��ǰ�ַ�'0'�޷�����
	//4. ���s[n] != '0' && s[n-1] == '0': dp[n] = dp[n-1];  // ��ǰ�ַ����뵥������
	//5. ���s[n] != '0' && s[n-1] != '0' && num <= 26: dp[n] = dp[n-2] + dp[n-1]; // ��ǰ�ַ����Ե�������Ҳ���Ժ�ǰһ���ַ�һ�����
	//6. ����dp[n] = dp[n-1];  // ��ǰ�ַ���ǰһ���ַ��γɵ����ִ���26�����뵥������
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
