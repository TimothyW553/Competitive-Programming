#include <bits/stdc++.h>
using namespace std;

int Q;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    string s; cin >> s;
    int psa[s.size()+1];
    for(int i = 1; i <= s.size(); i++) {
        psa[i] = psa[i-1] + (s[i-1] == 'G');
    }
    cin >> Q;
    int i, j;
    while(Q--) {
        cin >> i >> j;
        cout << psa[j+1] - psa[i] << "\n";
    }
    return 0;
}
