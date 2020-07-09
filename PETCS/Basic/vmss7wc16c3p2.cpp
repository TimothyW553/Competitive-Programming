#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
int N, M, A, B;
vector<int> adj[MM];
bool vis[MM];
void dfs(int src) {
    vis[src] = true;
    for(auto &x : adj[src]) {
        if(!vis[x]) {
            dfs(x);
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
    cin >> N >> M >> A >> B;
    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < N; i++) {

    }
    dfs(A);
    if(vis[B]) {
        cout << "GO SHAHIR!" << "\n";
    } else {
        cout << "NO SHAHIR!" << "\n";
    }
    return 0;
}
