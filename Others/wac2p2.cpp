#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define c(a) count(a)

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;
typedef map<ll, ll> mpll;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1000000;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

pll greed[1000005] = {};
mpll mp = {};
ll last = MAX;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n, m, q; cin >> n >> m >> q;
    mp[n] = MAX;
    ll count = n;
    for(int i = 0; i < q; i++) {
        ll d, p; cin >> d >> p;
        if(!mp.c(d)) { mp[d] = last; }
        ll temp = count - d - 1;
        greed[i+1].f = last; greed[i+1].s = max(0LL, temp);
        count = d; last = p;
        mp[d] = min(mp[d], p);
    }
    greed[q+1].f = last; greed[q+1].s = count-1; q++;
    for(auto p : mp){
        greed[++q].f = p.s; greed[q].s = 1;
    }
    sort(greed+1, greed+1+q);
    ll ans = 0LL;
    for(int i = 0; i < q && m; i++) {
        ans += min(m, greed[i+1].s) * greed[i+1].f;
        m -= greed[i+1].s; m = max(0LL, m);
    }
    cout << ans << "\n";
    return 0;
}
