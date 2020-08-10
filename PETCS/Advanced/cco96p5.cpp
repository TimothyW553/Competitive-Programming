#include <bits/stdc++.h>
using namespace std;
int M, N;
map<string, bool> vis; map<string, string> par; map<string, set<string>> adj;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> M >> N;
    string a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    queue<string> q;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        vis.clear(); par.clear();
        q.push(a);
        par[a] = a;
        vis[a] = true;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(auto &x : adj[cur]) {
                if(!vis[x]) {
                    vis[x] = true;
                    par[x] = cur;
                    q.push(x);
                }
            }
        }
        stack<char> st;
        while(par[b] != b) {
            st.push(b[0]);
            b = par[b];
        }
        st.push(b[0]);
        while(!st.empty()) {
            cout << st.top(); st.pop();
        }
        cout << "\n";
    }
    return 0;
}