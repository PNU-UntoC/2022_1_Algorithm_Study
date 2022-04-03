#include <iostream>
#include <algorithm>

using namespace std;

int map[1010][1010];
int dp[1010][1010][3];

int main() {
    int N, M;
    
    cin >> N >> M;
    
    for(int i = 0; i <= N + 1; i++) {
        for(int j = 0; j <= M + 1; j++) {
            if(i == 0 || j == 0 || i == N + 1 || j == M + 1)
                map[i][j] = 100000;
            else
                cin >> map[i][j];
        
            dp[i][j][0] = 100000;
            dp[i][j][1] = 100000;    
            dp[i][j][2] = 100000;    
        }
    }
    
    for(int i = 1; i <= M; i++) {
        dp[1][i][0] = map[1][i];
        dp[1][i][1] = map[1][i];
        dp[1][i][2] = map[1][i];
    }
    
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + map[i][j];
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + map[i][j];
            dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + map[i][j];
        } 
    }
    
    int minVal = 100000;
    
    for(int i = 1; i <= M; i++) 
        for(int dir = 0; dir < 3; dir++)
            if(minVal > dp[N][i][dir])
                minVal = dp[N][i][dir];
    
    cout << minVal << endl;
    
    return 0;
}
