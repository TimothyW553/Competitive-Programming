#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll N, M, a[MAX], b[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == 0) {
                b[j] = b[j-1] + a[j-1];
            } else {
                b[j] += b[j-1];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        cout << b[i]%MOD << " ";
    }
    return 0;
}
