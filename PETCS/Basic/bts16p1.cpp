#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    string s; getline(cin, s);
    int countCap = 0, countLow = 0;
    for(int i = 0; i < s.size(); i++) {
        if(isupper(s[i])) {
            countCap++;
        } else if(islower(s[i])) {
            countLow++;
        }
    }
    if(countCap > countLow) {
        for(int i = 0; i < s.size(); i++) {
            cout << (char)toupper(s[i]);
        }
    } else if(countLow > countCap) {
        for(int i = 0; i < s.size(); i++) {
            cout << (char)tolower(s[i]);
        }
    } else {
        cout << s;
    }
    return 0;
}
