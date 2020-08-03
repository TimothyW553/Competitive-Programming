#include <bits/stdc++.h>
using namespace std;
int matrix[55][55];
void i(int x, int y) {
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}
void d(int x, int y) {
    matrix[x][y] = 0;
    matrix[y][x] = 0;
}
int n(int x) {
    int cnt = 0;
    for(int i = 1; i <= 50; i++) {
        if(matrix[x][i] == 1) {
            cnt++;
        }
    }
    return cnt;
}
int f(int x) {
    set<int> st;
    for(int i = 1; i <= 50; i++) {
        if(matrix[x][i] == 1) {
            for(int j = 1; j <= 50; j++) {
                if(matrix[i][j] == 1 and matrix[j][x] == 0 and j != x) {
                    st.insert(j);
                }
            }
        }
    }
    return st.size();
}
int s(int x, int y) {
    queue<int> q;
    int dist[55];
    fill(dist, dist+50, -1);
    bool vis[55];
    fill(vis, vis+50, false);
    q.push(x);
    dist[x] = 0;
    vis[x] = true;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i = 1; i <= 50; i++) {
            if(matrix[cur][i] == 1 and !vis[i]) {
                q.push(i);
                dist[i] = dist[cur] + 1;
                vis[i] = true;
            }
        }
    }
    return dist[y];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    i(1,6);
    i(2,6);
    i(3,4);
    i(3,5);
    i(3,6);
    i(3,15);
    i(4,5);
    i(4,6);
    i(5,6);
    i(6,7);
    i(7,8);
    i(8,9);
    i(9,10);
    i(9,12);
    i(10,11);
    i(11,12);
    i(12,13);
    i(13,14);
    i(13,15);
    i(16,17);
    i(16,18);
    i(17,18);
    for(char c; c != 'q';) {
        cin >> c;
        if(c == 'i') {
            int x, y;
            cin >> x >> y;
            i(x, y);
        } else if(c == 'd') {
            int x, y;
            cin >> x >> y;
            d(x, y);
        } else if(c == 'n') {
            int x;
            cin >> x;
            cout << n(x) << "\n";
        } else if(c == 'f') {
            int x;
            cin >> x;
            cout << f(x) << "\n";
        } else if(c == 's') {
            int x, y;
            cin >> x >> y;
            int ans = s(x, y);
            if(ans != -1) {
                cout << ans << "\n";
            } else {
                cout << "Not connected" << "\n";
            }
        }
    }
    return 0;
}
