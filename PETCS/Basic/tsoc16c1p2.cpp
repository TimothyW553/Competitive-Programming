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
    string type;
    if(s.find(".") == -1) {
        cin >> type;
        cout << "\"" << s << "\" - ";
        for(auto &c : type) {
            cout << (char)tolower(c);
        }
    } else {
        int idx = -1;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == '.') {
                idx = i;
                break;
            }
        }
        cout << "\"";
        for(int i = 0; i < idx; i++) {
            cout << s[i];
        }
        cout << "\" - ";
        for(int i = idx+1; i < s.size(); i++) {
            cout << s[i];
        }
    }
    return 0;
}
