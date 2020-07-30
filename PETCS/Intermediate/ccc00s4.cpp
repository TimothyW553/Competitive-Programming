#include <bits/stdc++.h>
using namespace std;
const int MAX = 5285;
int dist, N, dp[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    memset(dp, 9999, sizeof(dp));
    cin >> dist >> N;
    dp[0] = 0;
    for(int i = 0, m; i < N; i++) {
        cin >> m;
        for(int j = m; j < MAX; j++) {
            dp[j] = min(dp[j], dp[j-m]+1);
        }
    }
    if(dp[dist] < 9999) {
        cout << "Roberta wins in " << dp[dist] << " strokes." << "\n";
    } else {
        cout << "Roberta acknowledges defeat." << "\n";
    }
    return 0;
}
