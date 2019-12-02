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
const int MAX = 150010;
const int MAXN = 1e5 + 1;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int arr[MAX] = {};
int psa[MAX] = {};
int ssa[MAX] = {};
int bit[(int)(3e5 + 10)] = {};
void add(int idx, int v) {
    for (idx += MAXN; idx < 3e5+10; idx+=idx&-idx) {
        bit[idx] += v;
    }
}
int sum(int idx) {
    int sum = 0;
    for (idx += MAXN; idx; idx-=idx&-idx) {
        sum += bit[idx];
    }
    return sum;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll ans = 0;
    for(int i = 1; i < n+1; i++) {
        cin >> arr[i]; arr[i]--;
    }
    for(int i = 1; i < n+1; i++) {
        if(arr[i]) {
            psa[i] = psa[i-1]-1;
        } else {
            psa[i] = psa[i-1]+1;
        }
    }
    for(int i = n; i > -1; i--) {
        if(arr[i]) {
            ssa[i] = ssa[i+1]-1;
        } else {
            ssa[i] = ssa[i+1]+1;
        }
    }
    for(int i = 1; i < n+2; i++) {
        add(ssa[i], 1);
    }
    for(int i = 0; i < n; i++) {
        add(ssa[i+1], -1);
        ll temp = sum(psa[n]-psa[i]-1);
        ans += temp;
    }
    cout << ans << "\n";
    return 0;
}
