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
const int MAX = 1 << 20;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

double a[MAX];
int arr[MAX];
bool cmp(const pair<double, int> &A, const pair<double, int> &B) {
    if(A.f != B.f) { return A.f < B.f; }
    return A.s < B.s;
}

void update(int u) {
    u += 10;
    while(u < MAX) {
        ++arr[u];
        u += u& - u;
    }
}

int query(int u) {
    u += 10;
    int ans = 0;
    while(u > 0) {
        ans += arr[u];
        u -= u& - u;
    }
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p; cin >> p;
    for(int i = 0; i < n; i++) {
        a[i] -= p;
        if(i > 0) { a[i] += a[i-1]; }
    }
    vector<pair<double, int>> v;
    for(int i = 0; i < n; i++) {
        v.pb({a[i], i});
    }
    v.pb({0, -1});
    sort(v.begin(), v.end(), cmp);
    int pos = 0;
    ll ans = 0;
    for(int i = 0; i < v.size(); i++) {
        while(pos < i && (v[i].f - v[pos].f) >= 0) { update(v[pos++].s); }
        ans += query(v[i].s);
    }
    cout << ans << "\n";
    return 0;
}
