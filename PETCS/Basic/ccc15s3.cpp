#include <bits/stdc++.h>
using namespace std;

int G, P;
set<int> gates;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> G >> P;
    for(int i = 1; i <= G; i++) {
        gates.insert(-i);
    }
    int g;
    for(int i = 0; i < P; i++) {
        cin >> g;
        auto x = gates.lower_bound(-g);
        if(x == gates.end()) {
            return cout << i << "\n", 0;
        }
        gates.erase(x);
    }
    cout << P << "\n";
    return 0;
}
/*
For this question we use -i and -g because lower_bound looks for something greater than or equal to
so it will search from -g to -1 basically or gates 1 to g
*/