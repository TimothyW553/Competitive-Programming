#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, srcX, srcY; ll ans = 0; vector<pair<int, int>> aX, aY;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        aX.push_back({x, y});
        aY.push_back({y, x});
    }
    sort(aX.begin(), aX.end());
    sort(aY.begin(), aY.end());
    cin >> M >> srcX >> srcY;
    for(int i = 1, x, y; i < M; i++) {
        cin >> x >> y;
        if(x != srcX) {
            ans += (upper_bound(aY.begin(), aY.end(), make_pair(y, max(srcX, x))))
                 - (lower_bound(aY.begin(), aY.end(), make_pair(y, min(srcX, x))));
            cout << (upper_bound(aY.begin(), aY.end(), make_pair(y, max(srcX, x))))
                 - (lower_bound(aY.begin(), aY.end(), make_pair(y, min(srcX, x)))) << "\n";
        } else {    
            ans += (upper_bound(aX.begin(), aX.end(), make_pair(x, max(srcY, y))))
                 - (lower_bound(aX.begin(), aX.end(), make_pair(x, min(srcY, y))));
            cout << (upper_bound(aX.begin(), aX.end(), make_pair(x, max(srcY, y))))
                 - (lower_bound(aX.begin(), aX.end(), make_pair(x, min(srcY, y)))) << "\n";
        }
        srcX = x;
        srcY = y;
    }
    cout << ans << "\n";
    return 0;
}
