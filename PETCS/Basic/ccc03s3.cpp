#include <bits/stdc++.h>
using namespace std;
int N, R, C, room_size;
vector<int> room_sizes;
char grid[26][26];
void flood(int r, int c) {
    grid[r][c] = 'I';
    room_size++;
    if(r > 0 and grid[r-1][c] == '.') { flood(r-1, c); }
    if(r < R-1 and grid[r+1][c] =='.') { flood(r+1, c); }
    if(c > 0 and grid[r][c-1] == '.') { flood(r, c-1); }
    if(c < C-1 and grid[r][c+1] == '.') { flood(r, c+1); }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '.') {
                room_size = 0;
                flood(i, j);
                room_sizes.push_back(room_size);
            }
        }
    }
    sort(room_sizes.rbegin(), room_sizes.rend());
    int cnt = 0;
    for(auto &x : room_sizes) {
        if(N-x < 0) {
            break;
        }
        N -= x;
        cnt++;
    }
    if(cnt == 1) {
        printf("%d room, %d square metre(s) left over\n", cnt, N);
    } else {
        printf("%d rooms, %d square metre(s) left over\n", cnt, N);
    }
    return 0;
}
