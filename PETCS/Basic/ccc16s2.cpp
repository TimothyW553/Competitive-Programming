#include <bits/stdc++.h>
using namespace std;

int Q, N,
          d[101], p[101];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> Q >> N;
    for(int i = 0; i < N; i++) {
        cin >> d[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    int sum = 0;
    if(Q == 1) { // minimum
        sort(d, d+N);
        sort(p, p+N);
        for(int i = 0; i < N; i++) {
            sum += max(p[i], d[i]);
        }
    } else { // maximum
        sort(d, d+N);
        sort(p, p+N, greater<>());
        for(int i = 0; i < N; i++) {
            sum += max(p[i], d[i]);
        }
    }
    cout << sum << "\n";
    return 0;
}
