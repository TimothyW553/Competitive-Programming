#include <bits/stdc++.h>
using namespace std;
const int MAX = 8;
int deg[MAX];
vector<int> adj[MAX], order;
bool vis[MAX];
void add(int a, int b) {
    adj[a].push_back(b);
    deg[b]++;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    add(1, 7);
    add(1, 4);
    add(2, 1);
    add(3, 4);
    add(3, 5);
    for(int a, b; a != 0 and b != 0;) {
        cin >> a >> b;
        add(a, b);
    }
    queue<int> q;
    for(int i = 1; i <= 7; i++) {
        if(deg[i] == 0) {
            q.push(i);
            vis[i] = true;
            break;
        }
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop(); order.push_back(cur);
        vis[cur] = true;
        for(auto &x : adj[cur]) {
            deg[x]--;
        }
        for(int i = 1; i <= 7; i++) {
            if(deg[i] == 0 and !vis[i]) {
                q.push(i);
                vis[i] = true;
                break;
            }
        }
    }
    for(int i = 1; i <= 7; i++) {
        if(deg[i] > 0) {
            return cout << "Cannot complete these tasks. Going to bed." << "\n", 0;
        }
    }
    for(auto &x : order) {
        cout << x << " ";
    }
    return 0;
}