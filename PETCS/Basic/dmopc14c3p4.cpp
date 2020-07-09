#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int T, f[MAX];
vector<int> cnt[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    for(int i = 1; i < MAX; i++) {
        for(int j = i; j < MAX; j += i) {
            f[j]++;
        }
        cnt[f[i]].push_back(i);
    }
    cin >> T;
    int K, A, B;
    while(T--) {
        cin >> K >> A >> B;
        auto ib = upper_bound(cnt[K].begin(), cnt[K].end(), B);
        auto ia = lower_bound(cnt[K].begin(), cnt[K].end(), A);
        cout << ib-ia << "\n";
    }
    return 0;
}
