#include <bits/stdc++.h>
using namespace std;
pair<int, int> pos[6];
int N, M, T, dis[6][22][22];
char g[22][22];
pair<int, int> moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ord[6] = {1, 2, 3, 4, 5};
void bfs(int n) {
    queue<pair<int, int>> q;
    q.push(pos[n]);
    dis[n][pos[n].first][pos[n].second] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto &dir : moves) {
            int r = cur.first + dir.first, c = cur.second + dir.second;
            if(r > 0 and r <= N and c > 0 and c <= M and dis[n][r][c] < 0 and g[r][c] != 'X') {
                q.push({r, c});
                dis[n][r][c] = dis[n][cur.first][cur.second] + 1;
            }
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    memset(dis, -1, sizeof(dis));
    cin >> N >> M >> T;
    int cnt = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> g[i][j];
            if(g[i][j] == 'H') {
                pos[cnt].first = i, pos[cnt].second = j;
                cnt++;
            }
            if(g[i][j] == 'G') {
                pos[0].first = i, pos[0].second = j;
            }
        }
    }
    for(int i = 0; i <= T; i++) {
        bfs(i);
    }
    int ans = 999999;
    do {
        int r = pos[ord[0]].first, c = pos[ord[0]].second, t = dis[0][r][c];
        for(int i = 1; i < T; i++) {
            r = pos[ord[i]].first, c = pos[ord[i]].second;
            t += dis[ord[i-1]][r][c];
        }
        ans = min(ans, t);
    } while(next_permutation(ord, ord+T));
    cout << ans << "\n";
    return 0;
}
