#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    int sum = 0, m;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> m;
            sum += m;
        }
    }
    if(sum != 6) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
    return 0;
}
