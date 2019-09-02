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

int arr1[101];
int arr2[101];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    int n; cin >> n;
    for(int i = 0; i < n; i++) { cin >> arr1[i]; }
    for(int i = 0; i < n; i++) { cin >> arr2[i]; }
    sort(arr1, arr1+n);
    sort(arr2, arr2+n);
    int total = 0;
    if(q == 1) {
        for(int i = 0; i < n; i++) {
            total += max(arr1[i], arr2[i]);
        }
        cout << total << "\n";
        return 0;
    } else if(q == 2) {
        reverse(arr2, arr2+n);
        for(int i = 0; i < n; i++) {
            total += max(arr1[i], arr2[i]);
        }
        cout << total << "\n";
    }
    return 0;
}
