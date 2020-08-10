#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MAX = 5005;
int N, T, K, D, dist[MAX], ans = INT_MAX; vector<pair<int, int>> adj[MAX]; vector<pair<int, int>> prices;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    scan(N); scan(T);
    for(int i = 0, u, v, w; i < T; i++) {
        scan(u); scan(v); scan(w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    scan(K);
    for(int i = 0, z, p; i < K; i++) {
        scan(z); scan(p);
        prices.push_back({z, p});
    }
    scan(D);
    fill(dist, dist+MAX, INT_MAX);
    dist[D] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, D});
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
    for(auto &x : prices) {
        // if(x.first != D) {
            ans = min(ans, (dist[x.first] + x.second));
        // }
    }
    cout << ans << "\n";
    return 0;
}