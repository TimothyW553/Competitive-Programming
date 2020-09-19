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
const int MAX = 3e3 + 5;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll mul(ll a,ll b, ll M){if(b==0)return 0;ll t=mul(a,b/2,M);if(b&1)return (t+t+a)%M;return (t+t)%M;}
ll fpow(ll a, ll b, ll M){if(b==0)return 1;ll t=fpow(a,b/2,M);if(b&1)return mul(mul(t,t,M),a,M)%M;return mul(t,t,M)%M;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int bit[MAX][MAX], base[MAX][MAX];

void qE(int n, int i, int j, int e) {
    for(int a = n-j; a <= n; a += a&-a) {
        for(int b = n+j-i; b <= n; b += b&-b) {
            bit[a][b] = max(e, bit[a][b]);
        }
    }
}

int qS(int n, int i, int j, int k) {
    int sub = 0;
    for(int a = n-j; a > 0; a -= a&-a) {
        for(int b = n-i+k-1+j; b > 0; b -= b&-b) {
            sub = max(sub, bit[a][b]);
        }
    }
    return sub;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cin >> base[i][n-i+j+1];
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int e = base[n-j][n+j-i];
            qE(n, i, j, e);
        }
        for(int j = 0; j < i-k+2; j++) {
            res += qS(n, i, j, k);
        }
    }
    cout << res << "\n";
    return 0;
}
