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

string keyPad[12] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "", " ", ""};
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int tt = 0; tt < t; tt++) {
        string str; getline(cin, str);
        cout<<"";
        int count = 0;
        for(int i = 0; i < str.length(); i++) {
            int presses;
            for(int j = 0; j < 12 /*keyPad.size()*/; j++) {
                for(int k = 0; k < keyPad[j].size(); k++) {
                    if(str[i] == keyPad[j][k]) {
                        presses = k+1;
                    }
                }
            }
            count += presses;
        }
        cout << "Case #" << tt+1 << ": " << count << "\n";
    }
    return 0;
}
