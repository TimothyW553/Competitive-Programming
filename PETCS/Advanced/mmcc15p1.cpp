#include <bits/stdc++.h>
using namespace std;
const int MAX = 500005;
int lead[MAX], depth[MAX], sz[MAX];
stack<int> moves;
void make_set(int n) {
    lead[n] = n;
    depth[n] = 1;
    sz[n] = 1;
}
int find(int n) {
    if(lead[n] == n) {
        return n;
    }
    return find(lead[n]);
}
int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(depth[b] > depth[a]) {
            lead[a] = b;
            sz[b] += sz[a];
            return a;
        } else {
            if(depth[a] == depth[b]) {
                depth[a]++;
            }
            lead[b] = a;
            sz[a] += sz[b];
            return b;
        }
    }
    return -1;
}
void Init(int n) {
    for(int i = 1; i <= n; i++) {
        make_set(i);
    }
}
void AddEdge(int u, int v) {
    moves.push(merge(u, v));
}
void RemoveLastEdge() {
    if(!moves.empty()) {
        int top = moves.top(); moves.pop();
        if(top != -1) {
            int nd = lead[top];
            while(1) {
                sz[nd] -= sz[top];
                if(lead[nd] == nd) {
                    break;
                }
                nd = lead[nd];
            }
            lead[top] = top;
        }
    }
}
int GetSize(int u) {
    return sz[find(u)];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    return 0;
}
