#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int N, M, K, dist[MAX], ans = -1; bool vis[MAX]; vector<int> adj[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M;
    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    cin >> K;
    for(int i = 0, a; i < K; i++) {
        cin >> a;
        q.push(a);
        vis[a] = true;
        dist[a] = 0;
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(!vis[x]) {
                vis[x] = true;
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    }
    for(int i = 0; i <= N; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans << "\n";
    return 0;
}
