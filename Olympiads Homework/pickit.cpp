#include <bits/stdc++.h>
using namespace std;

int a[256];
int dp[256][256];

int solve(int l, int r) {
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = 0;
    for(int m = l + 1; m < r; m++)
        ans = max(ans, solve(l, m) + solve(m, r) + a[l] + a[m] + a[r]);
    return dp[l][r] = ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n != 0) {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        cout << solve(0, n-1) << "\n";
        cin >> n;
    }
}
