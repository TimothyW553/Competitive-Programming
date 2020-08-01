#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        cout << a+b << "\n";
    }
    return 0;
}
