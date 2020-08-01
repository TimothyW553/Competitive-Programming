#include <bits/stdc++.h>
using namespace std;
int N, M, K, best = 0, cnt = 0, dsa[1005][30005];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> M >> N >> K;
    while(K--) {
        int x, y, r, b; cin >> x >> y >> r >> b;
        for(int i = max(1, x-r); i <= min(N, x+r); i++) { // go through each row
            int d = (int)sqrt(r*r-(i-x)*(i-x));
            dsa[i][max(1, y-d)] += b;
            dsa[i][min(y+d+1, M+1)] -= b;
        }
    }
    // basically represent as M 1d difference arrays
    for(int j = 1; j <= N; j++) {
        for(int i = 1, k = 0; i <= M; i++) {
            k += dsa[j][i];
            if(k > best) {
                best = k;
                cnt = 1;
            } else if(k == best) {
                cnt++;
            }
        }
    }
    cout << best << "\n";
    cout << cnt << "\n";
    return 0;
}
