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
const int MAX = 1e6 + 9;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int p[5][MAX], n;
string s;
char oo[MAX];

int f(char c){
    return c - 'A';
}

void init(){
    p[f(s[0])][0]++;
    for(int i=1;i<n;i++) {
        for(int j=0;j<3;j++) {
            p[j][i] = p[j][i-1];
        }
        p[f(s[i])][i]++;
    }
}

int sum(int l,int r,int c){
    if(l <= r){
        int ret = p[c][r];
        if(l != 0) {
            ret -= p[c][l-1];
        }
        return ret;
    }
    int ret = p[c][n-1];
    if(l != 0) {
        ret -= p[c][l-1];
    }
    ret += p[c][r];
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> oo;
    s = oo;
    n = s.size();
    init();

    int a = p[0][n-1];
    int b = p[1][n-1];
    int c = p[2][n-1];

    if(a == n || b == n || c == n){
        puts("0");
        return 0;
    }
    int ans = n;
    for(int i=0,j=a-1;i<n;i++,j++){
        j %= n;
        int a1 = sum(i, j, 0);
        int b1 = sum(i, j, 1);
        int c1 = sum(i, j, 2);

        int l = (j+1) % n;
        int r = (j+1 + b - 1 + n) % n;

        int a2 = sum(l, r, 0);
        int b2 = sum(l, r, 1);
        int c2 = sum(l, r, 2);

        int a3 = a - a1 - a2;
        int b3 = b - b1 - b2;
        int c3 = c - c1 - c2;

        int swaps = 0;
        int x = min(b1, a2);

        b1 -= x;
        a2 -= x;
        a1 += x;
        b2 += x;
        swaps += x;

        if(b1){
            swaps += b1;
            b2 += b1;
            c2 -= b1;
            c1 += b1;
            b1 = 0;
            swaps += c1 + c2;
        }
        else {
            a1 += a2;
            c1 -= a2;
            c2 += a2;
            swaps += a2;
            a2 = 0;
            swaps += c1 + c2;
        }
        ans = min(ans, swaps);
    }

    for(int i=0,j=a-1;i<n;i++,j++){
        j %= n;
        int a1 = sum(i, j, 0);
        int b1 = sum(i, j, 1);
        int c1 = sum(i, j, 2);

        int l = (j+1) % n;
        int r = (j+1 + c - 1 + n) % n;

        int a2 = sum(l, r, 0);
        int b2 = sum(l, r, 1);
        int c2 = sum(l, r, 2);

        int a3 = a - a1 - a2;
        int b3 = b - b1 - b2;
        int c3 = c - c1 - c2;

        int swaps = 0;
        int x = min(c1, a2);

        c1 -= x;
        a2 -= x;
        a1 += x;
        c2 += x;
        swaps += x;
        if(c1){
            swaps += c1;

            c2 += c1;
            b2 -= c1;

            b1 += c1;
            c1 = 0;

            swaps += b1 + b2;
        }
        else {
            a1 += a2;
            b1 -= a2;

            b2 += a2;
            swaps += a2;
            a2 = 0;
            swaps += b1 + b2;
        }
        ans = min(ans, swaps);
    }
    cout << ans << "\n";
}
