#include <bits/stdc++.h>
using namespace std;

int N, Q, 
          psa[1000005];
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
        psa[i] = psa[i-1] + m;
    }
    cin >> Q;
    int a, b;
    while(Q--) {
        cin >> a >> b;
        cout << psa[b+1]-psa[a] << "\n";
    }
    return 0;
}
