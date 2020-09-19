#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int N, M, lead[MAX], depth[MAX]; vector<int> edges;
void make_set(int n) {
    lead[n] = n;
    depth[n] = 0;
}
int find(int n) {
    if(lead[n] != n) {
        lead[n] = find(lead[n]);
    }
    return lead[n];
}
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(depth[a] > depth[b]) {
            lead[b] = a;
        } else {
            lead[a] = b;
            if(depth[a] == depth[b]) {
                depth[b]++;
            }
        }
        return true;
    }
    return false;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M;
    for(int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        if(lead[u] == 0) {
            make_set(u);
        }
        if(lead[v] == 0) {
            make_set(v);
        }
        if(merge(u, v)) {
            edges.push_back(i);
        }
    }
    if(edges.size() == N-1) {
        for(auto &x : edges) {
            cout << x << "\n";
        }
    } else {
        cout << "Disconnected Graph" << "\n";
    }
    return 0;
}
