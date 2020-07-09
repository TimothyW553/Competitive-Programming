#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    int countW = 0;
    char c;
    for(int i = 0; i < 6; i++) {
        cin >> c;
        if(c == 'W') {
            countW++;
        }
    }
    int ans = -1;
    if(countW == 5 or countW == 6) {
        ans = 1;
    } else if(countW == 3 or countW == 4) {
        ans = 2;
    } else if(countW == 1 or countW == 2) {
        ans = 3;
    }
    cout << ans << "\n";
    return 0;
}
