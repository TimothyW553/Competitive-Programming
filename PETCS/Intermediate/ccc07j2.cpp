#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;
string shrt[12] = {"CU", ":-)", ":-(", ";-)", ":-P", "(~.~)", "TA", "CCC", "CUZ", "TY", "YW", "TTYL"};
string tran[12] = {"see you", "I'm happy", "I'm unhappy", "wink", "stick out my tongue", "sleepy", "totally awesome", "Canadian Computing Competition", "because", "thank-you", "you're welcome", "talk to you later"};
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0; i < 12; i++) {
        mp[shrt[i]] = tran[i];
    }
    string s;
    while(1) {
        cin >> s;
        if(mp.count(s)) {
            cout << mp[s] << "\n";
        } else {
            cout << s << "\n";
        }
        if(s == "TTYL") {
            break;
        }
    }
    return 0;
}
