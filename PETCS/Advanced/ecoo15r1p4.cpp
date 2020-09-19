#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1000005;
string s; ll dp[MAX];
bool valid(string s) {
    if(s.size() == 2 && s == "ug") { return true; }
    if(s.size() == 3 && (s == "ook" || s == "oog")) { return true; }
    if(s.size() == 4 && (s == "ooga" || s == "mook" || s == "ugug")) { return true; }
    if(s.size() == 5 && (s == "oogam" || s == "oogum")) { return true; }
    if(s.size() == 6 && s == "ookook") { return true; }
    if(s.size() == 8 && s == "mookmook") { return true; }
}
void solve() {
    cin >> s;
    fill(dp, dp+s.size(), 0);
    for(int i = 0; i < s.size(); i++) {
        for(int j = 2; j <= 8; j++) {
            if(valid(s.substr(i, j))) {
                if(i == 0) {
                    dp[i+j-1]++;
                } else {
                    dp[i+j-1] += dp[i-1];
                }
            }
        }
    }
    cout << dp[s.length()-1] << "\n";
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    for(int i = 0; i < 2; i++) {
        solve();
    }
    return 0;
}
