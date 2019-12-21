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

int arr[MAX];
vector<int> adj[MAX];
bool pho[MAX];
bool vis[MAX];
bool onPath[MAX];
int dist[MAX];

// search all paths
void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v] && onPath[v]) {
            vis[v] = true;
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

// find if connected
bool unionFind(int u, int prev) {
    if (pho[u]) { onPath[u] = true; }
    for (int v : adj[u]) {
        if (v != prev) { onPath[u] |= unionFind(v, u); }
    }
    return onPath[u]; // compression
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int N, M; cin >> N >> M;
    int n; 
    for (int i = 0; i < M; i++) {
        cin >> n;
        pho[n] = true;
    }

    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < N; i++) {
        if (pho[i]) { unionFind(i, -1); break; }
    }
    int cnt = N;
    FILL(vis, 0);
    n = 0;
    for (int i = 0; i < N; i++) {
        if (onPath[i]) { n = i; break; }
    }
    dist[n] = 0;
    vis[n] = true;
    dfs(n);
    for (int i = n; i < N; i++) {
        if (onPath[i] && dist[i] > dist[n]) { n = i; }
    }
    FILL(vis, 0);
    dist[n] = 0;
    vis[n] = true;
    dfs(n);

    int diam = 0;
    for (int i = 0; i < N; i++) {
        if (onPath[i]) { diam = max(diam, dist[i]); }
        else { cnt--; }
    }
    int ans = 2 * (cnt - 1) - diam;
    cout << ans << "\n";
    return 0;
}