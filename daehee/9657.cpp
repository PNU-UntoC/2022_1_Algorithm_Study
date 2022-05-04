#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1010100];

int f(int k) {
    if(k == 2) return 0;
    if(k == 1 || k == 3 || k == 4 || dp[k]) return 1;
    return dp[k] = !(f(k-1) && f(k-3) && f(k-4));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    if(f(n)) cout << "SK";
    else cout << "CY";
}
