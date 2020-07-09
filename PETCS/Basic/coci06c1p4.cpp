#include <bits/stdc++.h>
using namespace std;
const int MM = 51;
int R, C;
char grid[MM][MM];
bool vis[MM][MM];
int flood_dist[MM][MM], src_dist[MM][MM];
vector<pair<int, int>> floods;
pair<int, int> moves[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool in_range(int r, int c) {
    if((r >= 0 and r < R) and (c >= 0 and c < C)) {
        return true;
    }
    return false;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> R >> C;
    pair<int, int> src, dest;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '*') {
                floods.push_back({i, j});
            } else if(grid[i][j] == 'S') {
                src = {i, j};
            } else if(grid[i][j] == 'D') {
                dest = {i, j};
            }
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            vis[i][j] = 0;
            flood_dist[i][j] = -1;
            src_dist[i][j] = -1;
        }
    }
    for(auto &flood : floods) {
        q.push(flood);
        grid[flood.first][flood.second] = '*';
        flood_dist[flood.first][flood.second] = 0;
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto &dir : moves) {
            int r = cur.first+dir.first, c = cur.second+dir.second;
            if(in_range(r, c) and grid[r][c] != 'X' and grid[r][c] != '*' and grid[r][c] != 'D') {
                q.push({r, c});
                grid[r][c] = '*';
                flood_dist[r][c] = flood_dist[cur.first][cur.second] + 1;
            }
        }
    }
    flood_dist[dest.first][dest.second] = INT_MAX;
    q.push({src.first, src.second});
    vis[src.first][src.second] = 1;
    src_dist[src.first][src.second] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto &dir : moves) {
            int r = cur.first+dir.first, c = cur.second+dir.second;
            if(in_range(r, c) and !vis[r][c] and grid[r][c] != 'X' and (src_dist[cur.first][cur.second] + 1 < flood_dist[r][c] or flood_dist[r][c] == -1) ) {
                q.push({r, c});
                vis[r][c] = 1;
                src_dist[r][c] = src_dist[cur.first][cur.second] + 1;
            }
        }
    }
    if(src_dist[dest.first][dest.second] == -1) {
        cout << "KAKTUS" << "\n";
    } else {
        cout << src_dist[dest.first][dest.second] << "\n";
    }
    return 0;
}
