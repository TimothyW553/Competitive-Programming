#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
bool isp(ll n) {
    if(n <= 1) {
        return false;
    }
    for(ll i = 2; i <= sqrt(n); i++) {
        if(n % 2 == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    while(1) {
        N++;
        if(isp(N)) {
            return cout << N << "\n", 0;
        }
    }
    return 0;
}
