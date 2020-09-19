#include <bits/stdc++.h>
using namespace std;
int N, ans = -1; unordered_map<int, int> mp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, d; i < N; i++) {
        cin >> d;
        mp[d]++;
    }
    for(auto &x : mp) {
        ans = max(ans, x.second);
    }
    cout << ans << "\n";
    return 0;
}
