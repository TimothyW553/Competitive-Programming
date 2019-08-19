#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
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

int stops[1001];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> stops[i];
    }
    sort(stops, stops + n);
    int i = 0;
    while(i < n) {
        int start = stops[i]; // start with a number
        while(i+1 < n && stops[i] == stops[i+1]-1) { // finds the maximum number in a consequtive sequence
            i++; // stores index of max num in sequence
        }
        int end = stops[i]; // max num in current consequtive seq.
        if(start == end) { // if consequtive seq. is only 1 num
            cout << start << " ";
        } else if(start == end - 1) { // if consequtive seq. is only 2 nums
            cout << start << " " << end << " ";
        } else { // if there is a consequtive sequence > 2
            cout << start << "-" << end << " ";
        }
        if(i == n - 1) { // newline char for end of output
            cout << "\n";
        }
        i++; // iterate to next starting point
    }
    return 0;
}
