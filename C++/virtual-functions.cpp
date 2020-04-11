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

int professor_id = 0;
int student_id = 0;

class Person {
public:
    string name;
    int age, score, id;
    virtual void putdata() = 0;
    virtual void getdata() = 0;
};

class Professor : public Person {
    void putdata() {
        cout << name << " " << age << " " << score << " " << ++professor_id << "\n";
    }
    void getdata() {
        cin >> name >> age >> score;
    }
};

class Student : public Person {
    void putdata() {
        cout << name << " " << age << " " << score << " " << ++student_id << "\n";
    }
    void getdata() {
        cin >> name >> age;
        score = 0;
        for(int i = 0; i < 6; i++) {
            int x; cin >> x;
            score += x;
        }
    }
};

int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    Person* per[n];
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        if(val == 1) {
            per[i] = new Professor;
        } else {
            per[i] = new Student;
        }
        per[i]->getdata();
    }
    for(int i = 0; i < n; i++) {
        per[i]->putdata();
    }
    return 0;
}
