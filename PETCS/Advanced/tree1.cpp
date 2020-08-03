#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        int row = 0;
        for(int j = 0, m; j < 4; j++) {
            cin >> m;
            row += m;
            sum += m;
        }
        if(row == 0) {
            return cout << "No" << "\n", 0;
        }
    }
    if(sum == 6) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}
