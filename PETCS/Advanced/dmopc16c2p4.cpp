#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, pows[30];
ll binarySearch(int n) {
    ll lo = 0, hi = pows[25];
    while(lo < hi) {
        ll mid = lo + (hi - lo) / 2; // mid is our x
        ll cnt = 0;
        // number of trailing zeros
        // f(x) = sigma(i=1, INF): floor(x / 5^i)
        for(int i = 1;; i++) {
            if(pows[i] > mid) { // dont need to compute anymore because its ~0
                break;
            }
            cnt += mid/pows[i]; // calculate the number of zeros
        }
        if(cnt < n) { // if the number of zeroes is too little
            lo = mid + 1; // look to right side
        } else {
            hi = mid; // look to left side
        }
    }
    return lo;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> A >> B;
    pows[0] = 1;
    for(int i = 1; i <= 25; i++) {
        pows[i] = (ll)5*pows[i-1];
    }
    ll n1 = binarySearch(A), n2 = binarySearch(B+1);
    if(A == 0) {
        n1 = 1;
    }
    cout << n2 - n1 << "\n";
    return 0;
}