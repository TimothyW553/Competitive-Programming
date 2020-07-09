#include <bits/stdc++.h>
using namespace std;
const int MM = 400001;
int N, vals[MM];
vector<int> adj[MM];
void dfs(int n) {
    for(auto &x : adj[n]) {
        dfs(x);
        vals[n] += vals[x];
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int a, b;
    for(int i = 0; i < N-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= N; i++) {
        cin >> vals[i];
    }
    dfs(1);
    int best = -INT_MAX;
    for(int i = 1; i < MM; i++) {
        best = max(best, vals[i]);
    }
    cout << best << "\n";
    return 0;
}
