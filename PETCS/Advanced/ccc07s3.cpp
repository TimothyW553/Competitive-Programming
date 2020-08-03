#include <bits/stdc++.h>
using namespace std;
const int MAX  = 10005;
int N;
vector<int> adj[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int x, y;;) {
        cin >> x >> y;
        if(x == 0 and y == 0) {
            break;
        } 
        int dist[MAX]; bool vis[MAX];
        fill(dist, dist+MAX-5, 0);
        fill(vis, vis+MAX-5, false);
        queue<int> q;
        q.push(x);
        dist[x] = 0;
        vis[x] = true;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(auto &x : adj[cur]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                    dist[x] = dist[cur] + 1;
                }
            }
        }
        if(vis[y]) {
            cout << "Yes " << dist[y]-1 << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    return 0;
}
