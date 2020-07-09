#include <bits/stdc++.h>
using namespace std;
int dist[9][9];
int start_x, start_y, end_x, end_y;
pair<int, int> moves[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, 1}, {2, -1}};
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> start_x >> start_y >> end_x >> end_y;
    if(start_x == end_x and start_y == end_y) {
        return cout << 0 << "\n", 0;
    }
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto &dir : moves) {
            int r = cur.first+dir.first, c = cur.second+dir.second;
            if(r == end_x and c == end_y) {
                dist[r][c] = dist[cur.first][cur.second] + 1;
                return cout << dist[r][c] << "\n", 0;
            }
            if(r > 0 and r < 9 and c > 0 and c < 9) {
                dist[r][c] = dist[cur.first][cur.second] + 1;
                q.push({r, c});
            }
        }
    }
    return 0;
}