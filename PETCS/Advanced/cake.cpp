#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 5005;
ll N, M, K, Q, dsa[MAX][MAX], na[MAX][MAX], psa[MAX][MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M >> K;
    for(ll i = 0, x1, y1, x2, y2; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        dsa[x1][y1] += 1;
        dsa[x2+1][y1] -= 1;
        dsa[x1][y2+1] -= 1;
        dsa[x2+1][y2+1] += 1;
    }
    // dsa --> [psa] --> normal arr
    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= M; j++) {
            na[i][j] = dsa[i][j] + na[i-1][j] + na[i][j-1] - na[i-1][j-1];
            psa[i][j] = na[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    cin >> Q;
    for(ll i = 0, x1, y1, x2, y2; i < Q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1]) << "\n";
    }
    return 0;
}
