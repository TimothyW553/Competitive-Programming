#include <bits/stdc++.h>
using namespace std;
const int MAX = 10005;
const int INF = 0x3f3f3f3f;
struct Edge {
    int b, c, d;
    friend bool operator<(const Edge &a, const Edge &b) {
        if(a.c == b.c) {
            return a.d > b.d;
        } else {
            return a.c > b.c;
        }
    }
};
int N, M, dist[MAX]; bool vis[MAX]; vector<Edge> adj[MAX]; 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M;
    for(int i = 0, a, b, c, d; i < M; i++) {
        cin >> a >> b >> c >> d;
        adj[a].push_back((Edge){b, c, d});
        adj[b].push_back((Edge){a, c, d});
    }
    fill(dist, dist+MAX, INF);
    fill(vis, vis+MAX, false);
    priority_queue<Edge> q;
    dist[1] = 0;
    q.push((Edge){-1, 0, 0});
    
    return 0;
}
