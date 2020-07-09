#include <bits/stdc++.h>
using namespace std;

int t1, t2;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> t1 >> t2;
    int count = 2;
    while(t1 - t2 > 0) {
        int t3 = t1 - t2;
        t1 = t2;
        t2 = t3;
        count++;
    }
    cout << count << "\n";
    return 0;
}
