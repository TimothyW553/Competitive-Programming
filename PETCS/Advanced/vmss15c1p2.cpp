#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int R, C, cnt = 0; char grid[MAX][MAX];
void floodfill(int x, int y) {
    grid[x][y] = 'X';
    if(x > 0 and grid[x-1][y] == '.') {
        floodfill(x-1, y);
    }
    if(x < R-1 and grid[x+1][y] == '.') {
        floodfill(x+1, y);
    }
    if(y > 0 and grid[x][y-1] == '.') {
        floodfill(x, y-1);
    }
    if(y < C-1 and grid[x][y+1] == '.') {
        floodfill(x, y+1);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
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
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '.') {
                floodfill(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
