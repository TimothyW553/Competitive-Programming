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

int arr[]  = { 2,   2,   2,   3,   3,   3,   4,   4,   4,   5,   5,   5,   6,   6,   6,   7,   7,   7,   7,   8,   8,   8,   9,   9,   9,   9 };
char let[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    while(n--) {
    	string temp; cin >> temp;
    	string str = "";
    	for(int i = 0; i < temp.length(); i++) {
    		if(temp[i] != '-') { str += temp[i]; }
    	}
    	string final = "";
    	for(int i = 0; i < 3; i++) {
    		if(str[i] >= 'A' && str[i] <= 'Z') {
    			for(int j = 0; j < 26; j++) {
    				if(str[i] == let[j]) { final += to_string(arr[j]); }
    			}
    		} else { final += str[i]; }
    	} final += '-';
    	for(int i = 3; i < 6; i++) {
    		if(str[i] >= 'A' && str[i] <= 'Z') {
    			for(int j = 0; j < 26; j++) {
    				if(str[i] == let[j]) { final += to_string(arr[j]); }
    			}
    		} else { final += str[i]; }
    	} final += '-';
    	for(int i = 6; i < 10; i++) {
    		if(str[i] >= 'A' && str[i] <= 'Z') {
    			for(int j = 0; j < 26; j++) {
    				if(str[i] == let[j]) { final += to_string(arr[j]); }
    			}
    		} else { final += str[i]; }
    	}
    	cout << final << "\n";
    }
    return 0;
}