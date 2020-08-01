#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int I, N, J, cnt = 0, dsa[MAX], psa[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> I >> N >> J;
    for(int i = 0, xi, xf, k; i < J; i++) {
        cin >> xi >> xf >> k;
        dsa[xi] += k;
        dsa[xf+1] -= k;
    }
    for(int i = 1; i <= I; i++) {
        psa[i] = psa[i-1] + dsa[i];
    }
    for(int i = 1; i <= I; i++) {
        cnt += (psa[i] < N);
    }
    cout << cnt << "\n";
    return 0;
}
