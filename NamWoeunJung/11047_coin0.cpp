#include <iostream>

using namespace std;

int main(void){
	int n,k,coin[10];
	int coin_num=0;
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >>  coin[i];
	}
	for (int i=n-1; i>=0; i--){
		while (coin[i] <= k){
			k -= coin[i];
			coin_num++;
		}
	}
	cout << coin_num;
	
	
	return 0;
}
