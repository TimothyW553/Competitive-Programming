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
const int MAX = 25;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

struct Node {
    pii f_n, s_n;
};

int N;
bool vis[MAX][MAX][MAX][MAX] = {};
int dist[MAX][MAX][MAX][MAX] = {};
vector<Node> moves;

// if all states are currently valid
bool valid(Node k) {
    if(k.f_n.f >= 1 && k.f_n.f <= N
    && k.f_n.s >= 1 && k.f_n.s <= N
    && k.s_n.f >= 1 && k.s_n.f <= N
    && k.s_n.f >= 1 && k.s_n.s <= N) {
        return k.f_n != k.s_n;
    }
    return 0;
}

bool adj(Node n) { return abs(n.f_n.f - n.s_n.f) + abs(n.f_n.s - n.s_n.s) <= 1; }

void bfs(pii f1, pii f2) { // find shortest path
    queue<Node> q;
    vis[f1.f][f1.s][f2.f][f2.s] = true;
    q.push({{f1}, {f2}});
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        for(auto m : moves){
            pii p1, p2;
            p1 = cur.f_n;
            p2.f = cur.s_n.f + m.s_n.f;
            p2.s = cur.s_n.s + m.s_n.s;
            Node n = {p1, p2};
            if(valid(n) && !vis[n.f_n.f][n.f_n.s][n.s_n.f][n.s_n.s]) {
                vis[n.f_n.f][n.f_n.s][n.s_n.f][n.s_n.s] = true;
                dist[n.f_n.f][n.f_n.s][n.s_n.f][n.s_n.s] =
                dist[cur.f_n.f][cur.f_n.s][cur.s_n.f][cur.s_n.s] + 1;
                q.push(n);
            }
        }
        Node n = cur;
        swap(n.f_n, n.s_n);
        if(adj(n) && !vis[n.f_n.f][n.f_n.s][n.s_n.f][n.s_n.s]) {
            vis[n.f_n.f][n.f_n.s][n.s_n.f][n.s_n.s] = true;
            dist[n.f_n.f][n.f_n.s][n.s_n.f][n.s_n.s] =
            dist[cur.f_n.f][cur.f_n.s][cur.s_n.f][cur.s_n.s] + 1;
            q.push(n);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int count = (bool)i + (bool)j;
            if(count == 1) { moves.pb({{0, 0}, {i, j}}); }
        }
    }
    // r_s: starting x
    // c_s: starting y
    // r_e: ending x
    // c_e: ending y
    int r_s, c_s, r_e, c_e; cin >> r_s >> c_s >> r_e >> c_e;
    pii st = {r_s, c_s}, ed = {r_e, c_e};
    pii f1, f2;
    cin >> f1.f >> f1.s >> f2.f >> f2.s;
    if(f2 == st){ swap(f1, f2); }
    bfs(f1, f2);
    int ans = INF;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(vis[r_e][c_e][i][j]){
                ans = min(ans, dist[r_e][c_e][i][j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}