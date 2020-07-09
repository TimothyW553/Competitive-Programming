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
    cin.ignore();
    int countT = 0, countS = 0;
    while(n--) {
        string s; getline(cin, s);
        for(auto &c : s) {
            if(tolower(c) == 't') {
                countT++;
            } else if(tolower(c) == 's') {
                countS++;
            }
        }
    }
    string ans = "French";
    if(countT > countS) {
        ans = "English";
    }
    cout << ans << "\n";
    return 0;
}
