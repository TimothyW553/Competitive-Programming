#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int A, B, N; ll dp[40];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
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
    dp[0] = 1; // number of ways to get to the first step is obviously 1
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            int dist = v[i] - v[j];
            if(dist >= A and dist <= B) {
                dp[i] += dp[j]; // this is like the classic staircase problem but you can basically go from all valid positions
            }
        }
    }
    cout << dp[v.size()-1] << "\n";
    return 0;
}
