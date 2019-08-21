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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> v = {"*"};
    int x = 0, y = 0;
    int startX = 0, startY = 0;
    string str;
    while(cin >> str) {
        if(str == "down") {
            y++;
            if(y >= v.size()) {
                string temp(v[0].size(), ' ');
                v.pb(temp);
            }
        }
        if(str == "up") {
            y--;
            if(y < 0) {
                startY++;
                y++;
                string temp(v[0].size(), ' ');
                v.insert(v.begin(), temp);
            }
        }
        if(str == "left") {
            x--;
            if(x < 0) {
                startX++;
                x++;
                for(auto& i : v) {
                    i.insert(i.begin(), ' ');
                }
            }
        }
        if(str == "right") {
            x++;
            if(x >= v[0].size()) {
                for(auto& i : v) {
                    i.pb(' ');
                }
            }
        }
        v[y][x] = '*';
    }
    v[y][x] = 'E';
    v[startY][startX] = 'S';

    for(auto& i : v) {
        i.insert(i.begin(), '#');
        i.push_back('#');
    }
    string temp(v[0].size(), '#');
    v.insert(v.begin(), temp);
    v.push_back(temp);

    for(auto st : v) {
        cout << st << endl;
    }
    return 0;
}

/*
down
down
left
left
up
up
up
left
left
 */
