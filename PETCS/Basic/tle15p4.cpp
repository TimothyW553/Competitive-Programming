#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 13;
const int MAX = 1e5 + 5;

ll pow(ll a, ll b) {
    if(b == 0) { return 1; }
    if(b % 2 == 0) { return a*(pow(a*a % MOD, b/2) % MOD) % MOD; }
    return pow(a*a % MOD, b/2) % MOD;
}

int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ll n; cin >> n;
    ll ans = 0;
    if(n <= 3) {
        cout << 1 << "\n";
    } else {
        ans = pow(2, n-2); // first part 2^n / 2^2 = 2^n-2
        if(n % 8 == 0) {
            ans += pow(2, n/2-1);
        } else if(n % 8 == 1 or n % 8 == 7) {
            ans += pow(2, (n+1)/2 - 2);
        } else if(n % 8 == 3 or n % 8 == 5) {
            ans -= pow(2, (n+1)/2-2);
            if(ans < MOD) { ans += MOD; }
        } else if(n % 8 == 4) {
            ans -= pow(2, (n/2-1));
        }
        ans %= MOD;
        if(ans < 0) { ans += MOD; }
        cout << ans << "\n";
    }
    return 0;
}
