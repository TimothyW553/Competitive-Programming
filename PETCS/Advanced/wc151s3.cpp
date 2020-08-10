#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100005;
const int INF = 0x3f3f3f3f;
int N, M, K, C[MAX], dist[3][MAX]; ll ans = 0; vector<pair<int, int>> adj[MAX];
void dijkstra(int s) {
    dist[s][s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        for(auto &x : adj[u]) {
            int v = x.first;
            int w = x.second;
            int d = dist[s][u] + w;
            if(d < dist[s][v]) {
                dist[s][v] = d;
                q.push({dist[s][v], v});
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
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    for(int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[v].push_back({u, w});
    }
    fill(dist[1], dist[1]+MAX, INF);
    dijkstra(1); 
    fill(dist[2], dist[2]+MAX, INF);
    dijkstra(2);
    vector<pair<int, int>> v;
    for(int i = 1; i <= N; i++) {
        if(C[i] == 0) {
            continue;
        }
        // case work
        // 1. D1 = D2 = INF
        // 2. D1 = INF
        // 3. D1 <= D2
        // 4. D1 > D2
        if(dist[1][i] >= INF and dist[2][i] >= INF) {
            return cout << -1 << "\n", 0;
        } else if(dist[1][i] >= INF) { // we cant reach the main site so we go to the second one
            ans += (ll)C[i]*dist[2][i];
            K -= C[i];
        } else if(dist[1][i] <= dist[2][i]) { // no limits? send em all to site 1
            ans += (ll)C[i]*dist[1][i];
        } else if(dist[1][i] > dist[2][i]) { // make a decision later
            v.push_back({dist[1][i]-dist[2][i], i});
        }
    }
    if(K < 0) {
        return cout << -1 << "\n", 0;
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++) {
        int cur = v[i].second;
        int send = min(K, C[cur]);
        ans += (ll)dist[1][cur]*(C[cur]-send);
        ans += (ll)dist[2][cur]*send;
        K -= send;
    }
    cout << ans << "\n";
    return 0;
}