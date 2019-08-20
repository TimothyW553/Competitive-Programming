#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
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
    char c;
    int h1, m1, s1; cin >> h1 >> c >> m1 >> c >> s1;
    int h2, m2, s2; cin >> h2 >> c >> m2 >> c >> s2;

    int hr = h2 - h1;
    int mn = m2 - m1;
    int sc = s2 - s1;

    while(sc < 0)  { sc += 60; mn -= 1; }
    while(sc > 59) { sc -= 60; mn += 1; }

    while(mn < 0)  { mn += 60; hr -= 1; }
    while(mn > 59) { mn -= 60; hr += 1; }

    while(hr < 0)  { hr += 24; }
    while(hr > 59) { hr -= 24; }

    if(hr == 0 && mn == 0 && sc == 0) hr = 24;

    printf("%02d:%02d:%02d\n", hr, mn, sc);
    return 0;
}
