#include <bits/stdc++.h>
using namespace std;

int N, X, Y, 
             a[1005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int m, s; 
    for(int i = 0; i < N; i++) {
        cin >> m >> s;
        a[i] = 60*m + s;
    }
    cin >> X >> Y;
    int tot = 60*X + Y;
    sort(a, a+N);
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(tot - a[i] >= 0) {
            tot -= a[i];
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
