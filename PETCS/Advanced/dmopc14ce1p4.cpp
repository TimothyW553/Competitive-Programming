#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int V, E, cnt = 0, par[MAX]; double dist[MAX]; vector<pair<int, double>> adj[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> V >> E;
    for(int i = 0, u, v, d, s; i < E; i++) {
        cin >> u >> v >> d >> s;
        double t = (double)d*60.0/s;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    fill(dist, dist+MAX, INT_MAX);
    memset(par, -1, sizeof par);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push({0.0, 1});
    dist[1] = 0.0;
    while(!q.empty()) {
        auto u = q.top().second; q.pop();
        for(auto &x : adj[u]) {
            int v = x.first;
            double t = x.second;
            double d = dist[u] + t;
            if(d < dist[v]) {
                dist[v] = d;
                par[v] = u;
                q.push({dist[v], v});
            }
        }
    }
    for(int i = V; i != -1; i = par[i]) {
        cnt++;
    }
    printf("%d\n%.0lf\n", cnt-1, dist[V]*1/3.0);
    return 0;
}