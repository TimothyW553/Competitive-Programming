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
    int l, w;
    while(T--) {
        cin >> l >> w;
        swap(l, w);
        char grid[l+1][w+1];
        int dist[l+1][w+1];
        pair<int, int> start, end;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'C') {
                    start.first = i; start.second = j;
                }
                if(grid[i][j] == 'W') {
                    end.first = i; end.second = j;
                }
                dist[i][j] = -1;
            }
        }
        queue<pair<int, int>> q;
        dist[start.first][start.second] = 0;
        q.push({start.first, start.second});
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int r = cur.first, c = cur.second;
            if(grid[r][c] == 'W') {
                break;
            }
            if(r > 0 and grid[r-1][c] != 'X') {
                grid[r-1][c] = 'X';
                dist[r-1][c] = dist[r][c] + 1;
                q.push({r-1, c});
            }
            if(r < l-1 and grid[r+1][c] != 'X') {
                grid[r+1][c] = 'X';
                dist[r+1][c] = dist[r][c] + 1;
                q.push({r+1, c});
            }
            if(c > 0 and grid[r][c-1] != 'X') {
                grid[r][c-1] = 'X';
                dist[r][c-1] = dist[r][c] + 1;
                q.push({r, c-1});
            }
            if(c < w-1 and grid[r][c+1] != 'X') {
                grid[r][c+1] = 'X';
                dist[r][c+1] = dist[r][c] + 1;
                q.push({r, c+1});
            }
        }
        int tot = dist[end.first][end.second];
        if(tot >= 60 or tot == -1) {
            cout << "#notworth" << "\n";
        } else {
            cout << dist[end.first][end.second] << "\n";
        }
    }
    return 0;
}
