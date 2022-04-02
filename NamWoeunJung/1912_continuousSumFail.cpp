#include <iostream>
#include <cstring>

using namespace std;

void make_dp(int* arr, int n){
	int i=0, j=0, gap=0;
	int **dp = new int *[n+1];
	int maximum;
	for (int k=0; k<n+1; k++) dp[k] = new int[n+1];
	
	while(!(i == 0 && j == n)){
        //cout << i << " " << j << endl;
        if (i == j) {
            dp[i][j] = arr[i];
			if (i==0 && j==0) maximum = dp[i][j];	
		}
		else{
			dp[i][j] = arr[j] + dp[i][j-1];
		} 
		if (dp[i][j] > maximum) maximum = dp[i][j];
	//	cout << dp[i][j] << endl;
        if (i != n-gap){
            i += 1;
            j = i + gap;
        }
        else{
            i = 0;
            gap += 1;
            j = i+gap;
        }

    }
    dp[0][n] = arr[n] + dp[0][n-1];
	if (dp[0][n] > maximum) maximum = dp[0][n];
	
    cout << maximum;
    for (int k=0; k<n; k++) delete []dp[k];
    
}
int main(void){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i=0; i<n; i++) {
		cin>>arr[i];
	}
	make_dp(arr,n-1);
    delete[] arr;
	return 0;
}
