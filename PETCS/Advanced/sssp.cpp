#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int N, M, dist[MAX], vis[MAX]; vector<pair<int, int>> adj[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M;
    for(int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    fill(dist, dist+MAX, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 1});
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        for(auto &x : adj[u]) {
            int v = x.first;
            int w = x.second;
            int d = dist[u] + w;
            if(d < dist[v]) {
                dist[v] = d;
                q.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(dist[i] != INT_MAX) {
            cout << dist[i] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
