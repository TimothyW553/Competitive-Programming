#include <bits/stdc++.h>
using namespace std;
const int MM = (int)1e6+5;
int N, M, P, Q;
vector<int> adj[MM];
bool vis1[MM], vis2[MM];
void dfs1(int node) {
    vis1[node] = 1;
    for(auto &x : adj[node]) {
        if(!vis1[x]) {
            dfs1(x);
        }
    }
}
void dfs2(int node) {
    vis2[node] = 1;
    for(auto &x : adj[node]) {
        if(!vis2[x]) {
            dfs2(x);
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cin >> P >> Q;
    dfs1(P);
    dfs2(Q);
    if(vis1[Q] and !vis2[P]) {
        cout << "yes" << "\n";
    } else if(!vis1[Q] and vis2[P]) {
        cout << "no" << "\n";
    } else {
        cout << "unknown" << "\n";
    }
    return 0;
}
