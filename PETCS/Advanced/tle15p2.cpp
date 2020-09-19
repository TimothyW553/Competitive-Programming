#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
ll N, M, T, ans = INF; vector<pair<ll, ll>> v; multiset<ll> s;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M >> T;
    for(int i = 0; i < N; i++) {
        s.insert(0);
    }
    for(int i = 0, t, f; i < M; i++) {
        cin >> t >> f;
        v.push_back({t, f});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < M; i++) {
        multiset<ll>::iterator it = s.upper_bound(v[i].first);
        if(it != s.begin()) {
            it--;
        }
        ll tm = *it;
        if(v[i].first - tm >= T) {
            ans = min(ans, tm);
        }
        tm = max(tm, v[i].first);
        s.erase(it);
        s.insert(tm+v[i].second);
    }
    ans = min(ans, *s.begin());
    cout << ans << "\n";
    return 0;
}
