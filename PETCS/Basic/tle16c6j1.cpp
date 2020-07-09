#include <bits/stdc++.h>
using namespace std;

int N, M, A;
int v[2005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M >> A;
    int x, y;
    for(int i = 0; i < A; i++) {
        cin >> x >> y;
        v[x] = y;
    }
    for(int i = 0; i < 100000; i++) {
        if(N < 0) {
            return cout << "The printer melts at " << i << " second(s)." << "\n", 0;
        }
        N += v[i];
        if(N > M) {
            return cout << "The printer jams at " << i << " second(s)." << "\n", 0;
        }
        N--;
    }
    return 0;
}
