#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;
int N, M, S, T, dist[MAX]; vector<pair<int, int>> adj[MAX];
int spfa(int s, int t) {
    fill(dist, dist+MAX, INF);
    dist[s] = 0;
    deque<int> q;
    q.push_back(s);
    while(!q.empty()) {
        auto u = q.front(); q.pop_front();
        for(auto &e : adj[u]) {
            int v = e.first;
            int w = e.second;
            int d = dist[u] + w;
            if(d < dist[v]) {
                dist[v] = d;
                if(find(q.begin(), q.end(), v) == q.end()) {
                    q.push_back(v);
                }
            }
        }
    }
    return dist[t];
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
    }
    int dis = spfa(1, N);
    if(dis == INF) {
        cout << "No path" << "\n";
    } else if(dis == -1) {
        cout << "negative weight" << "\n";
    } else {
        cout << 1 << " to " << N << ": " << dis << "\n"; 
    }
    return 0;
}
