#include <bits/stdc++.h>
using namespace std;

int N, K,
          a[100001];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a+N, greater<>());
    int sum = 0;
    for(int i = 0; i < K; i++) {
        if(a[i] < 0) { 
            break;
        }
        sum += a[i];
    }
    cout << sum << "\n";
    return 0;
}
