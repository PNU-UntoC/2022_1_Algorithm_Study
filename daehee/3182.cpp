#include <bits/stdc++.h>
using namespace std;

int n, ans, maxValue, now;
int nxt[1001];
int value[1001];
bool vis[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> nxt[i];
    for(int i=1 ; i<=n ; i++) {
        now = i;
        while(!vis[i][now]) {
            vis[i][now] = true;
            value[i]++;
            now = nxt[now];
        }
    }

    for(int i=1 ; i<=n ; i++) {
        if(value[i] > maxValue) {
            maxValue = value[i];
            ans = i;
            
        }
    }

    cout << ans;
}
