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

char floorplan[26][26];
int counter;
int floorboards, r, c, i;
vector<int> rooms;

bool maxi(int a, int b){
    return a>b;
}

void floorfill(int x, int y) {
    counter++;
    floorplan[x][y] = 'I';
    if(x > 1 && floorplan[x-1][y] == '.') { floorfill(x-1, y); }
    if(x < r && floorplan[x+1][y] == '.') { floorfill(x+1, y); }
    if(y > 1 && floorplan[x][y-1] == '.') { floorfill(x, y-1); }
    if(y < c && floorplan[x][y+1] == '.') { floorfill(x, y+1); } 
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> floorboards >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> floorplan[i][j];
        }
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(floorplan[i][j] == '.') {
                counter = 0;
                floorfill(i, j);
                rooms.pb(counter);
            }
        }
    }
    sort(rooms.begin(), rooms.end(), maxi);
    for(i = 0; i < rooms.size(); i++) {
        if(rooms[i] <= floorboards) { floorboards -= rooms[i]; }
        else { break; } 
    }
    cout << i << (i > 1 || i < 1 ? " rooms" : " room") << ", ";
    cout << floorboards << " square metre(s) left over" << "\n";
    return 0;
}
