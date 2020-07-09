#include <bits/stdc++.h>
using namespace std;

const int MM = (int)1e9+5;

int N, Q;
vector<int> v;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int m;
    for(int i = 0; i < N; i++) {
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end()); // sort it so we can use binary search
    cin >> Q;
    int qq;
    while(Q--) {
        cin >> qq;
        int idx = lower_bound(v.begin(), v.end(), qq)-v.begin(); // find idx of closest number to qq
        int ans = v[idx]; // we use lower_bound because upper returns +1 and something weird
        cout << ans << " " << upper_bound(v.begin(), v.end(), ans) - lower_bound(v.begin(), v.end(), ans) << "\n";
        // the difference between upper(last value idx) and lower(first value idx) is the freq of the num
    }
    return 0;
}

/*
lower_bound: returns first instance (>=) val
upper_bound: returns first instance (>) val
*/