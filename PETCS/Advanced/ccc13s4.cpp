#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
int N, M, P, Q; vector<int> adj[MAX]; bool vis[MAX];
void dfs(int n) {
    vis[n] = true;
    for(auto &x : adj[n]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
}
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
    }
    cin >> P >> Q;
    fill(vis, vis+MAX, false);
    dfs(P);
    bool flg1 = vis[Q];
    fill(vis, vis+MAX, false);
    dfs(Q);
    bool flg2 = vis[P];
    if(flg1 and !flg2) {
        cout << "yes" << "\n";
    } else if(!flg1 and flg2) {
        cout << "no" << "\n";
    } else {
        cout << "unknown" << "\n";
    }
    return 0;
}
