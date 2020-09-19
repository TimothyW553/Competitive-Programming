#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;
struct Edge {
    int v, w;
    friend bool operator<(const Edge &a, const Edge &b) {
        return a.w > b.w;
    }
};
int N, M, dist[MAX]; vector<Edge> adj[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    cin >> N >> M;
    for(int i = 0, u, v, w; i < N; i++) {
        cin >> u >> v >> w;
        adj[u].push_back((Edge){v, w});
    }
    fill(dist, dist+MAX, INF);
    priority_queue<Edge> q;
    dist[1] = 0;
    q.push((Edge){1, 0});
    while(!q.empty()) {
        int u = q.top().v; q.pop();
        for(auto &x : adj[u]) {
            int v = x.v;
            int w = x.w;
            int d = dist[u] + w;
            if(d < dist[v]) {
                dist[v] = d;
                q.push((Edge){v, dist[v]});
            }
        }
    }
    cout << dist[N] << "\n";
    return 0;
}
