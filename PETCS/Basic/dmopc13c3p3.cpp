#include <bits/stdc++.h>
using namespace std;
const int MM = 1501;
int N, H;
int grid[MM][MM];
bool vis[MM][MM];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> H;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        // go up
        if(x > 0 and !vis[x-1][y] and abs(grid[x][y]-grid[x-1][y]) <= H) {
            vis[x-1][y] = 1;
            q.push({x-1, y});
        }
        // go down
        if(x < N-1 and !vis[x+1][y] and abs(grid[x][y]-grid[x+1][y]) <= H) {
            vis[x+1][y] = 1;
            q.push({x+1, y});
        }
        // go left
        if(y > 0 and !vis[x][y-1] and abs(grid[x][y]-grid[x][y-1]) <= H) {
            vis[x][y-1] = 1;
            q.push({x, y-1});
        }
        // go right
        if(y < N-1 and !vis[x][y+1] and abs(grid[x][y]-grid[x][y+1]) <= H) {
            vis[x][y+1] = 1;
            q.push({x, y+1});
        }
    }
    if(vis[N-1][N-1]) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
    return 0;
}
