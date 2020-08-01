#include <bits/stdc++.h>
using namespace std;
int N; vector<string> a[26];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        a[int(s[0]-'a')].push_back(s);
    }
    for(int i = 0; i < 26; i++) {
        sort(a[i].begin(), a[i].end());
        for(int j = 0; j < a[i].size(); j++) {
            if(j == a[i].size()-1) {
                cout << a[i][j] << "\n";
            } else {
                cout << a[i][j] << ", ";
            }
        }
    }
    return 0;
}
