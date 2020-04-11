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
ll mul(ll a,ll b, ll M){if(b==0)return 0;ll t=mul(a,b/2,M);if(b&1)return (t+t+a)%M;return (t+t)%M;}
ll fpow(ll a, ll b, ll M){if(b==0)return 1;ll t=fpow(a,b/2,M);if(b&1)return mul(mul(t,t,M),a,M)%M;return mul(t,t,M)%M;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

class Box {
    private:
        int length, breadth, height;
    public:
        Box() {
            length = 0;
            breadth = 0;
            height = 0;
        }
        Box(int l, int b, int h) {
            length = l;
            breadth = b;
            height = h;
        }
        Box(const Box &B) {
            length = B.length;
            breadth = B.breadth;
            height = B.height;
        }
        int getLength() {
            return length;
        }
        int getBreadth() {
            return breadth;
        }
        int getHeight() {
            return height;
        }
        ll CalculateVolume() {
            return (ll)(breadth) * length * height;
        }
        bool operator<(Box &B) {
            if (length < B.length) {
                return true;
            } else if (length == B.length) {
                if (breadth < B.breadth) {
                    return true;
                } else if (breadth == B.breadth) {
                    if (height < B.height) {
                        return true;
                    }
                }
            }
            return false;
        }
};
ostream &operator<<(ostream &out, Box &B) {
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
};

void check2() {
    int n; cin >> n;
    Box temp;
    for(int i = 0; i < n; i++) {
        int type; cin >> type;
        if(type == 1) {
            cout << temp << "\n";
        }
        if(type == 2) {
            int l, b, h; cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if(type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if(NewBox < temp) {
                cout<<"Lesser" << "\n";
            } else {
                cout << "Greater" << "\n";
            }
        }
        if(type == 4) {
            cout << temp.CalculateVolume() << "\n";
        }
        if(type == 5) {
            Box NewBox(temp);
            cout << NewBox << "\n";
        }
    }
}

int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    check2();
    return 0;
}
