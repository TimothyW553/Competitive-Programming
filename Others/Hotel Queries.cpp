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
const int MAX = 1e6 + 5;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int n, a[MAX], m, b[MAX];
int tree[2*MAX];

void build(int l, int r, int x){
    if( l == r ){
        tree[x] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build( l, mid, x*2 );
    build( mid+1, r, x*2+1 );
    tree[x] = max( tree[x*2], tree[x*2+1] );
}

void update( int l, int r, int val, int x ){
    if(l == r) {
        cout << l+1 << " ";
        tree[x] -= val;
        return;
    }
    int mid = (l + r)/2;
    if(tree[x*2] >= val){
        update( l, mid, val, x*2 );
    } else {
        update( mid+1, r, val, x*2+1 );
    }
    tree[x] = max( tree[x*2], tree[x*2+1] );
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(0, n-1, 1);
    for(int i = 0; i < m; i++){
        cin >> b[i];
        if( tree[1] >= b[i] ){
            update(0, n-1, b[i], 1);
        } else{
            cout << "0 ";
        }
    }
    return 0;
}
