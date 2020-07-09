#include <bits/stdc++.h>
using namespace std;

int F, R, Q, C, psa[6][10005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> F >> R;
    for(int i = 1; i <= F; i++) {
        for(int j = 1; j <= R; j++) {
            cin >> C;
            psa[i][j] = psa[i][j-1] + C;
        }
    }
    cin >> Q;
    int a, b, c;
    while(Q--) {
        cin >> a >> b >> c;
        cout << psa[c][b]-psa[c][a-1] << "\n";
    }
    return 0;
}
