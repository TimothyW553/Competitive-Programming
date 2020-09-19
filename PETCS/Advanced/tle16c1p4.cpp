#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;
struct Edge {
    int v, w;
    friend bool operator<(const Edge &a, const Edge &b) {
        return a.w > b.w;
    }
};
int N, M, K, ans, dist[MAX], microwave[MAX]; vector<Edge> adj[MAX]; bitset<MAX> cover[MAX];
void dijk(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    fill(dist, dist+MAX, INF);
    dist[s] = 0;
    q.push({0, s});
    cover[s].set(s);
    while(!q.empty()) {
        int u = q.top().second, w0 = q.top().first; q.pop();
        if(dist[u] != w0) {
            continue;
        }
        for(auto &e : adj[u]) {
            int v = e.v;
            int w = e.w;
            int d = dist[u] + w;
            if(d <= dist[v] and d <= K) {
                cover[s].set(v);
                dist[v] = d;
                q.push({dist[v], v});
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
        cin >> microwave[i];
    }
    for(int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back((Edge){v, w});
        adj[v].push_back((Edge){u, w});
    }
    for(int i = 1; i <= N; i++) {
        dijk(i);
    }
    bitset<MAX> best;
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            for(int k = j+1; k <= N; k++) {
                int cnt = 0;
                bitset<MAX> tot = cover[i] | cover[j] | cover[k];
                for(int a = 1; a <= N; a++) {
                    if(tot.test(a)) {
                        cnt += microwave[a];
                    }
                }
                if(cnt > ans) {
                    best = tot;
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
