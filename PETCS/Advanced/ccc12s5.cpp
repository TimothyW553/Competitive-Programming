#include <bits/stdc++.h>
using namespace std;
const int MAX = 30;
int R, C, K, dp[MAX][MAX]; bool cat[MAX][MAX]; 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> R >> C >> K;
    for(int i = 0, r, c; i < K; i++) {
        cin >> r >> c;
        cat[r][c] = true;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(cat[i][j] or (i == 1 and j == 1)) {
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[R][C] << "\n";
    return 0;
}
