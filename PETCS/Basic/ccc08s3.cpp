#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> T;
    int row, col;
    while(T--) {
        cin >> row >> col;
        char maze[row][col];
        int dist[row][col];
        bool vis[row][col];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cin >> maze[i][j];
                dist[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        vis[0][0] = 1;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int r = cur.first, c = cur.second;
            // go up
            if((maze[r][c] == '+' or maze[r][c] == '|') and r > 0 and maze[r-1][c] != '*' and vis[r-1][c] == 0) {
                vis[r-1][c] = 1;
                dist[r-1][c] = dist[r][c] + 1;
                q.push({r-1, c});
            }
            // go down
            if((maze[r][c] == '+' or maze[r][c] == '|') and r < row-1 and maze[r+1][c] != '*' and vis[r+1][c] == 0) {
                vis[r+1][c] = 1;
                dist[r+1][c] = dist[r][c] + 1;
                q.push({r+1, c});
            }
            // go left
            if((maze[r][c] == '+' or maze[r][c] == '-') and c > 0 and maze[r][c-1] != '*' and vis[r][c-1] == 0) {
                vis[r][c-1] = 1;
                dist[r][c-1] = dist[r][c] + 1;
                q.push({r, c-1});
            }
            // go left
            if((maze[r][c] == '+' or maze[r][c] == '-') and c < col-1 and maze[r][c+1] != '*' and vis[r][c+1] == 0) {
                vis[r][c+1] = 1;
                dist[r][c+1] = dist[r][c] + 1;
                q.push({r, c+1});
            }
        }
        if(vis[row-1][col-1]) {
            cout << dist[row-1][col-1] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
