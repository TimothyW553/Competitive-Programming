#include <bits/stdc++.h>
using namespace std;
const int MM = 256;
int N, M, dp[MM][MM];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> K;
    for(int i = 0; i <= N; i++) { 
        dp[i][1] = 1; // if we only have 1 person with any amount of pies we can only split it 1 way
    }
    for(int i = 2; i <= N; i++) {
        for(int j = i; j <= K; j++) {
            dp[i][j] = dp[i-1][j-1];
            if(x-y >= 0) {
                dp[i][j] += dp[i-j][j];
            }
        }
    }
    cout << dp[N][K] << "\n";
    return 0;
}