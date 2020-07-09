#include <bits/stdc++.h>
using namespace std;

int x, y;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> x >> y;
    for(int i = x; i <= y; i++) {
        if((i-x) % 60 == 0) {
            cout << "All positions change in year " << i << "\n";
        }
    }
    return 0;
}
