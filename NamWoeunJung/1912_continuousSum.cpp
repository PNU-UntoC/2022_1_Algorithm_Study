#include <iostream>
#include <cstring>

using namespace std;

void make_dp(int* arr, int n){
	int *dp = new int [n];
	dp[0] = arr[0];
	int maximum = dp[0];
	
	for (int i=1; i<n; i++){
		dp[i] = max(arr[i], arr[i]+dp[i-1]);
		maximum = max(maximum, dp[i]);
	}
	
    cout << maximum;
    delete[] dp;
    
}
int main(void){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i=0; i<n; i++) {
		cin>>arr[i];
	}
	make_dp(arr,n);
    delete[] arr;
	return 0;
}
