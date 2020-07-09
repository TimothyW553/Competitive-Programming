#include <bits/stdc++.h>
using namespace std;

int N,
       psa1[100005], psa2[100005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int m;
    for(int i = 1; i <= N; i++) {
        cin >> m;
        psa1[i] = psa1[i-1] + m;
    }
    for(int i = 1; i <= N; i++) {
        cin >> m;
        psa2[i] = psa2[i-1] + m;
    }
    for(int i = N; i >= 0; i--) {
        if(psa1[i] == psa2[i]) {
            return cout << i << "\n", 0;
        }
    }
    return 0;
}
