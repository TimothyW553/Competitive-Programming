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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int qq = 5;
    while(qq--) {
    	int dd, mm, yy; cin >> dd >> mm >> yy;
    	string ans = "";
    	if(yy < 1997) { ans = "old enough"; }
    	else if(yy > 1997) { ans = "too young"; }
    	else if(yy == 1997) {
    		if(mm == 10 && dd >= 28) { ans = "too young"; }
    		else if(mm == 10 && dd < 28) { ans = "old enough"; }
    		else if(mm > 10) { ans = "too young"; }
    		else { ans = "old enough"; }
    	}
    	cout << ans << "\n";
    }
    return 0;
}