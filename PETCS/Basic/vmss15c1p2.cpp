#include <bits/stdc++.h>
using namespace std;
const int MM = 101;
int R, C;
char grid[MM][MM];
void flood(int r, int c) {
    grid[r][c] = 'X';
    // go up
    if(r > 0 and grid[r-1][c] == '.') {
        flood(r-1, c);
    }
    // go down
    if(r < R-1 and grid[r+1][c] == '.') {
        flood(r+1, c);
    }
    // go left
    if(c > 0 and grid[r][c-1] == '.') {
        flood(r, c-1);
    }
    // go right
    if(c < C-1 and grid[r][c+1] == '.') {
        flood(r, c+1);
    }
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
            if(grid[i][j] == '.') {
                flood(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
