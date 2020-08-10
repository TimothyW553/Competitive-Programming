#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int N, M, distSrc[MAX], distDest[MAX]; vector<pair<int, int>> adj[MAX];
void dijkstra(int s, int dist[]) {
    fill(dist, dist+MAX, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, s});
    dist[s] = 0;
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
}
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
    dijkstra(0, distSrc);
    dijkstra(N-1, distDest);
    int ans = -INT_MAX;
    for(int i = 0; i < N; i++) {
        // cout << i << " " << distSrc[i] << " " << distDest[i] << "\n";
        if(distSrc[i] != INT_MAX and distDest[i] != INT_MAX) {
            ans = max(ans, distSrc[i]+distDest[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
