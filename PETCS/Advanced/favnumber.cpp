#include <bits/stdc++.h>
using namespace std;
int N, Q; vector<int> v;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, m; i < N; i++) {
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    cin >> Q;
    for(int i = 0, q; i < Q; i++) {
        cin >> q;
        auto pos = lower_bound(v.begin(), v.end(), q)-v.begin();
        int num = v[pos];
        cout << num << " " << (upper_bound(v.begin(), v.end(), num)-v.begin()-pos) << "\n";
    }
    return 0;
}
