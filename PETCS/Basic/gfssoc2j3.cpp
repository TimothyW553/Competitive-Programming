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
    int ans; cin >> ans;
    while(1) {
        string s; cin >> s;
        if(s == "=") {
            return cout << ans << "\n", 0;
        } 
        if(s == "P") {
            cin >> n;
            ans += n;
        } else if(s == "M") {
            cin >> n;
            ans -= n;
        }
    }
    return 0;
}
