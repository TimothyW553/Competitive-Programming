#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int m, res = 0;
    for(int i = 0; i < N; i++) {
        cin >> m;
        res ^= m;
    }
    cout << res << "\n";
    return 0;
}
