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

ll arr[100005];
ll idx;
ll bit[100010];
double ans; 
vector<int> v;
unordered_map<int,int> mp;
void update(int idx) {
    for(; idx <= MAX; idx+=idx&-idx) {
        bit[idx]++;
    }
}
int query(int idx) {
    int sum = 0;
    for(; idx > 0; idx -= idx&-idx) {
        sum += bit[idx];
    }
    return sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v.pb(arr[i]);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i : v) {
        mp[i] = ++idx;
    }

    for(int i = 0; i < n; i++) {
        ans += (double)(i + 1 - query(mp[arr[i]])) / n;
        update(mp[arr[i]]);
    }

    cout << setprecision(2) << fixed << ("%.2f\n", ans*100.0)/100.0 << "\n";
    return 0;
}