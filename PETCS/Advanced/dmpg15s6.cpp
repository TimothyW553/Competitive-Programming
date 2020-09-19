#include <bits/stdc++.h>
using namespace std;
#define double long double
struct Edge {
    int v; double w;
};
const int MAX = 505;
int N, M; map<string, int> names; vector<Edge> adj[MAX]; vector<int> g2[MAX]; queue<int> q; bool vis[MAX]; double dist[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        names[s] = 0;
    }
    int idx = 0;
    for(auto &it : names) {
        names[it.first] = idx++;
    }
    string u, v; double c;
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        adj[names[u]].push_back((Edge){names[v], -log(c)});
        g2[names[v]].push_back(names[u]);
    }
    vis[names["APPLES"]] = true;
    q.push(names["APPLES"]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto &v : g2[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    fill(dist, dist+N, 2e9);
    dist[names["APPLES"]] = 0;
    for(int i = 0; i < 2*N; i++) {
        for(int u = 0; u < N; u++) {
            for(auto &e : adj[u]) {
                int v = e.v;
                double w = e.w;
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
    bool inf = false;
    for(int u = 0; u < N; u++) {
        for(auto &e : adj[u]) {
            int v = e.v;
            double w = e.w;
            if(dist[u] + w < dist[v]-(1e-5) and vis[v]) {
                inf = true;
                break;
            }
        }
    }
    cout << (inf ? "YA" : "NAW") << "\n";
    return 0;
}
