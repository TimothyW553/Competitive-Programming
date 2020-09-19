#include <bits/stdc++.h>
using namespace std;
const int MAX = 10005;
int N, M, D, ans = 1e9, dist[MAX]; vector<pair<int, int>> adj[MAX]; bool dest[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M >> D;
    for(int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 0, u; i < D; i++) {
        cin >> u;
        dest[u] = true;
    }
    priority_queue<pair<int, int>> q;
    dist[1] = 1e9;
    q.push({1e9, 1});
    while(!q.empty()) {
        int u = q.top().second, d = q.top().first; q.pop();
        if(d < dist[u]) {
            continue;
        }
        for(auto &x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if(w > dist[v]) {
                dist[v] = w;
                q.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(dest[i]) {
            ans = min(ans, dist[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
