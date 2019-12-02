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

ll n, k; string str;
ll num[26] = {};
ll arr[16] = {};

ll f(ll right, ll left) {
    if(right == 0) {
        ll ans = arr[n];
        for(int i = 0; i < 26; i++) { ans /= arr[num[i]]; }
        return ans;
    }
    ll ans = 0;
    for(int i = left; i < 26; i++) { num[i]++; ans += f(right - 1, i); num[i]--; }
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    arr[0] = 1LL;
    for(int i = 1; i < 16; i++) {
        arr[i] = arr[i-1]*i;
    }
    cin >> n >> k >> str;
    for(int i = 0; i < n; i++) {
        if(str[i] != '*') {
            ll idx = str[i] - 97;
            num[idx]++;
        }
    }
    cout << f(k, 0) << "\n";
    return 0;
}
