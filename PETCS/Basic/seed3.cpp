#include <bits/stdc++.h>
using namespace std;

const int MM = 100005;

int I, N, J, dsa[MM], psa[MM];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> I >> N >> J;
    int Xi, Xf, K;
    for(int i = 0; i < J; i++) {
        // do the range query stuff
        cin >> Xi >> Xf >> K;
        dsa[Xi] += K;
        dsa[Xf+1] -= K;
    }
    // construct psa of dsa
    for(int i = 1; i <= I; i++) {
        psa[i] = psa[i-1] + dsa[i];
    }
    int cnt = 0;
    for(int i = 1; i <= I; i++) {
        if(psa[i] < N) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
