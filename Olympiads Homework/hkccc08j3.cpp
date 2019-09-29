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

vector<pair<pair<string, int>, int>> phoneBook;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string name; int number;
        cin >> name >> number;
        phoneBook.pb({{name, number}, 0});
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int number; cin >> number;
        for(int i = 0; i < phoneBook.size(); i++) {
            if(phoneBook[i].f.s == number) {
                phoneBook[i].s++;
            }
        }
    }
    int max = -1;
    string maxName = "";
    int maxNumb = 0;
    for(int i = 0; i < phoneBook.size(); i++) {
        if(phoneBook[i].s > max) {
            max = phoneBook[i].s;
            maxName = phoneBook[i].f.f;
            maxNumb = phoneBook[i].f.s;
        } else if(phoneBook[i].s == max) {
            (phoneBook[i].f.s < maxNumb) {
                maxName = phoneBook[i].f.f;
                maxNumb = phoneBook[i].f.s;
            }
        }
    }
    cout << maxName << "\n";
    return 0;
}
