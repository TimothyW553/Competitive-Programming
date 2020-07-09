#include <bits/stdc++.h>
using namespace std;

int t, c,
          chores[101];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> t >> c;
    for(int i = 0; i < c; i++) {
        cin >> chores[i];
    }
    sort(chores, chores+c);
    int count = 0;
    for(int i = 0; i < c; i++) {
        if(t - chores[i] >= 0) {
            t -= chores[i];
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
