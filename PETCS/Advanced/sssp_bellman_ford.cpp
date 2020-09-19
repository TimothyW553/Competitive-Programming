#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;
int N, M, S, T, dist[MAX]; vector<pair<int, int>> adj[MAX];
int bf(int s, int t) {
    fill(dist, dist+MAX, INF);
    dist[s] = 0;
    for(int i = 1; i <= N; i++) {
        for(int u = 1; u <= N; u++) {
            for(auto &e : adj[u]) {
                int v = e.first;
                int w = e.second;
                if(dist[u] != INF and dist[u] + w < dist[v]) {
                    if(i == N) {
                        return -1;
                    } else {
                        dist[v] = dist[u] + w;
                    }
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
    int dis = bf(1, N);
    if(dis == INF) {
        cout << "No path" << "\n";
    } else if(dis == -1) {
        cout << "negative weight" << "\n";
    } else {
        cout << 1 << " to " << N << ": " << dis << "\n"; 
    }
    return 0;
}
