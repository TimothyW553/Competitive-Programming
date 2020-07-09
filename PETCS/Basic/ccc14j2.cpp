#include <bits/stdc++.h>
using namespace std;

int v;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> v;
    string s; cin >> s;
    int countA = 0, countB = 0;
    for(int i = 0; i < v; i++) {
        if(s[i] == 'A') {
            countA++;
        } else {
            countB++;
        }
    }
    if(countA > countB) {
        cout << "A" << "\n";
    } else if(countB > countA) {
        cout << "B" << "\n";
    } else {
        cout << "Tie" << "\n";
    }
    return 0;
}
