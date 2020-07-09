#include <bits/stdc++.h>
using namespace std;
const int MM = 1000005;
int N, A, B, arr[MM];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> A >> B;
    int a, b;
    for(int i = 0; i < A; i++) {
        cin >> a;
        arr[a]++;
    }
    int cnt = 0;
    for(int i = 0; i < B; i++) {
        cin >> b;
        if(arr[b] == 1) {
            cnt++;
        }
    }
    cout << N-cnt << "\n";
    return 0;
}