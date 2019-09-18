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
const int MAXN = 400010;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int N, len[MAXN], ansL;
long long cnt[MAXN], ansC;
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int u){
    vis[u] = 1; len[u] = 0; cnt[u] = 1;
    for (int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if (vis[v]) {
            continue;
        }
        dfs(v);
        if (len[u]+len[v]+1 > ansL){
            ansL = len[u]+len[v]+1;
            ansC = cnt[u]*cnt[v];
        }
        else if (len[u]+len[v]+1 == ansL) ansC += cnt[u]*cnt[v];
        if (len[v]+1 > len[u]){
            len[u] = len[v]+1;
            cnt[u] = cnt[v];
        }
        else if (len[v]+1 == len[u]) {
            cnt[u] += cnt[v];
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m = n - 1;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    cout << ansL+1 << " " << ansC << "\n";
    return 0;
}
