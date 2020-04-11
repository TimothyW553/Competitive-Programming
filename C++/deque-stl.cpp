#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define all(x) (x).begin(), (x).end()

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

// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
void printKMax(int a[], int n, int k) {
    deque<int> q(k);
    // first k elements
    for(int i = 0; i < k; i++) {
        while((!q.empty()) && a[i] >= a[q.back()]) {
            q.pop_back();
        }
        q.pb(i);
    }
    // process the rest of elements a[k] to a[n-1]
    for(int i = k; i < n; i++) {
        // the front of the deque is going to the be the largest element of the previous window
        cout << a[q.front()] << " ";
        // remove the elements that are not in this window
        while((!q.empty()) && q.front() <= i - k) {
            q.pop_front();
        }
        // remove useless elements (elements smaller than the one currently being added)
        while((!q.empty()) && a[i] >= a[q.back()]) {
            q.pop_back();
        }
        // add the current element
        q.pb(i); 
    }
    // print the last window
    cout << a[q.front()] << "\n";
}

int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        printKMax(a, n, k);
    }
    return 0;
}
