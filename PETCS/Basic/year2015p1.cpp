#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    string s; getline(cin, s);
    cin >> N;
    string name;
    while(N--) {
        cin >> name;
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '>') {
                ans += s[i];
            } else if(s[i] == '>') {
                ans += name;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
