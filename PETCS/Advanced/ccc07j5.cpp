#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 35;
int A, B, N, dp[MAX]; vector<int> v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> A >> B >> N;
    for(int i = 0, m; i < N; i++) {
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    dp[0] = 1;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < i; j++) {
            int dist = abs(v[j]-v[i]);
            if(dist >= A and dist <= B) {
                dp[i] += dp[j];
            }
        }
    }
    cout << dp[v.size()-1] << "\n";
    return 0;
}
