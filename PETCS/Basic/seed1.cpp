#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    mp['B'] = 0, mp['F'] = 0, mp['T'] = 0, mp['L'] = 0, mp['C'] = 0;
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    bool flag = true;
    for(auto &x : mp) {
        if(x.second == 0) {
            flag = false;
            cout << x.first;
        }
    }
    if(flag) {
        cout << "NO MISSING PARTS" << "\n";
    }
    return 0;
}
