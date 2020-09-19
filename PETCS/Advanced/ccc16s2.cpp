#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int Q, N, ans = 0, peg[MAX], dmoj[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> Q >> N;
    for(int i = 0; i < N; i++) {
        cin >> dmoj[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> peg[i];
    }
    sort(dmoj, dmoj+N);
    if(Q == 1) {
        sort(peg, peg+N);
    } else {
        sort(peg, peg+N, greater<>());
    }
    for(int i = 0; i < N; i++) {
        ans += max(dmoj[i], peg[i]);
    }
    cout << ans << "\n";
    return 0;
}
