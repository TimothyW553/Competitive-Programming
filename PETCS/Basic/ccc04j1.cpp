#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> n;
    cout << "The largest square has side length " << floor(sqrt(n)) << ".\n";
    return 0;
}
