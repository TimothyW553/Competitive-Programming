#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int v, t, h;
    friend bool operator<(const Edge &a, const Edge &b) {
        return a.t > b.t;
    }
};
const int MAX = 2005;
int K, N, M, S, T, ans = INT_MAX, dist[MAX][205]; vector<Edge> adj[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> K >> N >> M;
    for(int i = 0, a, b, t, h; i < M; i++) {
        cin >> a >> b >> t >> h;
        adj[a].push_back(Edge{b, t, h});
        adj[b].push_back(Edge{a, t, h});
    }
    cin >> S >> T;
    for(int i = 0; i < MAX; i++) {
        fill(dist[i], dist[i]+205, INT_MAX);
    }
    priority_queue<Edge> q;
    q.push({S, 0, 0});
    dist[S][0] = 0;
    while(!q.empty()) {
        auto cur = q.top(); q.pop();
        int u = cur.v, h0 = cur.h;
        for(auto &x : adj[u]) {
            int v = x.v;
            int t = x.t;
            int h = x.h;
            int d = dist[u][h0] + t;
            if(d < dist[v][h+h0] and h + h0 < K) {
                dist[v][h+h0] = d;
                q.push({v, dist[v][h+h0], h+h0});
            }
        }
    }
    for(int i = 0; i < K; i++) {
        ans = min(ans, dist[T][i]);
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}
