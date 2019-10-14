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

double median(vi v) {
    int mid = v.size() / 2;
    bool flag = false;
    if((v.size() & 1) == 1) { flag = true; }
    if(flag) { return v[mid]; }
    else { return (v[mid] + v[mid-1]) / 2.0; }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vi v;
    for(int i = 0; i < n; i++) { int t; cin >> t; v.pb(t); }
    sort(v.begin(), v.end());
    double med = median(v);
    vi low; vi upp;
    if(n % 2 == 1) {
        for(int i = 0; i < n/2; i++) {
            low.pb(v[i]);
        }
        for(int j = n/2+1; j < n; j++) {
            upp.pb(v[j]);
        }
    } else {
        for(int i = 0; i < n/2; i++) {
            low.pb(v[i]);
        }
        for(int j = n/2; j < n; j++) {
            upp.pb(v[j]);
        }
    }
    double q1 = median(low), q3 = median(upp);
    cout << (v[0] == (int)v[0] ? (int)v[0] : v[0]) << " ";
    cout << (v[n-1] == (int)v[n-1] ? (int)v[n-1] : v[n-1]) << " ";
    cout << (q1 == (int)q1 ? (int)q1 : q1) << " ";
    cout << (med == (int)med ? (int)med : med) << " ";
    cout << (q3 == (int)q3 ? (int)q3 : q3) << "\n";
    return 0;
}