#include <bits/stdc++.h>
using namespace std;
const int MM = 100001;
int N;
char grid[10][MM];
vector<int> v;
bool dfs(int x, int y) {
    if(grid[x][y] == 'X') { // cant visit
        return 0; // return false
    }
    if(y == N-1) { // if the space is open and we are at end
        return 1; // return true
    }
    grid[x][y] = 'X'; // mark as visited
    if(dfs(min(9, x+1), y+1)) { //  if go down and right is possible
        return 1; // return true
    }
    if(dfs(max(0, x-1), y+1)) { // go up and right
        v.push_back(y); // whenever we go up, we tap so we push the time into the vector
        return 1;
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    dfs(9, 0); // (9, 0) starting point
    reverse(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto &x : v) {
        cout << x << " " << 1 << "\n";
    }
    return 0;
}
