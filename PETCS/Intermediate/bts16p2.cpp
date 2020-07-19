#include <bits/stdc++.h>
using namespace std;
int N;
map<bool, pair<bool, int>> mp;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    mp[0].first = 0; mp[1].first = 0;
    mp[0].second = 1; mp[1].second = 1;
    for(int i = 0, m; i < N; i++) {
        cin >> m;
        if(m == 1) {
            string s; cin >> s; bool flag = (s == "true");
            if(mp[flag].first) {
                cout << "false" << "\n";
            } else {
                cout << "true" << "\n";
                mp[flag].first = 1;
                if(!mp[!flag].first) {
                    mp[flag].second = 0;
                } else if(mp[!flag].first) {
                    mp[!flag].second = 0;
                    mp[flag].second = 1;
                }
            }
        } else if(m == 2) {
            string s; cin >> s; bool flag = (s == "true");
            if(mp[flag].first) {
                cout << "true" << "\n";
                mp[flag].first = 0;
                if(mp[flag].second == 0) {
                    mp[!flag].second = 0;
                }
            } else {
                cout << "false" << "\n";
            }
        } else if(m == 3) {
            string s; cin >> s; bool flag = (s == "true");
            if(mp[flag].first) {
                cout << mp[flag].second << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else if(m == 4) {
            if(mp[false].first) {
                cout << "false ";
            } 
            if(mp[true].first) {
                cout << "true ";
            }
            cout << "\n";
        }
    }
    return 0;
}
