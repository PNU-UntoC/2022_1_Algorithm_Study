#include <iostream>
#include <cstring>

using namespace std;
int dp[1001][1001] = {0,};

int main(void){
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int str1_len = str1.length();
	int str2_len = str2.length();
	
	
	for (int i=0; i<str1_len+1; i++){
		for (int j=0; j<str2_len+1; j++){
			if (i==0 || j==0) dp[i][j] = 0;
			else{
				if (str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
			}
		}
	}
	cout << dp[str1_len][str2_len];
	
	
	return 0;
}
