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
const int MAX = 1e3 + 10;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int n, m;
int arr[MAX][MAX];
vector<pair<int, int>> v[1001000];
bool vis[MAX][MAX];

bool dfs(int x, int y) {
    if(x == n && y == m) {
        return true;
    }
    if(vis[x][y]) {
        return false;
    }
    vis[x][y] = true;
    bool ans = false;
    for(int i = 0; i < v[arr[x][y]].size(); i++) {
        ans = max(ans, dfs(v[arr[x][y]][i].f, v[arr[x][y]][i].s));
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
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> arr[i][j];
            if(i * j <= 1000000)
                v[i * j].pb({i, j});
        }
    }
    if(dfs(1, 1)){
        cout << "yes" << "\n";
    }
    else {
        cout << "no" << "\n";
    }
    return 0;
}
