#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, t;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> a >> b >> c >> d >> t;
    int dist = abs(d-b) + abs(c-a);
    if(dist <= t and (dist-t)%2 == 0) {
        cout << "Y" << "\n";
    } else {
        cout << "N" << "\n";
    }
    return 0;
}
