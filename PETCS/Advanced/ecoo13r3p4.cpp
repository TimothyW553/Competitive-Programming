#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int N, dp[MAX][6]; pair<int, int> p[MAX];
void solve() {
    cin >> N;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 5; j++) {
            if(j < 5) { //continue to win if less than 5 cards, 5th card must lose
                dp[i][j] = max(p[i].first + p[i].second + dp[i-1][j-1], dp[i][j]);
            } //lose here, streak ends, thus 0
            dp[i][0] = max(p[i].first-1 + dp[i-1][j-1], dp[i][0]);
        }
    }
    cout << *max_element(dp[N], dp[N]+6) << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    for(int i = 0; i < 10; i++) {
        solve();
    }
    return 0;
}
