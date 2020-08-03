#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 3005;
ll M, N, arr[MAX][MAX], psa[MAX][MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> M >> N;
    for(int r, c, x;;) {
        cin >> r >> c >> x;
        if(r == 0 and c == 0 and x == 0) {
            break;
        }
        if((r + c) % 2 == 0) {
            arr[r][c] = -x;
        } else {
            arr[r][c] = x;
        }
    }
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            psa[i][j] = arr[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    cout << "\n";
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cout << psa[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int x1, y1, x2, y2;;) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0) {
            break;
        }
        int ans = psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1];
        if((x1+y1) % 2 == 0) {
            cout << -ans << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
