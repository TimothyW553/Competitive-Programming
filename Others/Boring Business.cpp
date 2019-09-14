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

bool g[200][401];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    g[0][200] = 1, g[1][200] = 1, g[2][200] = 1;
    g[2][201] = 1, g[2][202] = 1, g[2][203] = 1;
    g[3][203] = 1, g[4][203] = 1;
    g[4][204] = 1, g[4][205] = 1;
    g[3][205] = 1, g[2][205] = 1;
    g[2][206] = 1, g[2][207] = 1;
    g[3][207] = 1, g[4][207] = 1, g[5][207] = 1, g[6][207] = 1;
    g[6][206] = 1, g[6][205] = 1, g[6][204] = 1, g[6][203] = 1, g[6][202] = 1, g[6][201] = 1, g[6][200] = 1, g[6][199] = 1;
    g[5][199] = 1, g[4][199] = 1;
	int r = 4, c = 199;
	bool flag = false;
	while(1) {
        string dir; cin >> dir;
        int d; cin >> d;
        if(dir == "q") { break; }
        if(dir == "d") {
            for(int i = 0; i < d; i++) {
                if(!g[++r][c]) { g[r][c] = 1; }
                else { flag = true; }
            }
        } else if(dir == "u") {
            for(int i = 0; i < d; i++) {
                if(!g[--r][c]) { g[r][c] = true; }
                else { flag = true; }
            }
        } else if(dir == "l") {
            for(int i = 0; i < d; i++) {
                if(!g[r][--c]) { g[r][c] = true; }
                else { flag = true; }
            }
        } else if(dir == "r") {
            for(int i = 0; i < d; i++) {
                if(!g[r][++c]) { g[r][c] = true; }
                else { flag = true; }
            }
        }
        cout << c-200 << " " << (-r-1) << " ";
        if(!flag) { cout << "safe" << "\n"; }
        else { cout << "DANGER" << "\n"; break; }
	}
    return 0;
}
