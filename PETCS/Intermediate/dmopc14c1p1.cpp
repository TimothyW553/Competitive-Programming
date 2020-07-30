#include <bits/stdc++.h>
using namespace std;
int N; vector<int> v;
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
    if(v.size() % 2 == 1) {
        cout << v[v.size()/2] << "\n";
    } else {
        double med = (v[v.size()/2]+v[v.size()/2-1])/2.0;
        cout << round(med) << "\n";
    }
    return 0;
}
