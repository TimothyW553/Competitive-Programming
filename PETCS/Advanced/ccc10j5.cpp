#include <bits/stdc++.h>
using namespace std;
int x1, y1_, x2, y2, dist[9][9]; bool vis[9][9];
pair<int, int> pos[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> x1 >> y1_ >> x2 >> y2;
    queue<pair<int, int>> q;
    dist[x1][y1_] = 0;
    vis[x1][y1_] = true;
    q.push({x1, y1_});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto &dir : pos) {
            int r = cur.first + dir.first;
            int c = cur.second + dir.second;
            if(r >= 1 and r <= 8 and c >= 1 and c <= 8 and !vis[r][c]) {
                vis[r][c] = true;
                dist[r][c] = dist[cur.first][cur.second] + 1;
                q.push({r, c});
            }
        }
    }
    cout << dist[x2][y2] << "\n";
    return 0;
}
