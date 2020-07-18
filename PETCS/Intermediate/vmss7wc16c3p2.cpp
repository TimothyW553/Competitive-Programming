#include <bits/stdc++.h>
using namespace std;
const int MAX = 2005;
int N, M, A, B, vis[MAX];
vector<int> adj[MAX];
void dfs(int n) {
    vis[n] = 1;
    for(auto &x : adj[n]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> A >> B;
    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(A);
    if(vis[B]) {
        cout << "GO SHAHIR!" << "\n";
    } else {
        cout << "NO SHAHIR!" << "\n";
    }
    return 0;
}
