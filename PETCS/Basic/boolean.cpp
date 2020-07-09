#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    int count = 0;
    string s;
    while(cin >> s) {
        if(s == "not") {
            count++;
        } else if(s == "True" and count % 2 == 0) {
            cout << "True" << "\n";
        } else if(s == "True" and count % 2 == 1) {
            cout << "False" << "\n";
        } else if(s == "False" and count % 2 == 0) {
            cout << "False" << "\n";
        } else {
            cout << "True" << "\n";
        }
    }
    return 0;
}
