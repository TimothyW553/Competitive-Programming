#include <bits/stdc++.h>
using namespace std;
int N, n = 0, pen = 0; vector<pair<int, int>> v;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, m, t; i < N; i++) {
        cin >> m >> t;
        v.push_back({m, t}); // due and how much time
    }
    for(int i = 0; i < N; i++) {
        if(n + v[i].second > v[i].first) {
            pen += (n + v[i].second - v[i].first);
        }
        n = min(n + v[i].second, v[i].first); // n is latest time
    }
    cout << pen << "\n";
    return 0;
}
