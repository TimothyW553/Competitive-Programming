#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000013LL;
ll N;
ll pwr(ll b, ll e) {
    if(e == 0) {
        return 1;
    } else if(e % 2 == 0) {
        return pwr((b*b) % MOD, e / 2) % MOD;
    } else {
        return (b*pwr((b*b) % MOD, e / 2)) % MOD;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    if(N == 1) {
        return cout << 1 << "\n", 0;
    }
    if(N % 8 == 0) {
        cout << (pwr(2, N-2) + pwr(2, N/2-1)) % MOD << "\n";
    } else if(N % 8 == 1 or N % 8 == 7) {
        cout << (pwr(2, N-2) + pwr(2, (N+1)/2 - 2)) % MOD << "\n";
    } else if(N % 8 == 2 or N % 8 == 6) {
        cout << (pwr(2, N-2)) % MOD << "\n";
    } else if(N % 8 == 3 or N % 8 == 5) {
        cout << (MOD + pwr(2, N-2) - pwr(2, (N+1)/2 - 2)) % MOD << "\n";
    } else if(N % 8 == 4) {
        cout << (MOD + pwr(2, N-2) - pwr(2, N/2-1)) % MOD  << "\n";
    }
    return 0;
}
