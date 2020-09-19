#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int INF = 0x3f3f3f3f;
int N, M, dist[MAX]; bool vis[MAX]; vector<pair<int, int>> adj[MAX]; vector<int> ans;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M;
    for(int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    fill(dist, dist+MAX, INF);
    fill(vis, vis+MAX, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    dist[1] = 0;
    q.push({0, 1});
    while(!q.empty()) {
        int u = q.top().second, e = q.top().first; q.pop();
        if(vis[u]) {
            continue;
        }
        vis[u] = true;
        ans.push_back(e);
        for(auto &x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if(!vis[v]) {
                if(w < dist[v]) {
                    dist[v] = w;
                    q.push({dist[v], v});
                }
            }
        }
    }
    if(ans.size() < N) {
        cout << "Disconnected Graph" << "\n";
    } else {
        for(int i = 1; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}
