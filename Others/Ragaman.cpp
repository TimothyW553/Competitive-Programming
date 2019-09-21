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
    string s1, s2; cin >> s1 >> s2;
    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if(t1 == t2) { cout << "A" << "\n"; return 0; }
    for(int i = 0; i < s1.length(); i++) {
        size_t idx = s2.find(s1[i]);
        if(idx != string::npos) {
            s2.erase(s2.begin()+idx);
            s1.erase(0,1);
            i = 0;
        }
//        cout << i << ": " << s1 << " " << s2 << "\n";
    }
    int numstars = 0;
    for(int i = 0; i < s2.length(); i++) {
        if(s2[i] == '*') { numstars++; }
    }
//    cout << s1 << " " << s2 << " " << numstars << "\n";
    if(s1.length() == s2.length() && numstars == s1.length()) { cout << "A" << "\n"; }
    else { cout << "N" << "\n"; }
    return 0;
}
// 13/15 what???
