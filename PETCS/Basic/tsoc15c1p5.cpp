#include <bits/stdc++.h>
using namespace std;
const int MM = 101;
int N, M, W;
int dist[MM], distAnts[MM];
bool vis[MM];
vector<int> adj[MM];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> W;
    queue<int> q;
    fill(vis, vis+N+1, 0);
    fill(distAnts, distAnts+N+1, -1);
    while(W--) {
        cin >> x;
        vis[x] = 1;
        distAnts[x] = 0;
        q.push(x);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(!vis[x]) {
                vis[x] = 1;
                distAnts[x] = distAnts[cur]+1; distAnts[x] *= 4;
                q.push(x);
            }
        }
    }
    fill(vis, vis+N+1, 0);
    fill(dist, dist+N+1, -1);
    dist[1] = 0;
    vis[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(!vis[x] and distAnts[x] > dist[cur]+1) {
                vis[x] = 1;
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    }
    if(dist[N] != -1) {
        cout << dist[N] << "\n";
    } else {
        cout << "sacrifice bobhob314" << "\n";
    }
    return 0;
}