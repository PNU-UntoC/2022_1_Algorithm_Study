#include <bits/stdc++.h>
using namespace std;

int r, c, t, dirCnt, nx, ny, hand, ans;
int a[60][60];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
pair<int, int> ap[2]; // Air purifier

bool isCanVis(int x, int y) {
    if(0 < x && x <= r && 0 < y && y <= c) return true;
    return false;
}

void airCircle(int x, int y, int dir, bool reverse) {
    if(a[x][y] == -1) {
        hand = 0;
        return;
    }
    swap(hand, a[x][y]);
    nx = x + dx[dir];
    ny = y + dy[dir];
    if(!isCanVis(nx, ny)) {
        dir = reverse ? (dir+3)%4 : (dir+1)%4;
        nx = x + dx[dir];
        ny = y + dy[dir];
    }
    airCircle(nx, ny, dir, reverse);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> r >> c >> t;
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) {
                if(!ap[0].first) {
                    ap[0].first = i;
                    ap[0].second = j;
                }else {
                    ap[1].first = i;
                    ap[1].second = j;
                }
            }
        }
    }

    while(t--) {
        int b[60][60] = {0, };
        b[ap[0].first][ap[0].second] = -1;
        b[ap[1].first][ap[1].second] = -1;
        for(int i=1 ; i<=r ; i++) {
            for(int j=1 ; j<=c ; j++) {
                if(a[i][j] <= 0) continue;
                dirCnt = 0;
                for(int dir=0 ; dir<4 ; dir++) {
                    nx = i + dx[dir];
                    ny = j + dy[dir];
                    if(!isCanVis(nx, ny) || a[nx][ny] == -1) continue;
                    dirCnt++;
                }
                for(int dir=0 ; dir<4 ; dir++) {
                    nx = i + dx[dir];
                    ny = j + dy[dir];
                    if(!isCanVis(nx, ny) || a[nx][ny] == -1) continue;
                    b[nx][ny] += a[i][j]/5;
                }
                b[i][j] += a[i][j] - ((a[i][j]/5) * dirCnt);
            }
        }
        for(int i=1 ; i<=r ; i++)
            for(int j=1 ; j<=c ; j++)
                a[i][j] = b[i][j];

        airCircle(ap[0].first, ap[0].second + 1, 0, false);
        airCircle(ap[1].first, ap[1].second + 1, 0, true);
    }

    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            if(a[i][j] == -1) continue;
            ans += a[i][j];
        }
    }

    cout << ans;
}
