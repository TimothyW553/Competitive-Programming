#include <bits/stdc++.h>
using namespace std;
vector<string> v; vector<int> adj[30]; bool vis[30]; int cnt = 0;
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
    string s;
    while(1) {
        cin >> s;
        if(s == "**") {
            break;
        }
        v.push_back(s);
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < 30; j++) {
            adj[j].clear();
        }
        fill(vis, vis+26, false);
        for(int j = 0; j < v.size(); j++) {
            if(j != i) {
                int x = int(v[j][0]-'A'), y = int(v[j][1]-'A');
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }
        dfs(0);
        if(!vis[1]) {
            cnt++;
            cout << v[i] << "\n";
        }
    }
    cout << "There are " << cnt << " disconnecting roads." << "\n";
    return 0;
}
