#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    ll lo = 1, hi = 2*1e9;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        cout << mid << "\n";
        string s; cin >> s;
        if(s == "SINKS") {
            lo = mid + 1;
        } else if(s == "FLOATS") {
            hi = mid - 1;
        } else {
            break;
        }
    }
    return 0;
}
