#include <bits/stdc++.h>
using namespace std;

int N, M,
          arr[100005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    int ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        ans += arr[i];
    }
    cin >> M;
    int a, d;
    for(int i = 0; i < M; i++) {
        cin >> a >> d;
        ans -= min(min(arr[a], arr[a-1]), d);
    }
    cout << ans << "\n";
    return 0;
}
