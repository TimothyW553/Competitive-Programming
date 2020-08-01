#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
string s; int Q, psa[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> s >> Q;
    psa[0] = (s[0] == 'G');
    for(int i = 1; i < s.length(); i++) {
        psa[i] = psa[i-1] + (s[i] == 'G');
    }
    for(int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        cout << psa[b]-psa[a-1] << "\n";
    }
    return 0;
}
