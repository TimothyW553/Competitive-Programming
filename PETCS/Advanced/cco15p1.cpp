#include <bits/stdc++.h>
using namespace std;
int N, W; vector<int> v;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> W;
    for(int i = 0, t; i < N; i++) {
        cin >> t;
        v.push_back(t);
    }
    int minVal = W, maxVal = W;
    sort(v.begin(), v.end());
    // TODO: SOLVE THIS PROBLEM!
    return 0;
}
