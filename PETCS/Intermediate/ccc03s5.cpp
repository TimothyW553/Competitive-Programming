#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
struct Edge {
    int a, b, w;
};
int C, R, D, ans = 0x3f3f3f3f, par[MAX], dist[MAX];
vector<pair<int, int>> adj[MAX]; vector<Edge> edges;
bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}
int Find(int x) {
    if(par[x] == x) {
        return x;
    }
    return par[x] = Find(par[x]);
}
void Union(int x, int y) {
    int p = Find(x);
    int q = Find(y);
    par[p] = par[q];
}
void dfs(int src, int p) {
    for(auto &child : adj[src]) {
        if(child.second == p) {
            continue;
        }
        dist[child.second] = min(dist[src], child.first);
        cout << child.second << " ";
        for(int i = 1; i < 10; i++) {
            cout << dist[i] << " ";
        }
        cout << "\n";
        dfs(child.second, src);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> C >> R >> D;
    dist[1] = 0x3f3f3f3f;
    for(int i = 0, x, y, w; i < R; i++) {
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    sort(edges.begin(), edges.end(), cmp);
    for(int i = 1; i <= C; i++) {
        par[i] = i;
    }
    for(auto &x : edges) {
        cout << x.a << " " << x.b << " " << x.w << "\n";
    }
    for(auto &edge : edges) {
        if(Find(edge.a) != Find(edge.b)) {
            cout << edge.a << " " << edge.b << " " << Find(edge.a) << " " << Find(edge.b) << "\n";
            Union(edge.a, edge.b);
            adj[edge.a].push_back({edge.w, edge.b});
            adj[edge.b].push_back({edge.w, edge.a});
        }
    }
    for(int i = 0; i < C; i++) {
        cout << par[i] << " ";
    }
    cout << "\n";
    dfs(1, 1);
    for(int i = 0, d; i < D; i++) {
        cin >> d;
        ans = min(ans, dist[d]);
    }
    cout << ans << "\n";
    return 0;
}
