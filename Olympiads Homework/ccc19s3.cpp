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

int a[3][3], miss[3][3], row[3], col[3], x; string s;
int ord[5][2] = {{1,1}, {0, 1}, {1, 0}, {1, 2}, {2, 1}};
void solveR(int i) {
    if(miss[i][0]) { 
        a[i][0] = 2*a[i][1] - a[i][2]; 
        miss[i][0] = 0; 
        col[0]--; 
    }
    if(miss[i][1]) { 
        a[i][1] = (a[i][0] + a[i][2])/2; 
        miss[i][1] = 0; 
        col[1]--; 
    }
    if(miss[i][2]) { 
        a[i][2] = 2*a[i][1] - a[i][0]; 
        miss[i][2] = 0; 
        col[2]--; 
    }
    row[i]--; 
    x--;
}
void solveC(int j) {
    if(miss[0][j]) { 
        a[0][j] = 2*a[1][j] - a[2][j]; 
        miss[0][j] = 0; 
        row[0]--; 
    }
    if(miss[1][j]) { 
        a[1][j] = (a[0][j] + a[2][j])/2; 
        miss[1][j] = 0; 
        row[1]--; 
    }
    if(miss[2][j]) {  
        a[2][j] = 2*a[1][j] - a[0][j]; 
        miss[2][j] = 0; 
        row[2]--; 
    }
    col[j]--; 
    x--;
}
void fillCell(int i, int j) {
    a[i][j] = 0; 
    miss[i][j] = 0; 
    row[i]--; 
    col[j]--; 
    x--;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> s;
            if(s == "X") { 
                miss[i][j] = 1; 
                row[i]++; 
                col[j]++; 
                x++; 
            }
            else { 
                a[i][j] = stoi(s);
            }
        }
    }
    while(x > 0 && x < 9){
        for(int i = 0; i < 3; i++) {
            if(row[i] == 1) { 
                solveR(i); 
                goto next; 
            }
        }
        for(int j = 0; j < 3; j++) {
            if(col[j] == 1) { 
                solveC(j); 
                goto next; 
            }
        }
        for(int i = 0; i < 5; i++) {
            if(miss[ord[i][0]][ord[i][1]]) { 
                fillCell(ord[i][0], ord[i][1]); 
                goto next;
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(miss[i][j]) {
                    fillCell(i, j); 
                    goto next;
                }
            }
        }
        next: ;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}