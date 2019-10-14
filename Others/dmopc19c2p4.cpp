#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2005;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

ll dp[MAX][MAX], arr[MAX];
void knapsack(ll n, ll t, ll a, ll b) {
    dp[0][0] = 1;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < t+1; j++) {
            dp[i+1][j] = dp[i][j];
            if(j >= arr[i+1] and i+1 != a and i+1 != b) {
                dp[i+1][j] += dp[i][j-arr[i+1]];
                dp[i+1][j] %= MOD;
            }
        }
    }  
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n, t, q; cin >> n >> t >> q;
    for(ll i = 1; i < n+1; i++) { cin >> arr[i]; }
    for(ll qq = 0; qq < q; qq++) {
        ll a, b, w; cin >> a >> b >> w;
        knapsack(n, t, a, b);
        ll bg = w-arr[a]-arr[b];
        ll ans = 0;
        for(ll i = 0; i < bg+1; i++) { ans += dp[n][i]; }
        cout << ans % MOD << "\n";
    }
    return 0;
}