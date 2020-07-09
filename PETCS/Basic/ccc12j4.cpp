#include <bits/stdc++.h>
using namespace std;

int K;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> K;
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i] - (3*(i+1)+K);
        if(c < 'A') {
            cout << char(c+26);
        } else {
            cout << char(c);
        }
    }
    return 0;
}
