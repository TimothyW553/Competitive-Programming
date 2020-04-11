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

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val) : prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp;
   int cp;
   Node* tail;
   Node* head;
   virtual void set(int, int) = 0;
   virtual int get(int) = 0;

};

class LRUCache {
public:
    deque<pii> v;
    int cp;
    LRUCache(const int &x) {
        cp = x;
    }
    int get(int x) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i].f == x) {
                return v[i].s;
            }
        }
        return -1;
    }
    void set(int x, int y) {
        int i = 0;
        for(; i < v.size(); i++) {
            if(v[i].f == x) {
                v.erase(v.begin() + i);
                break;
            }
        }
        if(i == cp) {
            v.pop_back();   
        }
        v.push_front({x, y});
    }
};

int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int n, capacity, i; cin >> n >> capacity;
    LRUCache l(capacity);
    for(i = 0; i < n; i++) {
        string command; cin >> command;
        if(command == "get") {
            int key; cin >> key;
            cout << l.get(key) << "\n";
        }
        else if(command == "set") {
            int key, value; cin >> key >> value;
            l.set(key,value);
        }
    }
    return 0;
}
