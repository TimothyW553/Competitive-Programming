#include <bits/stdc++.h>
using namespace std;

int x, y, n;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> x >> y >> n;
    cout << int(x/(1.0*n))*int(y/(1.0*n)) << "\n";
    return 0;
}
