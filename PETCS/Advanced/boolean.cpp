#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    string s;
    int cnt = 0;
    while (cin >> s) {
        if (s == "not") {
            cnt++;
        }
        if (s != "not") {
            if (cnt % 2 == 0) {
                cout << s << "\n";
            } else {
                if (s == "True") {
                    cout << "False" << "\n";
                } else {
                    cout << "True" << "\n";
                }
            }
        }
    }
    return 0;
}
