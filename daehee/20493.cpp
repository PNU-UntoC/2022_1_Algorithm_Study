#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, dir, nx, ny;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
ll T, preT, nxtT;
string order;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> T;
    while(n--) {
        cin >> nxtT >> order;
        nx += dx[dir] * (nxtT - preT);
        ny += dy[dir] * (nxtT - preT);
        preT = nxtT;
        if(order == "right") dir += 1;
        if(order == "left") dir += 3;
        dir %= 4;
    }
    nx += dx[dir] * (T - preT);
    ny += dy[dir] * (T - preT);

    cout << nx << " " << ny;
}
