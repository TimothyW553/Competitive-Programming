#include <bits/stdc++.h>
using namespace std;
struct state {
    int t, x, y;
};
const int MAX = 105;
int R, C, T, steps = 0, dist[11][MAX][MAX]; char mat[11][MAX][MAX];
pair<int, int> loc[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    pair<int, int> a, b;
    cin >> R >> C >> T;
    for(int k = 0; k < T; k++) {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin >> mat[k][i][j];
                if(mat[k][i][j] == 'A') {
                    a = {i, j};
                }
                if(mat[k][i][j] == 'B') {
                    b = {i, j};
                }
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < MAX; j++) {
            fill(dist[i][j], dist[i][j]+MAX, -1);
        }
    }
    queue<state> q;
    dist[0][a.first][a.second] = 0;
    q.push((state){0, a.first, a.second});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto &dir : loc) {
            int dim = cur.t, r = cur.x+dir.first, c = cur.y+dir.second;
            if(r >= 0 and r < R and c >= 0 and c < C and dist[dim][r][c] == -1 and mat[dim][r][c] != 'X') {
                dist[dim][r][c] = dist[dim][cur.x][cur.y] + 1;
                q.push((state){dim, r, c});
            }
        }
        for(int i = 0; i < T; i++) {
            if(i != cur.t) {
                int dim = cur.t, r = cur.x, c = cur.y;
                if(r >= 0 and r < R and c >= 0 and c < C and dist[i][r][c] == -1 and mat[i][r][c] != 'X') {
                    dist[i][r][c] = dist[dim][cur.x][cur.y] + 1;
                    q.push((state){i, r, c});
                }
            }
        }
    }
    cout << dist[0][b.first][b.second] << "\n";
    return 0;
}
