#include <bits/stdc++.h>
using namespace std;
const int MAX = 35;
int N; string f[MAX], s[MAX];
map<string, string> m1, m2;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> f[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < N; i++) {
        m1[f[i]] = s[i];
        m2[s[i]] = f[i];
    }
    for(auto &x : m1) {
        if(x.second != m2[x.first] or x.first == m2[x.first]) {
            return cout << "bad" << "\n", 0;
        }
    }
    cout << "good" << "\n";
    return 0;
}
