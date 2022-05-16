#include <bits/stdc++.h>
using namespace std;

void solve();
bool cmp(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    vector<int> v;
    int n, ans = 0;
    bool flag = false;

    while(!flag) {
        cin >> n;
        if(n == 0) flag = true;
        v.push_back(n);
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0 ; i<v.size() ; i++) {
        int value = 1;
        for(int y=0 ; y<=i ; y++) value *= v[i];
        ans += value * 2;
        if(ans > 5000000) {
            cout << "Too expensive\n";
            return;
        }
    }
    
    cout << ans << "\n";
}
