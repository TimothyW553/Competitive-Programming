#include <bits/stdc++.h>
using namespace std;

int N, Q, tot, psa[500005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> Q;
    int k;
    for(int i = 1; i <= N; i++) {
        cin >> k;
        psa[i] = psa[i-1] + k;
        tot += k;
    }
    int a, b;
    while(Q--) {
        cin >> a >> b;
        cout << tot-(psa[b]-psa[a-1]) << "\n";
    }
    return 0;
}
