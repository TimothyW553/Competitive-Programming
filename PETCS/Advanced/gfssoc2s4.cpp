#include <bits/stdc++.h>
using namespace std;
const int MAX = 500005;
const int INF = 0x3f3f3f3f;
int N, M, D, dist1[MAX], dist2[MAX], ans;
vector<pair<int, int>> adj1[MAX], adj2[MAX]; vector<pair<int, pair<int, int>>> cindy;
void dijk(int s, int dist[], vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    fill(dist, dist+MAX, INF);
    dist[s] = 0;
    q.push({0, s});
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
        adj1[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }
    cin >> D;
    for(int i = 0, u, v, w; i < D; i++) {
        cin >> u >> v >> w;
        cindy.push_back({u, {v, w}});
    }
    dijk(1, dist1, adj1); dijk(N, dist2, adj2);
    ans = dist1[N];
    for(auto &x : cindy) {
        ans = min(ans, dist1[x.first] + x.second.second + dist2[x.second.first]);
    }
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}
