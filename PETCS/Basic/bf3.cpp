#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(ll n) {
    if(n <= 1) {
        return false;
    }
    for(ll i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

ll n;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> n;
    while(1) {
        if(isprime(n)) {
            return cout << n << "\n", 0;
        }
        n++;
    }
    return 0;
}
