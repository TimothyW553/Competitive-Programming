#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define all(x) (x).begin(), (x).end()

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
ll mul(ll a,ll b, ll M){if(b==0)return 0;ll t=mul(a,b/2,M);if(b&1)return (t+t+a)%M;return (t+t)%M;}
ll fpow(ll a, ll b, ll M){if(b==0)return 1;ll t=fpow(a,b/2,M);if(b&1)return mul(mul(t,t,M),a,M)%M;return mul(t,t,M)%M;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int a[30][30];
int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    FILL(a, 0);
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cin >> a[i][j];
        }
    }
    ll max_val = -INF;
    // first diag
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            ll prod = 1LL * a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3];
            max_val = max(max_val, prod);
        }
    }
    // row by row
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            ll prod = 1LL * a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3];
            max_val = max(max_val, prod);
        }
    }
    // column by column
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            ll prod = 1LL * a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j];
            max_val = max(max_val, prod);
        }
    }
    // secon diag
    for(int i = 0; i < 20; i++) {
        for(int j = 20; j >= 4; j--) {
            ll prod = 1LL * a[i][j] * a[i+1][j-1] * a[i+2][j-2] * a[i+3][j-3];
            max_val = max(max_val, prod);
        }
    }
    cout << max_val << "\n";
    return 0;
}
