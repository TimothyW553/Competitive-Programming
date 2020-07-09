#include <bits/stdc++.h>
using namespace std;
const int MM = (int)1e6+5;
int N, C;
int deg[MM];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> C;
    int a, b;
    for(int i = 0; i < C; i++) {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    int max_val = -1, idx = -1;
    for(int i = 0; i <= N; i++) {
        if(deg[i] >= max_val) {
            max_val = deg[i];
            idx = i;
        }
    }
    cout << idx << "\n";
    return 0;
}
