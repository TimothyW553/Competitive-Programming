#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int N, Q, arr[MAX], psa[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++) {
        psa[i] = psa[i-1] + arr[i-1];
    }
    cin >> Q;
    for(int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        cout << psa[b+1]-psa[a] << "\n";
    }
    return 0;
}
