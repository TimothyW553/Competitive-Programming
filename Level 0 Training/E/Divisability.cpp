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
 
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a*b / gcd(a, b); }
ll mul(ll a, ll b, ll M) { if (b == 0)return 0; ll t = mul(a, b / 2, M); if (b & 1)return (t + t + a) % M; return (t + t) % M; }
ll fpow(ll a, ll b, ll M) { if (b == 0)return 1; ll t = fpow(a, b / 2, M); if (b & 1)return mul(mul(t, t, M), a, M) % M; return mul(t, t, M) % M; }
ll divmod(ll i, ll j, ll mod) { i %= mod, j %= mod; return i*fpow(j, mod - 2, mod) % mod; }
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ll a, b, x, l, r; cin >> l >> r >> x;
    a = min(l, r);
    b = max(l, r);
    ll a_1 = a % x == 0 ? a : (a + x) - (a % x); // find closest number divisible by x greater than a
    ll a_n = b % x == 0 ? b : b - (b % x); // find closest number divisible by x smaller than b
    ll n = (a_n - a_1) / x + 1; // find number of terms using arithmetic formula
    ll ans = (n / 2.0)*(a_1 + a_n);
    cout << ans << "\n"; // sum of n terms formula
    return 0;
}