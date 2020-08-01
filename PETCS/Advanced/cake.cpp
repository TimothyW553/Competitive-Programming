#include <bits/stdc++.h>
using namespace std;
const int MAX = 5005;
int N, M, K, Q, dsa[MAX][MAX], psa[MAX][MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M >> K;
    for(int i = 0, x, y, X, Y; i < K; i++) {
        cin >> x >> y >> X >> Y;
        dsa[x][y] += 1;
        dsa[X+1][y] -= 1;
        dsa[x][Y+1] -= 1;
        dsa[X+1][Y+1] += 1;
    }
    psa[0][0] = dsa[0][0];
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < M; j++) {
            psa[i][j] = dsa[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    cin >> Q;
    for(int i = 0, a, b, c, d; i < Q; i++) {
        cin >> a >> b >> c >> d;
        cout << (psa[c][d] - (psa[a-1][d] + psa[c][b-1] - psa[a-1][b-1])) << "\n";
    }
    return 0;
}
