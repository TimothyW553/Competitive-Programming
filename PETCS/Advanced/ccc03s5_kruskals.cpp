#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
struct Edge {
    int u, v, w;
} roads[MAX];
bool cmp(const Edge &a, const Edge &b) {
    return a.w > b.w;
}
int N, M, D, ans, edges, lead[MAX], depth[MAX], cnt[MAX];
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
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(depth[a] > depth[b]) {
            lead[b] = a;
            cnt[a] += cnt[b];
        } else {
            lead[a] = b;
            if(depth[a] == depth[b]) {
                depth[b]++;
            }
            cnt[b] += cnt[a];
        }
        edges++;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M >> D;
    for(int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        roads[i] = (Edge){u, v, w};
    }
    for(int i = 0, d; i < D; i++) {
        cin >> d;
        cnt[d] = 1;
    }
    sort(roads, roads+M, cmp);
    for(int i = 0; i < M; i++) {
        if(lead[roads[i].u] == 0) {
            make_set(roads[i].u);
        }
        if(lead[roads[i].v] == 0) {
            make_set(roads[i].v);
        }
        merge(roads[i].u, roads[i].v);
        ans = roads[i].w;
        if(cnt[find(roads[i].u)] == D or edges >= N-1) {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
