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

string f_0 = "Good writing is good writing is good writing.";
string str_1 = "Good writing is good ";
string str_2 = " writing is good ";
string str_3 = " is good writing.";
int len_1 = str_1.length();
int len_2 = str_2.length();
int len_3 = str_3.length();
ll arr[35];
char f(ll n, ll k) {
    if(n == 0){ return f_0[k-1]; }
    if(k <= 21){ return str_1[k-1]; }
    else if(k <= arr[n-1]+21){ return f(n-1, k-21); }
    else if(k <=arr[n-1]+21+17){ return str_2[k-arr[n-1]-21-1]; }
    else if(k <= arr[n-1]+21+17+arr[n-1]){ return f(n-1, k-arr[n-1]-21-17); }
    else { return str_3[k-arr[n-1]-arr[n-1]-21-17-1]; }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int qq; cin >> qq;
    arr[0] = f_0.size();
    for(int i = 1; i<=30; i++){ arr[i] = 2 * arr[i-1] + len_1 + len_2 + len_3; }
    while(qq--){
        int n, k; cin >> n >> k;
        if(k > arr[n]) { cout << "." << "\n"; }
        else { cout << f(n, k) << "\n"; }
    }
    return 0;
}
