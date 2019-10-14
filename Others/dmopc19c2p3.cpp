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
const int MAX = 300001;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int arr[MAX];
int tree[25][MAX];
void update(int num, int val, int idx, int n) {
    for(int i = num; i < n+1; i +=i & -i) { tree[idx][i] += val; }
}

int query(int num, int idx){
    int ans = 0;
    for(int i = num; i; i -=i & -i){ ans += tree[idx][i]; }
    return ans;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m; cin >> n >> m;
    for(int i = 1; i < n+1; i++){
        cin >> arr[i];
        arr[i] = 20-arr[i];
        for(int j = arr[i]; j < 21; j++){
            update(i, 1, j, n);
        }
    }
    for(int t = 0; t < m; t++) {
        int cmd; cin >> cmd;
        if(cmd == 1){
            int a, b; cin >> a >> b;
            for(int i = arr[a]; i < 21; i++) {
                update(a, -1, i, n);
            } arr[a] = 20-b;
            for(int i = arr[a]; i < 21; i++) {
                update(a, 1, i, n);
            }
        }
        else if(cmd == 2) {
            int l, r, c; cin >> l >> r >> c;
            for(int i = 0; i < 21; i++) {
                if(query(r, i) - query(l-1, i) >= c){
                    cout << (20-i) << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}