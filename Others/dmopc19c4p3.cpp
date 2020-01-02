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
const int MAX = 1e4 + 5;
const int MAX_DP = 100;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int dp[MAX*2][MAX_DP+5] = {};
int x[MAX] = {};
int y[MAX] = {};
int b[MAX] = {};
int s[MAX] = {};

void init() {
    for(int i = 1; i <= MAX_DP; i++) {
        dp[0][i] = INT_MIN / 2;
    }
}

void DP(int n, int m) {
    for(int i = 2; i <= n*2; i += 2) {
        int pos = i / 2;
        deque<pii> q;
        for(int j = MAX_DP; j >= 0; j--) {
            int idx = dp[i-2][j] - m*j + j*s[pos];
            while(!q.empty() && q.back().f <= idx) { q.pop_back(); }
            q.pb(make_pair(idx, j));
            while(!q.empty() && q.front().s > j + y[pos]) { q.pop_front(); }
            dp[i-1][j] = q.front().f - j * s[pos];
        }
        q.clear();
        for(int j = 0; j <= MAX_DP; j++) {
            int idx = dp[i-1][j] + j*b[pos];
            while(!q.empty() && q.back().f <= idx) { q.pop_back(); }
            q.pb(make_pair(idx, j));
            while(!q.empty() && q.front().s < j - x[pos]) { q.pop_front(); }
            dp[i][j] = q.front().f - j * b[pos];
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
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> b[i] >> s[i];
    }
    init();
    DP(n, m);
    cout << dp[n*2][0] << "\n";
    return 0;
}