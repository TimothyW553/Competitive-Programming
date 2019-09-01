#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int m; cin >> m;
        mp[m]++; // count the frequences
    }
    int count = 0;
    for(auto &x : mp) {
        if(x.second >= 2) {
            if(x.second % 2 == 0) { count += x.second / 2; }
            else if(x.second % 2 == 1) { count += (x.second - 1) / 2; }
        }
    }
    cout << count << "\n";
    return 0;
}
