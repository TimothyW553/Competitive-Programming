#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int N, A, B;
vector<int> adj[MM];
bool vis[MM];
void dfs(int src) {
    vis[src] = true;
    for(auto &x : adj[src]) {
        if(!vis[src]) {
            dfs(src);
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
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cin >> A >> B;
    dfs(A);
    if(!vis[B]) {
        cout << "Tangled" << "\n";
    } else {
        cout << "Not Tangled" << "\n";
    }
    return 0;
}
