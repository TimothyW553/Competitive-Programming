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
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        map<string, int> mp;
        int idx = 1;
        while(1) {
            string str; getline(cin, str);
            if(str == "") {
                break;
            }
            istringstream iss(str);
            vector<string> s{istream_iterator<string>{iss}, istream_iterator<string>{}};
            for(int i = 0; i < s.size(); i++) {
                if(mp[s[i]] == 0) {
                    mp[s[i]] = idx;
                    cout << s[i] << " ";
                    idx++;
                } else {
                    cout << mp[s[i]] << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
