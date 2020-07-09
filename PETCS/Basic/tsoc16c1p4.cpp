#include <bits/stdc++.h>
using namespace std;

int R, C;
char grid[36][50];
void flood(int r, int c) {
    grid[r][c] = '#';
    if(r > 0 and grid[r-1][c] != '#') { flood(r-1, c); }
    if(r < R-1 and grid[r+1][c] != '#') { flood(r+1, c); }
    if(c > 0 and grid[r][c-1] != '#') { flood(r, c-1); }
    if(c < C-1 and grid[r][c+1] != '#') { flood(r, c+1); }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == 'M') {
                cnt++;
                flood(i, j);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
