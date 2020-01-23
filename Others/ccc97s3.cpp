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
const int MAX = 1e5 + 5;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n; cin >> n;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        ll ud = x, ol = 0LL, el = 0LL;
        ll count = 0;
        while(true) {
            printf("Round %lld: %lld undefeated, %lld one-loss, %lld eliminated\n", count, ud, ol, el);
            if(ud == 0LL and  ol == 1LL) { break; }
            if(ud == 1LL and ol == 1LL) {
                el = el;
                ol = 2LL;
                ud = 0LL;
            } else {
                el = el + ol / 2LL;
                ol = ol - (ol / 2LL) + (ud / 2LL);
                ud = ud - (ud / 2LL);
            }
            count++;
        }
        printf("There are %lld rounds.\n", count);
    }
    return 0;
}
