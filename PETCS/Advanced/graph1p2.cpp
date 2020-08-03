#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int N, matrix[MAX][MAX], vis[MAX], dist[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> matrix[i][j];
        }
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dist[1] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i = 1; i <= N; i++) {
            if(!vis[i] and matrix[cur][i] == 1) {
                vis[i] = true;
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
    cout << dist[N] << "\n";
    return 0;
}
