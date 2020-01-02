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
const int MAX = 3005;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

pair<ll, ll> vals[MAX];
ll adj[MAX][MAX];
ll dist[MAX];
bool vis[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y;
        vals[i] = {x, y};
    }
    for (ll i = 1; i < n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            ll x = abs(vals[i].f - vals[j].f);
            ll y = abs(vals[i].s - vals[j].s);
            ll w = pow(x, 2) + pow(y, 2);
            adj[i][j] = w;
            adj[j][i] = w;
        }
    }
    ll x, q; cin >> x >> q;
    FILL(dist, INF);
    FILL(vis, false);
    dist[x] = 0;
    for (ll tt = 1; tt <= n; tt++) {
        ll u = 0;
        for (ll i = 1; i <= n; i++) {
            if (!vis[i] && dist[i] < dist[u]) {
                u = i;
            }
        }
        vis[u] = true;
        for (ll v = 1; v <= n; v++) {
            ll w = adj[u][v];
            if (!vis[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    sort(dist, dist+n+1);
    while (q--) {
        int query; cin >> query;
        cout << upper_bound(dist, dist + n + 1, query) - dist << "\n";
    }
    return 0;
}