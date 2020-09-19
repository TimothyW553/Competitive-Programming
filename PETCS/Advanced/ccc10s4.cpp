#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;
struct Edge {
    int v, w;
};
Edge edges[805][805];
vector<Edge> adj[MAX];
bool vis[MAX];
int N, corners[8], dist[MAX], best;
void makeEdge(int v1,int v2,int a,int c) {
    if(edges[v1][v2].v != 0) {
        adj[edges[v1][v2].v].push_back((Edge){a, c});
        adj[a].push_back((Edge){edges[v1][v2].v, c});
        edges[v1][v2].v = 0; edges[v2][v1].v = 0;
    } else {
        edges[v1][v2].v = a; edges[v1][v2].w = c;
        edges[v2][v1].v = a; edges[v2][v1].w = c;
    }
}
int prim() {
    int left = N+1, cur = 1, cost = 0, next, smallest;
    fill(dist, dist+MAX, INF);
    if(vis[0]) {
        left--;
    }
    while(left--) {
        smallest = INF;
        next = 1;
        vis[cur] = true;
        for(auto &x : adj[cur]) {
            int v = x.v;
            int w = x.w;
            dist[v] = min(dist[v], w);
        }
        if(left == 1) {
            continue;
        }
        for(int i = 0; i <= N; i++) {
            if(!vis[i]) {
                if(dist[i] < smallest) {
                    smallest = dist[i];
                    next = i;
                }
            }
        }
        if(smallest == INF) {
            return INF;
        }
        cur = next;
        cost += smallest;
    }
    return cost;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 1, e; i <= N; i++) {
        cin >> e;
        for(int j = 0; j < e; j++) {
            cin >> corners[j];
        }
        int cost;
        for (int j = 0; j < e-1; j++) {
            cin >> cost;
            makeEdge(corners[j], corners[j+1], i, cost);
        }
        cin >> cost;
        makeEdge(corners[e-1], corners[0], i, cost);
    }
    for(int i = 0; i < 805; i++) {
        for(int j = 0; j < 805; j++) {
            if(edges[i][j].v != 0) {
                adj[0].push_back((Edge){edges[i][j].v, edges[i][j].w});
                adj[edges[i][j].v].push_back((Edge){0, edges[i][j].w});
                edges[i][j].v = 0; edges[j][i].v = 0;
            }
        }
    }
    vis[0] = true;
    best = prim();
    fill(vis,vis+MAX,false);
    best = min(best,prim());
    cout << best << "\n";
    return 0;
}
