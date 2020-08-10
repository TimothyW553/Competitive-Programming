#include <bits/stdc++.h>
using namespace std;
const int MAX = 25;
int T; pair<int, int> allDirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, hDirs[2] = {{0, -1}, {0, 1}}, vDirs[2] = {{1, 0}, {-1, 0}};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> T;
    int R, C;
    while(T--) {
        char grid[MAX][MAX];
        int dist[MAX][MAX];
        for(int i = 0; i < MAX; i++) {
            fill(dist[i], dist[i]+MAX, -1);
        }
        cin >> R >> C;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int r0 = cur.first, c0 = cur.second;
            if(grid[r0][c0] == '+') {
                for(auto &dir : allDirs) {
                    int r = r0+dir.first, c = c0+dir.second;
                    if(r >= 0 and r < R and c >= 0 and c < C and dist[r][c] == -1 and grid[r][c] != '*') {
                        dist[r][c] = dist[r0][c0] + 1;
                        q.push({r, c});
                    }
                }
            } else if(grid[r0][c0] == '-') {
                for(auto &dir : hDirs) {
                    int r = r0+dir.first, c = c0+dir.second;
                    if(r >= 0 and r < R and c >= 0 and c < C and dist[r][c] == -1 and grid[r][c] != '*') {
                        dist[r][c] = dist[r0][c0] + 1;
                        q.push({r, c});
                    }
                }
            } else if(grid[r0][c0] == '|') {
                for(auto &dir : vDirs) {
                    int r = r0+dir.first, c = c0+dir.second;
                    if(r >= 0 and r < R and c >= 0 and c < C and dist[r][c] == -1 and grid[r][c] != '*') {
                        dist[r][c] = dist[r0][c0] + 1;
                        q.push({r, c});
                    }
                }
            }
        }
        cout << dist[R-1][C-1] << "\n";
    }
    return 0;
}
