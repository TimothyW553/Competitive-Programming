#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int N, a[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0, m; j < N; j++) {
            cin >> m;
            a[i] |= m;
            a[j] |= m;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
