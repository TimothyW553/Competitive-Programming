#include <bits/stdc++.h>
using namespace std;

int n,
       a[1001];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
