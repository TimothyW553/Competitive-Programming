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

vector< pair<int, pii> > adj[2001];
int dist[2001][201];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int K, N, M; cin >> K >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, t, h; cin >> a >> b >> t >> h;
        adj[a].push_back({b, {t, h}});
        adj[b].push_back({a, {t, h}});
    }
    int A, B; cin >> A >> B;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    int ans = 0;
    priority_queue<pair<pii, int>, vector< pair<pii, int>>, greater<pair<pii, int>>> pq;
    pq.push({{0, 0}, A});
    dist[A][0] = 0;
    while (!pq.empty()) {
        pair<pii, int> x = pq.top();
        pq.pop();
        int h0 = x.f.s; int u = x.s;
        for (pair<int, pii> n : adj[u]) {
            int v = n.f; int t = n.s.first; int h = n.s.s;
            if (dist[u][h0] + t < dist[v][h + h0] && h + h0 < K) {
                dist[v][h + h0] = dist[u][h0] + t;
                pq.push({{dist[v][h + h0], h + h0}, v});
            }
        }
    }
    int minN = INT_MAX;
    for (int i = 0; i < K; i++) {
        minN = min(minN, dist[B][i]);
    }
    ans = minN;
    cout << (ans == INT_MAX ? -1 : ans) << "\n";

    return 0;
}
